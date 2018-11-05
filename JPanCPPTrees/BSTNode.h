#pragma once
#include <iostream>

template <typename T>
class BSTNode {
public:
	BSTNode(T);
	T Value;
	BSTNode Left;
	BSTNode Right;
	BSTNode Parent;
};

template <typename T>
BSTNode<T>::BSTNode(T value) {
	Value = value;
}