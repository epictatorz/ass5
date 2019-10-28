#include "structs.h"
#ifndef SOQ_h
#define SOQ_h

const int SOQ_SIZE = 32;

class SOQ {
public:
	SOQ();
	int Length();
	bool IsFull();
	bool IsEmpty();
	void Enqueue(struct data);
	struct data Dequeue();
	void Clear();
private:
	struct data d[SOQ_SIZE];
	int front;
	int back;
	int length;
};

#endif