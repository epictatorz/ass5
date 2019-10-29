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
	AsynchronousSim("wordCount.gauss", "outputFile.gauss");

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
		if (in.eof() && SOQueue.IsEmpty() && SIQueue.IsEmpty() && ROQueue.IsFull() && RIQueue.IsFull()) {
			break;
		}
		globalClock++;
		cout << " Global Clock : " << globalClock << endl;
		cout << STtS << ' ' << STtR << ' ' << RTtS << ' ' << RTtR << endl;

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
				cout << "RRS" << endl;
				RDataMsg = RIQueue.Dequeue();
				out << RDataMsg.data;
			}
			else {
				RRS = "NO_RECEIVE";
			}
		}
		if (SRS == "RECEIVE") {
			if (!SIQueue.IsFull()) {
				cout << "SRS" << endl;
				SAckMsg = SIQueue.Dequeue();
			}
			SRS = "NO_RECEIVE";
		}
		if (SSS == "SEND") {
			if (!SOQueue.IsFull()) {
				cout << "SSS" << endl;
				if (in) {
					SDataMsg.data = in.get();
					if (in) {
						cout << "SSS2" << endl;
						SDataMsg = PrepareNextDataMessage(SDataMsg);
						SOQueue.Enqueue(SDataMsg);
					}
				}
			}
			while (!SOQueue.IsEmpty() && !RIQueue.IsFull()) {
				SDataMsg = SOQueue.Dequeue();
				RIQueue.Enqueue(SDataMsg);
			}
			SSS = "NO_SEND";
		}
		if (RSS == "SEND") {
			while (!ROQueue.IsEmpty() && !SIQueue.IsFull()) {
				cout << "RSS" << endl;
				RAckMsg = ROQueue.Dequeue();
				SIQueue.Enqueue(RAckMsg);
			}
			RSS = "NO_SEND";
		}
		if (RRS == "RECEIVE") {
			cout << "RRS" << endl;
			RAckMsg = PrepareNextDataMessage(RDataMsg);
			ROQueue.Enqueue(RAckMsg);
			RRS = "NO_RECEIVE";
		}
	}
	return;
}

int GenerateTimeToNextEvent() {
	srand(time(0));
	return globalClock + (1 + rand() % 100);
}

info PrepareNextDataMessage(info msg) {
	info temp;
	temp = msg;
	temp.num++;
	return temp;
}