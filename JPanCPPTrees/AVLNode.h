#pragma once
#include <string>
using namespace std;

#define FRIEND_TEST(test_case_name, test_name)\
friend class test_case_name##_##test_name##_Test

template <typename T>
class AVLNode {
public:
	T Value;
	int Height;
	unique_ptr<AVLNode<T>> Left;
	unique_ptr<AVLNode<T>> Right;

	AVLNode(T);
	void UpdateHeight();
	int GetBalance();
	void Print(string prefix, bool isTail);
};

template <typename T>
AVLNode<T>::AVLNode(T value) {
	Value = value;
	Height = 1;
}

template <typename T>
void AVLNode<T>::UpdateHeight() {
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

	int right = 0;
	int left = 0;
	if (Right != nullptr)
	{
		right = Right->Height;
	}

	if (Left != nullptr)
	{
		left = Left->Height;
	}

	return right - left;
}

template<typename T>
void AVLNode<T>::Print(string prefix, bool isTail)
{
	cout << prefix;
	if (isTail)
	{
		cout << "->";
		prefix += "  ";
	}
	else
	{
		cout << "|>";
		prefix += "| ";
	}
	cout << Value << endl;

	if (Left != nullptr && Right != nullptr)
	{
		Left->Print(prefix, false);
		Right->Print(prefix, true);
	}
	else if (Left != nullptr)
	{
		Left->Print(prefix, true);
	}
	else if (Right != nullptr)
	{
		Right->Print(prefix, true);
	}

}
