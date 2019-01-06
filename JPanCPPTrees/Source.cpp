#include <iostream>
#include "BSTNode.h"
#include "BSTree.h"
#include "AVLNode.h"
#include "AVLTree.h"
#include "SkipListNode.h"
#include "SkipList.h"
using namespace std;

int main() {
	SkipList<int> list;
	for (int i = 0; i <= 10; i++)
	{
		list.Add(i);
	}
	
	system("PAUSE");
	return 0;
}