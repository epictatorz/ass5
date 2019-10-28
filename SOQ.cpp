#include "SOQ.h"

SOQ::SOQ() {
	front = SOQ_SIZE - 1;
	back = front;
	length = 0;
	return;
}

int SOQ::Length() {
	return length;
}

bool SOQ::IsEmpty() {
	if (length == 0) {
		return true;
	}
	return false;
}

bool SOQ::IsFull() {
	if (length == SOQ_SIZE) {
		return true;
	}
	return false;
}

void SOQ::Enqueue(data x) {
	if (IsFull() != true) {
		back = (back + 1) % SOQ_SIZE;
		d[back] = x;
		length++;
	}
	return;
}

data SOQ::Dequeue() {
	front = (front + 1) % SOQ_SIZE;
	data x = d[front];
	return x;
}

void SOQ::Clear() {
	front = SOQ_SIZE - 1;
	back = front;
	length = 0;
}