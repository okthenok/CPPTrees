#pragma once
#include <memory>
#include <vector>
using namespace std;

template <typename T>
class SkipListNode {
public:
	T Value;
	int Height;
	vector<shared_ptr<SkipListNode<T>>> Nexts;
	SkipListNode(T);
	SkipListNode();
};

template <typename T>
SkipListNode<T>::SkipListNode(T value) {
	Value = value;
	Height = 1;
	Nexts.emplace_back(nullptr);
}

template <typename T>
SkipListNode<T>::SkipListNode() {
	Height = 1;
	Nexts.emplace_back(nullptr);
}