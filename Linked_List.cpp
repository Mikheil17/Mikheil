#include "Linked_List.h"
#include <iostream>

LinkedList::~LinkedList() {
	Node2* tmp = head;
	Node2* prev = nullptr;

	while (tmp != nullptr) {

		prev = tmp;
		tmp = tmp->next;
		delete prev;
	}

	head = nullptr;
	tail = nullptr;
}
void LinkedList::append(string data) {
	Node2* tmp = new Node2(data);
	//If list empty
	if (head == nullptr) {
		head = tmp;
	}
	else {
		tail->next = tmp;
		tmp->prev = tail;
	}
	tail = tmp;
}
bool LinkedList::remove(string data) {
	if (head == nullptr) {
		//List is empty
		return false;
	}

	Node2* tmp = head;
	Node2* prev = nullptr;

	//Removing head
	if (head->data == data) {
		head = head->next;
		if (head == nullptr) { //Only one element
			tail = nullptr;
		}
		delete tmp;
		return true;
	}

	while (tmp != nullptr && tmp->data != data) {
		prev = tmp;
		tmp = tmp->next;
	}

	if (tmp == nullptr) {
		return false; // Value not found
	}

	//Removing tail
	if (tmp == tail) {
		tail = prev;
		prev->next = nullptr;
	}
	else { //Removing middle
		prev->next = tmp->next;

		tmp->next->prev = prev;
	}
	delete tmp;
	return true;
}
void LinkedList::display(ostream& os) {
	Node2* tmp = head;

	while (tmp != nullptr) {
		os << tmp->data << " ";
		tmp = tmp->next;
	}
	os << endl;
}
ostream& operator<<(ostream& os, LinkedList& right) {
	right.display(os);
	return os;
}
void LinkedList::prepend(string data) {
	Node2* tmp = new Node2(data);
	//If list empty
	if (head == nullptr) {
		tail = tmp;
	}
	else {
		tmp->next = head;
		head->prev = tmp;
	}
	head = tmp;
}
bool LinkedList::tailRemove(string data) {
	if (head == nullptr) {
		//List is empty
		return false;
	}

	Node2* tmp = tail;
	while (tmp->data != data) {
		tmp = tmp->prev;
		if (tmp == nullptr) {
			//Value not found
			return false;
		}
	}

	//Removing tail
	if (tmp == tail) {
		tail = tmp->prev;
		tail->next = nullptr;

	} //Removing head
	else if (head->data == data) {
		head = head->next;
		head->prev = nullptr;
		if (head == nullptr) { //Only one element
			tail = nullptr;
		}
	}
	else { //Removing middle
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
	}
	delete tmp;
	return true;
}
void LinkedList::tailDisplay(ostream& os) {
	Node2* tmp = tail;

	while (tmp != nullptr) {
		os << tmp->data << " ";
		tmp = tmp->prev;
	}
	os << endl;
}