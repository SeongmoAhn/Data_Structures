// ThreadedBinaryTree.cpp
#include "ThreadedBinaryTree.h"
int main(void)
{
    ThreadedBinTree tree;
    //       G
    //   C       F
    // A   B   D   E
    ThreadedBinNode* n1 = new ThreadedBinNode('A', NULL, NULL, true);
    ThreadedBinNode* n2 = new ThreadedBinNode('B', NULL, NULL, true);
    ThreadedBinNode* n3 = new ThreadedBinNode('C', n1, n2, false);
    ThreadedBinNode* n4 = new ThreadedBinNode('D', NULL, NULL, true);
    ThreadedBinNode* n5 = new ThreadedBinNode('E', NULL, NULL, false);
    ThreadedBinNode* n6 = new ThreadedBinNode('F', n4, n5, false);
    ThreadedBinNode* n7 = new ThreadedBinNode('G', n3, n6, false);
    tree.setRoot(n7);
    // 스레드 설정
    n1->setRight(n3);
    n2->setRight(n7);
    n4->setRight(n6);
    // inorder
    tree.threadedInorder();

    return 0;
}