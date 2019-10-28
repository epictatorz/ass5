#include "SIQ.h"
#include "structs.h"

SIQ::SIQ() {
	front = NULL;
	back = front;
	length = 0;
}

int SIQ::Length() {
	return length;
}

bool SIQ::IsEmpty() {
	if (length == 0) {
		return true;
	}
	return false;
}

bool SIQ::IsFull() {
	try { Node* q = new Node; }

	catch (bad_alloc) {
		return true;
	}
	return false;
}

void SIQ::Enqueue(struct data x) {
	Node* q = new Node;
	q->data = x;
	q->next = NULL;
	if (front == NULL) {
		front = q;
	}
	else {
		back->next = q;
	}
	back = q;
	length++;
	return;
}

struct data SIQ::Dequeue() {
	if (IsEmpty() != true) {
		Node* q = front;
		struct data temp = front->data;
		if (front == NULL) {
			back == front;
		}
		delete q;
		length--;
		return temp;
	}
	else {
		struct data temp;
		return temp;
	}
}