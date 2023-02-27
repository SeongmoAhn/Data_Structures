// BinSrcTree.h
#include "BinaryTree.h"
class BinSrcTree : public BinaryTree
{
public:
    // 이진 탐색 트리의 탐색 연산
    BinaryNode* search(int key)
    {
        BinaryNode* node = searchRecur(root, key);
        if (node != NULL)
            printf("탐색 성공: 키 값이 %d인 노드 = x%p\n", node->getData(), node);
        else
            printf("탐색 실페: 키 값이 %d인 노드 없음\n", key);
        return node;
    }
    BinaryNode* searchRecur(BinaryNode* n, int key)
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

    // 이진 탐색 트리의 삽입 연산
    void insert(BinaryNode* n)
    {
        if (n == NULL)
            return ;
        if (isEmpty())
            root = n;
        else
            insertRecur(root, n);
    }
    void insertRecur(BinaryNode* rootNode, BinaryNode* n)
    {
        if (n->getData() == rootNode->getData())
            return ;
        else if (n->getData() < rootNode->getData())
        {
            if (rootNode->getLeft() == NULL)
                rootNode->setLeft(n);
            else
                insertRecur(rootNode->getLeft(), n);
        }
        else
        {
            if (rootNode->getRight() == NULL)
                rootNode->setRight(n);
            else
                insertRecur(rootNode->getRight(), n);    
        }
    }

    // 이진 탐색 트리의 삭제 연산
    void remove(int key)
    {
        if (isEmpty())
            return ;
        
        // 없앨 노드와 그 노드의 부모 노드 찾기
        BinaryNode* parent = NULL;
        BinaryNode* delNode = root;
        while (delNode != NULL & delNode->getData() != key)
        {
            parent = delNode;
            delNode = (key < delNode->getData())
                    ? delNode->getLeft() : delNode->getRight();
        }
        // 없앨 노드가 트리에 없는 경우
        if (delNode == NULL)
        {
            printf("Error: key is not in the tree\n");
            return ;
        }
        else // 없앨 노드가 트리에 있는 경우
            remove(parent, delNode);
    }
    void remove(BinaryNode* parent, BinaryNode* delNode)
    {
        // case1
        if (delNode->isLeaf())
        {
            if (parent == NULL)
                root = NULL;
            else
            {
                if (parent->getLeft() == delNode)
                    parent->setLeft(NULL);
                else
                    parent->setRight(NULL);
            }
        }
        // case2
        else if (delNode->getLeft() == NULL || delNode->getRight() == NULL)
        {
            BinaryNode* child = (delNode->getLeft() != NULL)
                    ? delNode->getLeft() : delNode->getRight();
            if (delNode == root)
                root = child;
            else
            {
                if (parent->getLeft() == delNode)
                    parent->setLeft(child);
                else
                    parent->setRight(child);    
            }
        } 
        // case3
        else
        {
            BinaryNode* replace = delNode->getRight(); // 후계 노드
            BinaryNode* reParent = delNode; // 후계노드 부모노드
            while (replace->getLeft() != NULL)
            {
                reParent = replace;
                replace = replace->getLeft();
            }
            if (reParent->getLeft()  == replace)
                reParent->setLeft(replace->getRight());
            else
                reParent->setRight(replace->getRight());
            delNode->setData(replace->getData());
            delNode = replace;
        }
        delete delNode; 
    }
};