#pragma once
#include <memory>
#include <vector>
using namespace std;

template <typename T>
class SkipListNode {
public:
	T Value;
	int Height;
	vector<unique_ptr<SkipListNode<T>>> Nexts;
	SkipListNode(T);
};

template <typename T>
SkipListNode<T>::SkipListNode(T value) {
	Value = value;
	Height = 1;
	Nexts.emplace_back(nullptr);
}