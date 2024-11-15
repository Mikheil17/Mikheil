#pragma once
#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;

	Node() : data(0), left(nullptr), right(nullptr) {}
	Node(int data) : data(data), left(nullptr), right(nullptr) {}
	int degree() const;

};


class BST
{
private:
	Node* root;
	bool insert(Node*& node, int data);
	bool remove(Node*& node, int data);
	bool find(Node* node, int data);
	void inOrder(Node* node, ostream& os, bool firstCall);
	void preOrder(Node* node, ostream& os, bool firstCall);
	void postOrder(Node* node, ostream& os, bool firstCall);
public:
	BST() : root(nullptr) {}
	~BST();
	bool insert(int data) { return insert(root,data); }
	bool remove(int data) { return remove(root,data); }
	bool find(int data) { return find(root,data); }
	void inOrder(ostream& os) { return inOrder(root,os, true); }
	void preOrder(ostream& os) { return preOrder(root,os, true); }
	void postOrder(ostream& os) { return postOrder(root,os, true); }
};


