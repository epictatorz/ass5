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

void SOQ::Enqueue(int x) {
	if (IsFull() != true) {
		back = (back + 1) % SOQ_SIZE;
		d[back].data = x;
		d[back].num = back;
		length++;
	}
	return;
}

int SOQ::Dequeue() {
	front = (front + 1) % SOQ_SIZE;
	int x = d[front].data;
	d[front].num = front;
	length--;
	return x;
}

void SOQ::Clear() {
	front = SOQ_SIZE - 1;
	back = front;
	length = 0;
}