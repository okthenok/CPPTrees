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


TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}