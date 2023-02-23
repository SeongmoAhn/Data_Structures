// ThreadedBinaryTree.h 스레드 이진트리를 위한 트리 클래스
#include "ThreadedBinaryNode.h"
#include <cstdio>
class ThreadedBinTree
{
private:
    ThreadedBinNode* root;
public:
    ThreadedBinTree(): root(NULL) {}
    void setRoot(ThreadedBinNode* node) { root = node; }
    bool isEmpty() { return root == NULL; }

    // 스레드 방식의 inorder 방문 함수
    void threadedInorder()
    {
        if (!isEmpty())
        {
            printf("Threaded Binary Tree: ");
            ThreadedBinNode* q = root;
            while (q->getLeft()) // 가장 왼쪽 단말 노드로 이동
                q = q->getLeft();
            do
            {
                printf("%c ", q->getData());
                q = findSuccessor(q); // 후속자 함수 호출
            } while (q);
            printf("\n"); 
        }
    }
    // 후속자 함수 호출
    ThreadedBinNode* findSuccessor(ThreadedBinNode* p)
    {
        ThreadedBinNode* q = p->getRight(); // 오른쪽 자식 포인터

        if (q == NULL || p->bThread) // 만약 오른쪽 포인터가 NULL이거나 스레드이면 오른쪽 포인터를 반환
            return q;

        while (q->getLeft() != NULL) // 만약 오른쪽 자식이면 다시 가장 왼쪽 단말 노드로 이동
            q = q->getLeft();
        return q;
    }
};