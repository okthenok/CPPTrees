#include <iostream>
#include "BSTNode.h"
#include "BSTree.h"
#include "AVLNode.h"
#include "AVLTree.h"
#include "SkipListNode.h"
#include "SkipList.h"
#include <vector>
using namespace std;

int main() {
	SkipList<int> list;
	for (int i = 1; i <= 10; i++)
	{
		list.Add(i);
	}
	list.Remove(6);
	auto stuff = list.Enumerate();
	system("PAUSE");
	return 0;
}