#pragma once
#include <memory>
#include <random>
#include <time.h>
#include "SkipListNode.h"
using namespace std;

template <typename T>
class SkipList {
public:
	int Count;
	shared_ptr<SkipListNode<T>> head;

	SkipList();
	void ChooseRandHeight(shared_ptr<SkipListNode<T>>&);
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
void SkipList<T>::ChooseRandHeight(shared_ptr<SkipListNode<T>>& node) {
	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist2(0, 1);

	while (dist2(rng) % 2 == 0 && node->Height < head->Height + 1) {
		node->Height++;
		node->Nexts.emplace_back(nullptr);
	
	if (node->Height > head->Height) {
		for (int i = node->Height; i > head->Height; i--) {
			head->Nexts.emplace_back(nullptr);
		}
		head->Height = node->Height;
	}
}

template <typename T>
void SkipList<T>::Add(T value) {
	if (head == nullptr) {
		head = make_shared<SkipListNode<T>>();
		return;
	}
	shared_ptr<SkipListNode<T>> newNode = make_shared<SkipListNode<T>>(value);
	ChooseRandHeight(newNode);
	auto search = head.get();
	int currHeight = head->Height - 1;
	while (currHeight > -1) {
		if (search->Nexts[currHeight] == nullptr || search->Nexts[currHeight]->Value > value) {
			if (currHeight < newNode->Height) {
				newNode->Nexts[currHeight] = search->Nexts[currHeight];
				search->Nexts[currHeight] = newNode;
			}
			currHeight--;
		}
		else if (search->Nexts[currHeight]->Value < value) {
			search = search->Nexts[currHeight].get();
		}
	}
}