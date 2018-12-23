#pragma once
using namespace std;

template <typename T>
class SkipListNode {
public:
	T Value;
	int Height;
	unique_ptr<SkipListNode<T>> Next;
	SkipListNode(T);
};

template <typename T>
SkipListNode<T>::SkipListNode(T value) {
	Value = value;
	Height = 0;
}