#pragma once
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
	bool DeleteHelper(shared_ptr<BSTNode<T>>);
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
	while (curr != nullptr && key != curr->Value) {
		if (key < curr->Value) {
			curr = curr->Left;
		}
		else {
			curr = curr->Right;
		}
	}
	return curr;
}

template <typename T>
bool BSTree<T>::IsLeftChild(shared_ptr<BSTNode<T>> node) {
	if (node->Parent->Left == node) {
		return true;
	}
	return false;
}

template <typename T>
bool BSTree<T>::IsRightChild(shared_ptr<BSTNode<T>> node) {
	return !IsLeftChild(node);
}


template <typename T>
void BSTree<T>::Insert(T value) {
	if (head == nullptr) {
		head = make_shared<BSTNode<T>>(value);
		Count++;
		return;
	}
	auto curr = head;
	while (curr != nullptr) {
		if (value < curr->Value) {
			if (curr->Left == nullptr) {
				curr->Left = make_shared<BSTNode<T>>(value);
				curr->Left->Parent = move(curr);
				break;
			}
			curr = curr->Left;
		}
		else if (value >= curr->Value) {
			if (curr->Right == nullptr) {
				curr->Right = make_shared<BSTNode<T>>(value);
				curr->Right->Parent = move(curr);
				break;
			}
			curr = curr->Right;
		}
	}
	//if curr == null: throw
	Count++;
}

template <typename T>
bool BSTree<T>::Delete(T value) {
	auto curr = Search(value);
	return DeleteHelper(curr);
}

template <typename T>
bool BSTree<T>::DeleteHelper(shared_ptr<BSTNode<T>> curr) {
	if (curr == nullptr) {
		return false;
	}
	if (curr->Left == nullptr && curr->Right == nullptr) {
		if (IsLeftChild(curr)) {
			curr->Parent->Left = nullptr;
		}
		else {
			curr->Parent->Right = nullptr;
		}
		Count--;
		return true;
	}
	if (curr->Left != nullptr ^ curr->Right != nullptr) {
		if (curr->Left != nullptr) {
			curr->Left->Parent = curr->Parent;
			if (IsLeftChild(curr)) {
				curr->Parent->Left = curr->Parent->Left->Left;
			}
			else {
				curr->Parent->Right = curr->Parent->Right->Left;
			}
		}
		else {
			curr->Right->Parent = curr->Parent;
			if (IsLeftChild(curr)) {
				curr->Parent->Left = curr->Parent->Left->Right;
			}
			else {
				curr->Parent->Right = curr->Parent->Right->Right;
			}
		}
		Count--;
		return true;
	}
	else {
		auto node = curr->Left;
		while (node->Right != nullptr) {
			node = node->Right;
		}
		curr->Value = node->Value;
		DeleteHelper(node);
		Count--;
		return true;
	}
	return false;
}

template <typename T>
T BSTree<T>::Maximum() {
	auto curr = head;
	while (curr->Right != nullptr) {
		curr = curr->Right;
	}
	return curr->Value;
}

template <typename T>
T BSTree<T>::Minimum() {
	auto curr = head;
	while (curr->Left != nullptr) {
		curr = curr->Left;
	}
	return curr->Value;
}

template <typename T>
bool BSTree<T>::IsEmpty() {
	if (head == nullptr) {
		return true;
	}
	return false;
}