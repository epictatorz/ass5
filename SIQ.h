#include <iostream>
#include "structs.h"
using namespace std;

#ifndef SIQ_h
#define SIQ_h

const int SIQ_SIZE = 4;

//class Node {
//public:
//	info data;
//	Node *next;
//};

class SIQ {
public:
	SIQ();
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