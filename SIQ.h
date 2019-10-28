#include <iostream>
using namespace std;

#ifndef SIQ_h
#define SIQ_h

const int SIQ_SIZE = 4;

class Node {
public:
	Node();
	int data;
	Node *next;
};

Node::Node() {
	data = 0;
	next = NULL;
}

class SIQ {
public:
	SIQ();
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