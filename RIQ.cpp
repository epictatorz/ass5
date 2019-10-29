#include "RIQ.h"
#include "structs.h"

RIQ::RIQ() {
	front = NULL;
	back = front;
	length = 0;
}

int RIQ::Length() {
	return length;
}

bool RIQ::IsEmpty() {
	if (length == 0) {
		return true;
	}
	return false;
}

bool RIQ::IsFull() {
	if (length == RIQ_SIZE) {
		return true;
	}
	try { Node* q = new Node; }

	catch (bad_alloc)
	{
		cout << "List is full" << endl;
		return true;
	}
	return false;
}

void RIQ::Enqueue(info x) {
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

info RIQ::Dequeue() {
	if (IsEmpty() != true) {
		Node* q = front;
		info temp = front->data;
		if (front == NULL) {
			back == front;
		}
		delete q;
		length--;
		return temp;
	}
	else {
		info temp;
		return temp;
	}
}