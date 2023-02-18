// BinaryTree.cpp
#include "BinaryTree.h"
int main(void)
{
    BinaryTree tree;
    BinaryNode* d = new BinaryNode('D', NULL, NULL);
    BinaryNode* e = new BinaryNode('E', NULL, NULL);
    BinaryNode* b = new BinaryNode('B', d, e);
    BinaryNode* f = new BinaryNode('F', NULL, NULL);
    BinaryNode* c = new BinaryNode('C', f, NULL);
    BinaryNode* a = new BinaryNode('A', b, c);
    tree.setRoot(a);
    tree.inorder();
    tree.preorder();
    tree.postorder();
    tree.levelorder();
    printf(" 노드의 개수: %d\n", tree.getCount());
    printf(" 단말의 개수: %d\n", tree.getLeafCount());
    printf(" 트리의 높이: %d\n", tree.getHeight());

    BinaryTree tree2;
    //        +
    //    *       -
    // 3    2  5     6
    BinaryNode* n1 = new BinaryNode(3, NULL, NULL);
    BinaryNode* n2 = new BinaryNode(2, NULL, NULL);
    BinaryNode* n3 = new BinaryNode('*', n1, n2);
    BinaryNode *n4 = new BinaryNode(5, NULL, NULL);
    BinaryNode *n5 = new BinaryNode(6, NULL, NULL);
    BinaryNode* n6 = new BinaryNode('-', n4, n5);
    BinaryNode* n7 = new BinaryNode('+', n3, n6);
    tree2.setRoot(n7);
    printf(" 계산 결과: %d\n", tree2.evaluate());

    return 0;
}