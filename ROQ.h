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
	void Enqueue(int);
	int Dequeue();
	void Clear();
private:
	data d[ROQ_SIZE];
	int front;
	int back;
	int length;
};

#endif