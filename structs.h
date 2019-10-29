#ifndef structs_h
#define structs_h

struct info{
	info();
	int num;
	char data;
};

class Node {
public:
	info data;
	Node *next;
};
#endif