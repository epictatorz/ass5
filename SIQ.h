#include <iostream>
using namespace std;

#ifndef SIQ_h
#define SIQ_h

const int SIQ_SIZE = 4;

class Node {
public:
	struct data data;
	Node *next;
};

class SIQ {
public:
	SIQ();
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