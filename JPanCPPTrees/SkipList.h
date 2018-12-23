#pragma once
#include "SkipListNode.h"
using namespace std;

template <typename T>
class SkipList {
public:
	int Count;
	unique_ptr<SkipListNode<T>> head;

	SkipList();
	void Add(T);
	bool Remove(T);
	void Search(T);
	void Enumerate();
};

template <typename T>
SkipList<T>::SkipList() {
	head = nullptr;
}

template <typename T>
void SkipList<T>::Add(T value) {
	unique_ptr<SkipListNode<T>> node = make_unique<SkipListNode<T>>(value);
}