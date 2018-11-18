#pragma once
using namespace std;

template <typename T>
class BSTNode {
public:
	BSTNode(T);
	T Value;
	shared_ptr<BSTNode<T>> Left;
	shared_ptr<BSTNode<T>> Right;
	shared_ptr<BSTNode<T>> Parent;
};

template <typename T>
BSTNode<T>::BSTNode(T value) {
	Value = value;
}