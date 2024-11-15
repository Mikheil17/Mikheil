#include "BST.h"

int Node::degree() const {
	int count = 0;
	if (left != nullptr) count++;
	if (right != nullptr) count++;
	return count;
}

BST::~BST() {}

bool BST::insert(Node*& node, int data)
{
	if (node == nullptr) {
		node = new Node(data);
		return true;
	}
	if (data < node->data)
		return insert(node->left, data);
	if (data > node->data)
		return insert(node->right, data);
	return false;
}

bool BST::remove(Node*& node, int data)
{
	if (node == nullptr)
		return false;
	if (data < node->data)
		return remove(node->left, data);
	if (data > node->data)
		return remove(node->right, data);
	int deg = node->degree();

	if (deg == 0) {
		delete node;
		node = nullptr;
	}
	else if (deg == 1) {

		Node* tmp = node;
		if (node->left != nullptr) {
			node = node->left;
		}
		else {
			node = node->right;
		}
		delete tmp;
	}
	else {
		Node* tmp = node;
		tmp = node->left;

		while (tmp->right != nullptr) {
			tmp = node->right;
		} 
		node->data = tmp->data;
		remove(node->left, tmp->data);

	}
	return true;
}

void BST::postOrder(Node* node, ostream& os, bool firstCall)
{
	if (firstCall) os << "postOrder: ";
	if (node == nullptr) return;
	postOrder(node->left, os, false);
	postOrder(node->right, os, false);
	os << node->data << " ";
	if (firstCall) os << endl;
}

void BST::preOrder(Node* node, ostream& os, bool firstCall) {

	if (firstCall) os << "preOrder: ";
	if (node == nullptr) return;
	os << node->data << " ";
	preOrder(node->left, os, false);
	preOrder(node->right, os, false);
	if (firstCall) os << endl;
}

void BST::inOrder(Node* node, ostream& os, bool firstCall) {
	
	if (firstCall) os << "inOrder: ";
	if (node == nullptr) return;
	inOrder(node->left, os, false);
	os << node->data << " ";
	inOrder(node->right, os, false);
	if (firstCall) os << endl;
}

bool BST::find(Node* node, int data) {

	if (node == nullptr) {return false; }
	if (data < node->data) {
		return find(node->left, data);
	}
	else if (data > node->data) {
		return find(node->right, data);
	} 
	return true ;
}

