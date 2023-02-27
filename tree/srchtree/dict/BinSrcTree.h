// BinSrcTree.h
#include "BinaryTree.h"
class BinSrcTree : public BinaryTree
{
public:
    // 이진 탐색 트리의 탐색 연산
    BinaryNode* search(char* key) { return searchRecur(root, key); }
    BinaryNode* searchRecur(BinaryNode* n, char* key)
    {
        if (n == NULL) return NULL;
        if (n->compare(key) == 0) return n;
        else if (n->compare(key) < 0)
            return searchRecur(n->getLeft(), key);
        else return searchRecur(n->getRight(), key); 
    }
    // 이진 탐색 트리의 삽입 연산
    void insert(BinaryNode* n)
    {
        if (n == NULL) return ;
        if (isEmpty()) root = n;
        else insertRecur(root, n);
    }
    void insertRecur(BinaryNode* r, BinaryNode* n)
    {
        if (n->compare(r) == 0) return ;
        else if (n->compare(r) > 0)
        {
            if (r->getLeft() == NULL)
                r->setLeft(n);
            else
                insertRecur(r->getLeft(), n);
        }
        else
        {
            if (r->getRight() == NULL)
                r->setRight(n);
            else
                insertRecur(r->getRight(), n):
        }
    }
    // 이진 탐색 트리의 삭제 연산
    void remove(char* data)
    {
        if (isEmpty()) return ;
        BinaryNode* parent = NULL;
        BinaryNode* node = root;
        while (node != NULL && node->compare(data) != 0)
        {
            parent = node;
            node = (node->compare(data) < 0) ? node->getLeft() : node->getRight();
        }
        if (node != NULL)
            remove(parent, node);
    }
    void remove(BinaryNode* parent, BinaryNode* node)
    {

        // case1
        if (node->isLeaf())
        {
            if (parent == NULL)
                root = NULL;
            else
            {
                if (parent->getLeft() == node)
                    parent->setLeft(NULL);
                else
                    parent->setRight(NULL);
            }
        }
        // case2
        else if (node->getLeft() == NULL || node->getRight() == NULL)
        {
            BinaryNode* child = (node->getLeft() != NULL)
                    ? node->getLeft() : node->getRight();
            if (node == root)
                root = child;
            else
            {
                if (parent->getLeft() == node)
                    parent->setLeft(child);
                else
                    parent->setRight(child);    
            }
        } 
        // case3
        else
        {
            BinaryNode* replace = node->getRight(); // 후계 노드
            BinaryNode* reParent = node; // 후계노드 부모노드
            while (replace->getLeft() != NULL)
            {
                reParent = replace;
                replace = replace->getLeft();
            }
            if (reParent->getLeft()  == replace)
                reParent->setLeft(replace->getRight());
            else
                reParent->setRight(replace->getRight());
            node->setData(replace->getData());
            node = replace;
        }
        delete node; 
    }
};