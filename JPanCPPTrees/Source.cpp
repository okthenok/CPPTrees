#include <iostream>
#include "BSTNode.h"
#include "BSTree.h"

int main() {
	BSTree<int> tree;
	tree.Insert(6);
	tree.Insert(88);
	tree.Insert(18);
	tree.Insert(96);
	tree.Insert(92);
	tree.Insert(63);
	tree.Insert(46);
	tree.Insert(16);
	tree.Insert(71);
	tree.Insert(86);
	tree.IsEmpty();
	cout << tree.Search(86) << endl;
	tree.Delete(71);
	system("PAUSE");
	return 0;
}