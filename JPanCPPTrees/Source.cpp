#include <iostream>
#include "BSTNode.h"
#include "BSTree.h"
#include "AVLNode.h"
#include "AVLTree.h"
using namespace std;

int main() {
	AVLTree<int> tree;
	for (int i = 0; i <= 10; i++)
	{
		tree.Add(i);
	}

	tree.Print();
	
	system("PAUSE");
	return 0;
}