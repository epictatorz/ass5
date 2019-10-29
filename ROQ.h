#include "structs.h"
#ifndef ROQ_h
#define ROQ_h

const int ROQ_SIZE = 16;

class ROQ {
public:
	ROQ();
	int Length();
	bool IsFull();
	bool IsEmpty();
	void Enqueue(info);
	info Dequeue();
	void Clear();
private:
	info d[ROQ_SIZE];
	int front;
	int back;
	int length;
};

#endif