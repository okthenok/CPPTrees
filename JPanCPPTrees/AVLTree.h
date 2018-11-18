#pragma once
#include "AVLNode.h"
#include <iostream>
using namespace std;

template <typename T>
class AVLTree {
public:
	AVLTree();
	void LeftRotation(unique_ptr<AVLNode<T>>);
	void RightRotation(unique_ptr<AVLNode<T>>);
	void Balance(unique_ptr<AVLNode<T>>);
	void Add(T);
	bool Delete(T);
private:
	unique_ptr<AVLNode<T>> head;
	bool DeleteHelper(T);
};

template <typename T>
AVLTree<T>::AVLTree() {
	head = nullptr;
}

template <typename T>
void AVLTree<T>::LeftRotation(unique_ptr<AVLNode<T>> node) {
	node.Right = node.Right.Left
	node = node.Right.Left;
}

template <typename T>
void AVLTree<T>::RightRotation(unique_ptr<AVLNode<T>> node) {
	node = node.Left.Right;
}

template <typename T>
void AVLTree<T>::Balance(unique_ptr<AVLNode<T>> node) {
	if (node.Balance() > 1) {
		if (node.Right.Right != nullptr) {
			LeftRotation(node);
		}
		else {
			RightRotation(node.Right);
			LeftRotation(node);
		}
	}
	else if (node.Balance() < -1) {
		if (node.Left.Left != nullptr) {
			RightRotation(node);
		}
		else {
			LeftRotation(node.Left);
			RightRotation(node);
		}
	}
}