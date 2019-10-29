#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include "SOQ.h"
#include "SIQ.h"
#include "RIQ.h"
#include "ROQ.h"
#include "structs.h"
using namespace std;

int globalClock;
void AsynchronousSim(string, string);
int GenerateTimeToNextEvent();
info PrepareNextDataMessage(info);

int main() {
	srand(time(0));
	AsynchronousSim("wordCount.gauss", "outputFile.txt");

	return 0;
}

void AsynchronousSim(string Input, string Output) {
	int STtS, STtR, RTtS, RTtR;
	string SSS, SRS, RSS, RRS;
	info RDataMsg, SDataMsg;
	info SAckMsg, RAckMsg;
	globalClock = 0;
	SOQ SOQueue;
	SIQ SIQueue;
	ROQ ROQueue;
	RIQ RIQueue;
	STtS = GenerateTimeToNextEvent();
	STtR = GenerateTimeToNextEvent();
	RTtS = GenerateTimeToNextEvent();
	RTtR = GenerateTimeToNextEvent();
	SSS = "NO_SEND";
	SRS = "NO_RECEIVE";
	RSS = "NO_SEND";
	RRS = "NO_RECEIVE";

	ifstream in;
	ofstream out;
	in.open(Input);
	out.open(Output);
	
	while (1) {
		if (in.eof() && SOQueue.IsEmpty() && SIQueue.IsEmpty() && ROQueue.IsEmpty() && RIQueue.IsEmpty()) {
			break;
		}
		globalClock++;
		cout << "Global Clock : " << globalClock << endl;
		//cout << STtS << ' ' << STtR << ' ' << RTtS << ' ' << RTtR << endl;

		if (globalClock == STtS) {
			SSS = "SEND";
			STtS = globalClock + GenerateTimeToNextEvent();
		}
		if (globalClock == STtR) {
			SRS = "RECEIVE";
			STtR = globalClock + GenerateTimeToNextEvent();
		}
		if (globalClock == RTtS) {
			RSS = "SEND";
			RTtS = globalClock + GenerateTimeToNextEvent();
		}
		if (globalClock == RTtR) {
			RRS = "RECEIVE";
			RTtR = globalClock + GenerateTimeToNextEvent();
		}

		if (RRS == "RECEIVE") {
			if (!RIQueue.IsEmpty()) {
				RDataMsg = RIQueue.Dequeue();
				cout << "Receiver: Received [" << RDataMsg.num << ',' << RDataMsg.data << ']' << endl;
				out << RDataMsg.data;
			}
			else {
				RRS = "NO_RECEIVE";
			}
		}
		if (SRS == "RECEIVE") {
			if (!SIQueue.IsFull()) {
				SAckMsg = SIQueue.Dequeue();
			}
			SRS = "NO_RECEIVE";
		}
		if (SSS == "SEND") {
			while (!SOQueue.IsFull()) {
				if (in) {
					SDataMsg.data = in.get();
					if (in) {
						SDataMsg = PrepareNextDataMessage(SDataMsg);
						SOQueue.Enqueue(SDataMsg);
					}
				}
			}
			if (!SOQueue.IsEmpty() && !RIQueue.IsFull()) {
				SDataMsg = SOQueue.Dequeue();
				RIQueue.Enqueue(SDataMsg);
					cout << "Sender: Sent [" << SDataMsg.num << ',' << SDataMsg.data << ']' << endl;
			}
			SSS = "NO_SEND";
		}
		if (RSS == "SEND") {
			while (!ROQueue.IsEmpty() && !SIQueue.IsFull()) {
				RAckMsg = ROQueue.Dequeue();
				SIQueue.Enqueue(RAckMsg);
				cout << "Sender: Received [" << RAckMsg.num << ',' << RAckMsg.data << ']' << endl;
			}
			RSS = "NO_SEND";
		}
		if (RRS == "RECEIVE") {
			RAckMsg = PrepareNextDataMessage(RDataMsg);
			ROQueue.Enqueue(RAckMsg);
			cout << "Receiver: Sent [" << RAckMsg.num << ',' << RAckMsg.data << ']' << endl;
			RRS = "NO_RECEIVE";
		}
	}
	return;
}

int GenerateTimeToNextEvent() {
//	return (1 + rand() % 100);
	return 1;
}

info PrepareNextDataMessage(info msg) {
	info temp;
	temp.data = msg.data;
	temp.num = msg.num + 1;
	return temp;
}