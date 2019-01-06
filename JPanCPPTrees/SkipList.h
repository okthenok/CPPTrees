#pragma once
#include <memory>
#include "SkipListNode.h"
using namespace std;

template <typename T>
class SkipList {
public:
	int Count;
	unique_ptr<SkipListNode<T>> head;

	SkipList();
	void ChooseRandHeight(unique_ptr<SkipListNode<T>>&);
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
void SkipList<T>::ChooseRandHeight(unique_ptr<SkipListNode<T>>& node) {
	while (rand() % 2 == 0 && node->Height <= head->Height + 1) {
		node->Height++;
		node->Nexts.emplace_back(nullptr);
	}
}

template <typename T>
void SkipList<T>::Add(T value) {
	if (head == nullptr) {
		head = make_unique<SkipListNode<T>>(value);
		return;
	}
	unique_ptr<SkipListNode<T>> newNode = make_unique<SkipListNode<T>>(value);
	ChooseRandHeight(newNode);
	if (newNode->Height > head->Height) {
		head->Height = newNode->Height;
	}
	auto search = head.get();
	int currHeight = head->Height - 1;
	while (currHeight > -1 && (search->Nexts[currHeight] == nullptr || search->Nexts[currHeight]->Value > value)) {
		if (currHeight < newNode->Height) {
			newNode->Nexts[currHeight] = move(search->Nexts[currHeight]);
			search->Nexts[currHeight] = move(newNode);
		}
		currHeight--;
	}
}