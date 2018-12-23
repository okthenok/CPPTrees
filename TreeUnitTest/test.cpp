#include "pch.h"

#include "../JPanCPPTrees/AVLTree.h"


TEST(AVLTreeTest, TestTreeInitialize) {
	AVLTree<int> tree;
	EXPECT_EQ(tree.head, nullptr);
}
TEST(AVLTreeTest, TestTreeAdd) {
	AVLTree<int> tree;
	for (int i = 0; i <= 10; i++) {
		tree.Add(i);
	}
	EXPECT_TRUE(tree.head->GetBalance() < 2 && tree.head->GetBalance() > -2);
}

TEST(AVLTreeTest, TestTreeDFS) {
	AVLTree<int> tree;
	for (int i = 0; i <= 10; i++) {
		tree.Add(i);
	}
	stack<AVLNode<int>*> nodes;
	tree.InOrderDFS(tree.head.get(), nodes);
	for (int i = 10; i >= 0; i--) {
		EXPECT_EQ(nodes.top()->Value, i);
		nodes.pop();
	}
}

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}