// BinarySearchTree.h 이진 탐색 트리 클래스
#include "BinaryTree.h"
class BinSrctree : public BinaryTree
{
public:
    // 이진 탐색 트리의 탐색 연산
    BinaryNode* search(int key)
    {
        BinaryNode* node = searchRecur(root, key);
        if (node != NULL)
            printf("탐색 성공: 키 값이 %d인 노드 = 0x%x\n", node->getData(), node);
        else
            printf("탐색 실패: 키 값이 %d인 노드 없음\n", key);
        return node;
    }
    BinaryNode* searchRecur(BinaryNode* n, int key) // 재귀 구현
    {
        if (n == NULL)
            return NULL;
        if (key == n->getData())
            return n;
        else if (key < n->getData())
            return searchRecur(n->getLeft(), key);
        else
            return searchRecur(n->getRight(), key);
    }
    BinaryNode* searchIter(BinaryNode* n, int key) // 반복 구현
    {
        while (n != NULL)
        {
            if (key == n->getData())
                return n;
            else if (key < n->getData())
                n = n->getLeft();
            else
                n = n->getRight();
        }
        return NULL;
    }

    // 이진 탐색 트리의 삽입 연산
    void insert(BinaryNode* node) {...}
    void insert(BinaryNode* r, int key) {...}
    void insertRecur(BinaryNode* rootNode, BinaryNode* newNode)
    {
        if (newNode->getData() == rootNode->getData())
            return ;
        else if (newNode->getData() < rootNode->getData())
        {
            if (rootNode->getLeft() == NULL)
                rootNode->setLeft(newNode);
            else
                insertRecur(rootNode->getLeft(), newNode);
        }
        else
        {
            if (rootNode->getRight() == NULL)
                rootNode->setRight(newNode);
            else
                insertRecur(rootNode->getRight(), newNode);
        }
    }

    // 이진 탐색 트리의 삭제 연산
    void remove(int data) {...}
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
            BinaryNode* child = (node->getLeft() != NULL) ? node->getLeft() : node->getRight();
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
            BinaryNode* reparent = node; // 후계 노드의 부모 노드
            BinaryNode* replace = node->getRight(); // 후계 노드: 오른쪽 서브트리에서 가장 key가 작은 노드
            while (replace->getLeft() != NULL) // 후계 노드 찾기
            {
                reparent = replace;
                replace = replace->getLeft();
            }
            if (reparent->getLeft() == replace)
                reparent->setLeft(replace->getRight());
            else
                reparent->setRight(replace->getRight());
            node->setData(replace->getData());
            node = replace;
        }
        delete node;
    }
};