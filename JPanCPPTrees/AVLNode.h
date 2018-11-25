#pragma once
using namespace std;

template <typename T>
class AVLNode {
public:
	T Value;
	int Height;
	unique_ptr<AVLNode<T>> Left;
	unique_ptr<AVLNode<T>> Right;

	AVLNode(T);
	int UpdateHeight();
	int GetBalance();
};

template <typename T>
AVLNode<T>::AVLNode(T value) {
	Value = value;
}

template <typename T>
int AVLNode<T>::UpdateHeight() {
	if(Left == nullptr && Right == nullptr)
	{
		Height = 1;
		return;
	}
	else if (Left == nullptr)
	{
		Height = Right->Height + 1;
		return;
	}
	else if (Right == nullptr)
	{
		Height = Left->Height + 1;
		return;
	}
	else
	{
		if (Left->Height > Right->Height)
		{
			Height = Left->Height + 1;
		}
		else
		{
			Height = Right->Height + 1;
		}
	}
}

template <typename T>
int AVLNode<T>::GetBalance() {
	return Right.Height - Left.Height;
}