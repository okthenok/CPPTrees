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
	/*tree.Delete(5);
	tree.Delete(7);*/
	tree.Print();
	stack<AVLNode<int>*> nodes;
	tree.InOrderDFS(tree.head.get(), nodes);
	
	system("PAUSE");
	return 0;
}