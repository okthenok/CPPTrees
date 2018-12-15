#pragma once
#include "AVLNode.h"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

template <typename T>
class AVLTree {
public:
	FRIEND_TEST(AVLTreeTest, TestTreeInitialize);
	FRIEND_TEST(AVLTreeTest, TestTreeAdd);
	FRIEND_TEST(AVLTreeTest, TestTreeAVL);
	AVLTree();
	void Add(T);
	bool Delete(T);
	bool Contains(T);
	void Print();
	void PreOrderDFS(AVLNode<T>*, stack<AVLNode<T>*>&);
	void InOrderDFS(AVLNode<T>*, stack<AVLNode<T>*>&);
	void PostOrderDFS(AVLNode<T>*, stack<AVLNode<T>*>&);
	unique_ptr<AVLNode<T>> head;
private:
	unique_ptr<AVLNode<T>> LeftRotation(unique_ptr<AVLNode<T>>);
	unique_ptr<AVLNode<T>> RightRotation(unique_ptr<AVLNode<T>>);
	unique_ptr<AVLNode<T>> Balance(unique_ptr<AVLNode<T>>);
	unique_ptr<AVLNode<T>> AddHelper(T, unique_ptr<AVLNode<T>>);
	unique_ptr<AVLNode<T>> DeleteHelper(T, unique_ptr<AVLNode<T>>);
};

template <typename T>
AVLTree<T>::AVLTree() {
	head = nullptr;
}

template <typename T>
unique_ptr<AVLNode<T>> AVLTree<T>::LeftRotation(unique_ptr<AVLNode<T>> node) {
	unique_ptr<AVLNode<T>> pivot = move(node->Right);
	node->Right = move(pivot->Left);
	pivot->Left = move(node);

	pivot->Left->UpdateHeight();
	pivot->UpdateHeight();

	return pivot;
}

template <typename T>
unique_ptr<AVLNode<T>> AVLTree<T>::RightRotation(unique_ptr<AVLNode<T>> node) {
	unique_ptr<AVLNode<T>> pivot = move(node->Left);
	node->Left = move(pivot->Right);
	pivot->Right = move(node);

	pivot->Right->UpdateHeight();
	pivot->UpdateHeight();

	return pivot;
}

template <typename T>
unique_ptr<AVLNode<T>> AVLTree<T>::Balance(unique_ptr<AVLNode<T>> node) {

	node->UpdateHeight();

	if (node->GetBalance() > 1) {
		if (node->Right->GetBalance() < 0)
		{
			node->Right = RightRotation(move(node->Right));
		}

		node = LeftRotation(move(node));
	}
	else if (node->GetBalance() < -1) {
		if (node->Left->GetBalance() > 0) {
			node->Left = LeftRotation(move(node->Left));
		}

		//rotate right
		node = RightRotation(move(node));
	}

	return node;
}

template <typename T>
unique_ptr<AVLNode<T>> AVLTree<T>::AddHelper(T value, unique_ptr<AVLNode<T>> node) {
	if (node == nullptr) {
		return make_unique<AVLNode<T>>(value);
	}

	if (value < node->Value) {
		node->Left = AddHelper(value, move(node->Left));
	}
	else if (value > node->Value) {
		node->Right = AddHelper(value, move(node->Right));
	}
	else {
		throw "repeated number error";
	}

	node = Balance(move(node));
	return node;
}

template <typename T>
void AVLTree<T>::Add(T value) {
	head = AddHelper(value, move(head));
}

template<typename T>
void AVLTree<T>::Print()
{
	head->Print("", true);
}

template <typename T>
unique_ptr<AVLNode<T>> AVLTree<T>::DeleteHelper(T value, unique_ptr<AVLNode<T>> node) {
	if (node == nullptr) {
		return nullptr;
	}
	
	if (value < node->Value) {
		node->Left = DeleteHelper(value, move(node->Left));
	}
	else if (value > node->Value) {
		node->Right = DeleteHelper(value, move(node->Right));
	}
	else {
		if ((node->Left != nullptr) && (node->Right != nullptr)) {
			auto temp = node->Left.get();
			while (temp->Right != nullptr) {
				temp = temp->Right.get();
			}
			node->Value = temp->Value;
			DeleteHelper(temp->Value, move(node->Left));
		}
		else if (node->Left != nullptr) {
			 return move(node->Left);
		}
		else if (node->Right != nullptr) {
			return move(node->Right);
		}
		else {
			return nullptr;
		}
	}
	node = Balance(move(node));
	return node;
}

template <typename T>
bool AVLTree<T>::Delete(T value) {
	head = DeleteHelper(value, move(head));
	return true;
}

template <typename T>
bool AVLTree<T>::Contains(T value) {
	bool found = false;
	auto find = move(head);
	while (!found) {
		if (find == nullptr) {
			return false;
		}
		if (value > find->Value) {
			find = move(find->Right);
		}
		else if (value < find->Value) {
			find = move(find->Left);
		}
		else {
			return true;
		}
	}
}

template <typename T>
void AVLTree<T>::PreOrderDFS(AVLNode<T>* node, stack<AVLNode<T>*>& nodes) {
	nodes.push(node);
	if (node->Left != nullptr) { 
		node->Left; 
	}
	if (node->Right != nullptr) { 
		node->Right; 
	}
}

template <typename T>
void AVLTree<T>::InOrderDFS(AVLNode<T>* node, stack<AVLNode<T>*>& nodes) {
	if (node->Left != nullptr) {
		node->Left;
	}
	nodes.push(node);
	if (node->Right != nullptr) {
		node->Right;
	}
}

template <typename T>
void AVLTree<T>::PostOrderDFS(AVLNode<T>* node, stack<AVLNode<T>*>& nodes) {
	if (node->Left != nullptr) {
		node->Left;
	}
	if (node->Right != nullptr) {
		node->Right;
	}
	nodes.push(node);
}