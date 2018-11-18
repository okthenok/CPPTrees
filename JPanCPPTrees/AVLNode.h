#pragma once
using namespace std;

template <typename T>
class AVLNode {
public:
	AVLNode(T);
	T Value;
	unique_ptr<AVLNode<T>> Left;
	unique_ptr<AVLNode<T>> Right;
	int Height();
	int Balance();
};

template <typename T>
AVLNode<T>::AVLNode(T value) {
	Value = value;
	Height = 0;
	Balance = 0;
}

template <typename T>
int AVLNode<T>::Height() {
	if (Left.Height > Right.Height) {
		return Left.Height + 1;
	}
	return Right.Height + 1;
}

template <typename T>
int AVLNode<T>::Balance() {
	return Right.Height - Left.Height;
}