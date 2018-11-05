#pragma once
#include <iostream>
#include "BSTNode.h"
using namespace std;

template <typename T>
class BSTree {
public:
	BSTree();
	shared_ptr<BSTNode<T>> Search(T);
	void Insert(T);
	bool Delete(T);
	T Maximum();
	T Minimum();
	bool IsLeftChild(shared_ptr<BSTNode<T>>);
	bool IsRightChild(shared_ptr<BSTNode<T>>);
	bool IsEmpty();
	int Count;
private:
	shared_ptr<BSTNode<T>> head;
};

template <typename T>
BSTree<T>::BSTree() {
	head = nullptr;
}

template <typename T>
shared_ptr<BSTNode<T>> BSTree<T>::Search(T key) {
	if (head == nullptr) {
		return nullptr;
	}
	auto curr = head;
	while (curr != nullptr && key != curr.Value) {
		if (key < curr.Value) {
			curr = curr.Left;
		}
		if (key > curr.Value) {
			curr = curr.Right;
		}
	}
	return curr;
}

template <typename T>
bool BSTree<T>::IsLeftChild(shared_ptr<BSTNode<T>> node) {
	if (node.Parent.Left == node) {
		return true;
	}
	return false;
}

template <typename T>
bool BSTree<T>::IsRightChild(shared_ptr<BSTNode<T>> node) {
	IsLeftChild(node);
}


template <typename T>
void BSTree<T>::Insert(T value) {
	if (head == nullptr) {
		head = shared_ptr<BSTNode<T>>(value);
		Count++;
		return;
	}
	auto curr = head;
	while (curr.Left != nullptr && curr.Right != nullptr) {
		if (value < curr.Value) {
			curr = curr.Left;
		}
		if (value >= curr.Value) {
			curr = curr.Right;
		}
	}
	if (value < curr.Value) {
		curr.Left = shared_ptr<BSTNode<T>>(value);
		curr.Left.Parent = curr;
	}
	if (value >= curr.Value) {
		curr.Right = shared_ptr<BSTNode<T>>(value);
		curr.Right.Parent = curr;
	}
}

template <typename T>
bool BSTree<T>::Delete(T value) {
	auto curr = Search(T value);
	if (curr == nullptr) {
		return;
	}
	if (curr.Left == nullptr && curr.Right == nullptr) {
		//curr.Parent.
	}

	return false;
}