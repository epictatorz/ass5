#include "ROQ.h"

ROQ::ROQ() {
	front = ROQ_SIZE - 1;
	back = front;
	length = 0;
	return;
}

int ROQ::Length() {
	return length;
}

bool ROQ::IsEmpty() {
	if (length == 0) {
		return true;
	}
	return false;
}

bool ROQ::IsFull() {
	if (length == ROQ_SIZE) {
		return true;
	}
	return false;
}

void ROQ::Enqueue(int x) {
	if (IsFull() != true) {
		back = (back + 1) % ROQ_SIZE;
		d[back].data = x;
		d[back].num = back;
		length++;
	}
	return;
}

int ROQ::Dequeue() {
	front = (front + 1) % ROQ_SIZE;
	int x = d[front].data;
	d[front].num = front;
	length--;
	return x;
}

void ROQ::Clear() {
	front = ROQ_SIZE - 1;
	back = front;
	length = 0;
}