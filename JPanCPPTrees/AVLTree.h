#pragma once
#include "AVLNode.h"
#include <iostream>
using namespace std;

template <typename T>
class AVLTree {
public:
	AVLTree();
	unique_ptr<AVLNode<T>> LeftRotation(unique_ptr<AVLNode<T>>&);
	unique_ptr<AVLNode<T>> RightRotation(unique_ptr<AVLNode<T>>&);
	unique_ptr<AVLNode<T>> Balance(unique_ptr<AVLNode<T>>&);
	void Add(T);
	bool Delete(T);
private:
	unique_ptr<AVLNode<T>> head;
	unique_ptr<AVLNode<T>> AddHelper(T, unique_ptr<AVLNode<T>>&);
	bool DeleteHelper(T);
};

template <typename T>
AVLTree<T>::AVLTree() {
	head = nullptr;
}

template <typename T>
unique_ptr<AVLNode<T>> AVLTree<T>::LeftRotation(unique_ptr<AVLNode<T>>& node) {
	unique_ptr<AVLNode<T>> pivot = move(node->Right);
	node->Right = move(pivot->Left);
	pivot->Left = move(node);
	return pivot;
}

template <typename T>
unique_ptr<AVLNode<T>> AVLTree<T>::RightRotation(unique_ptr<AVLNode<T>>& node) {
	//fix rotate here
	throw "not implemented error";
}

template <typename T>
unique_ptr<AVLNode<T>> AVLTree<T>::Balance(unique_ptr<AVLNode<T>>& node) {

	node->UpdateHeight();

	if (node->GetBalance() > 1) {
		if (node->Right->GetBalance() < 0)
		{
			node->Right = move(RightRotation(node->Right));
		}

		node = move(LeftRotation(node));
	}
	else if (node->GetBalance() < -1) {
		//fix balance here
	}

	return node;
}

template <typename T>
unique_ptr<AVLNode<T>> AVLTree<T>::AddHelper(T value, unique_ptr<AVLNode<T>>& node) {

	if (node == nullptr) {
		return make_unique<AVLNode<T>>(value);
	}

	if (value < node->Left->Value) {
		node->Left = move(AddHelper(value, node->Left));
	}
	else if (value < node->Right->Value) {
		node->Right = move(AddHelper(value, node->Right));
	}
	else {
		throw "repeated number error";
	}

	node = move(Balance(node));
	return node;
}

template <typename T>
void AVLTree<T>::Add(T value) {
	if (head == nullptr) {
		head = make_unique<AVLNode<T>>(value);
		return;
	}
	head = move(AddHelper(value, head));
}
