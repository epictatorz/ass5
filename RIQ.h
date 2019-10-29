#include <iostream>
#include "structs.h"
using namespace std;

#ifndef RIQ_h
#define RIQ_h

const int RIQ_SIZE = 8;

//class Node {
//public:
//	info data;
//	Node *next;
//};

class RIQ {
public:
	RIQ();
	int Length();
	bool IsEmpty();
	bool IsFull();
	void Enqueue(info);
	info Dequeue();
private:
	Node *front;
	Node *back;
	int length;
};
#endif