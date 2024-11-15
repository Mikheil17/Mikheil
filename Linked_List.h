#pragma once
using namespace std;
#include <string>

struct Node2 {
	string data;
	Node2* next;
	Node2* prev;
	Node2(string data) : data(data), next(nullptr), prev(nullptr) {}

};

class LinkedList {
private:
	
	Node2* tail;

public:
	Node2* head;

	LinkedList() : head(nullptr), tail(nullptr) {}
	~LinkedList();

	void append(string data);
	bool remove(string data);
	bool tailRemove(string data);
	void prepend(string data);


	void display(ostream& os);
	void tailDisplay(ostream& os);
	friend ostream& operator<<(ostream& os, LinkedList& right);


};

