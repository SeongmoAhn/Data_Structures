// BinaryTree.h
#include "BinaryNode.h"
class BinaryTree
{
private:
    BinaryNode* root;
public:
    BinaryTree(): root(NULL) {}
    void setRoot(BinaryNode* node) { root = node; }
    BinaryNode* getRoot() { return root; }
    bool isEmpty() { return root == NULL; }
    
    // 순회 연산
    void inorder()
    {
        printf("\n   inorder: ");
        inorder(root);
    }
    void inorder(BinaryNode* Node)
    {
        if (Node != NULL)
        {
            inorder(Node->getLeft());
            printf(" [%c] ", Node->getData());
            inorder(Node->getRight());
        }
    }
    void preorder()
    {
        printf("\n  preorder: ");
        preorder(root);
    }
    void preorder(BinaryNode* Node)
    {
        if (Node != NULL)
        {
            printf(" [%c] ", Node->getData());
            preorder(Node->getLeft());
            preorder(Node->getRight());
        }
    }
    void postorder()
    {
        printf("\n postorder: ");
        postorder(root);
    }
    void postorder(BinaryNode* Node)
    {
        if (Node != NULL)
        {
            postorder(Node->getLeft());
            postorder(Node->getRight());
            printf(" [%c] ", Node->getData());
        }
    }

    // 추가 연산 추가
};