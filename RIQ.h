#include <iostream>
using namespace std;

#ifndef RIQ_h
#define RIQ_h

const int RIQ_SIZE = 8;

class Node {
public:
	struct data data;
	Node *next;
};

class RIQ {
public:
	RIQ();
	int Length();
	bool IsEmpty();
	bool IsFull();
	void Enqueue(struct data);
	struct data Dequeue();
private:
	Node *front;
	Node *back;
	int length;
};
#endif