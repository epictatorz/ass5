#include <iostream>
using namespace std;

#ifndef RIQ_h
#define RIQ_h

const int RIQ_SIZE = 8;

class Node {
public:
	int data;
	Node *next;
};

class RIQ {
public:
	RIQ();
	int Length();
	bool IsEmpty();
	bool IsFull();
	void Enqueue(int);
	int Dequeue();
	void Clear();
private:
	Node *front;
	Node *back;
	int length;
};
#endif