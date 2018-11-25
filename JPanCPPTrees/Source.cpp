#include <iostream>
#include "BSTNode.h"
#include "BSTree.h"
#include "AVLNode.h"
#include "AVLTree.h"
using namespace std;

int main() {
	AVLTree<int> tree;
	tree.Add(6);
	tree.Add(88);
	tree.Add(18);
	tree.Add(96);
	tree.Add(92);
	tree.Add(63);
	tree.Add(46);
	tree.Add(16);
	tree.Add(71);
	tree.Add(86);
	/*tree.IsEmpty();
	cout << tree.Search(86) << endl;
	tree.Delete(71);*/
	system("PAUSE");
	return 0;
}