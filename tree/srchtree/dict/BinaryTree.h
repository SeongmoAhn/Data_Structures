// BinaryTree.h: 이진트리 클래스
#include "BinaryNode.h"
class BinaryTree
{
protected:
    BinaryNode* root;
public:
    BinaryTree(): root(NULL) {}
    bool isEmpty() { return root == NULL; }
    void inorder(BinaryNode* node)
    {
        if (node != NULL)
        {
            inorder(node->getLeft());
            node->display();
            inorder(node->getRight());
        }
    }
};