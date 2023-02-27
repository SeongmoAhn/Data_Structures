// BinaryTree.h
#include "BinaryNode.h"
#include <queue>
using namespace std;
class BinaryTree
{
private:
public:
    BinaryNode* root;
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
    void levelorder()
    {
        printf("\nleverorder: ");
        if (!isEmpty())
        {
            queue<BinaryNode*> q;
            q.push(root);
            while (!q.empty())
            {
                BinaryNode* n = q.front();
                q.pop();
                if (n != NULL)
                {
                    printf(" [%c] ", n->getData());
                    q.push(n->getLeft());
                    q.push(n->getRight());
                }
            }
        }
        printf("\n");
    }

    // 추가 연산 추가
    int getCount() { return isEmpty() ? 0 : getCount(root); } // 노드 개수 구하기
    int getCount(BinaryNode* parentNode)
    {
        if (parentNode == NULL) return 0;
        return 1 + getCount(parentNode->getLeft()) + getCount(parentNode->getRight());
    }
    int getLeafCount() { return isEmpty() ? 0 : getLeafCount(root); } // 단말노드 개수 구하기
    int getLeafCount(BinaryNode* parentNode)
    {
        if (parentNode == NULL) return 0;
        if (parentNode->isLeaf()) return 1;
        else
            return getLeafCount(parentNode->getLeft()) + getLeafCount(parentNode->getRight());
    }
    int getHeight() { return isEmpty() ? 0 : getHeight(root); } // 트리 높이 구하기
    int getHeight(BinaryNode* node)
    {
        if (node == NULL) return 0;
        int hLeft = getHeight(node->getLeft());
        int hRight = getHeight(node->getRight());
        return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
    }
};