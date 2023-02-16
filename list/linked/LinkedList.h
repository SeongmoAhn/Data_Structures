// LinkedList.h
#include "Node.h"

class LinkedList
{
private:
    Node headNode; // head Node not head pointer, headNode의 idx는 -1
    // 실질적인 시작 Node의 idx는 0번임. 배열과 같음
public:
    LinkedList(): headNode(0) { }
    ~LinkedList() { clear(); }
    void clear() { while(!isEmpty()) delete remove(0); } // 0번 idx가 NULL일 때까지 Node를 삭제
    Node* getHead() { return headNode.getLink(); } // 0번 idx의 Node를 반환
    bool isEmpty() { return getHead() == NULL; } // 0번 idx가 NULL인지 검사
    Node* getEntry(int idx) // idx의 Node를 반환
    {
        Node* cur = &headNode;
        for (int i = -1; i < idx; i++, cur = cur->getLink())
            if (cur == NULL)
                break;
        return cur;
    }
    void insert(int idx, Node* newNode)
    {
        Node* prev = getEntry(idx - 1);
        if (prev != NULL)
            prev->insertNext(newNode);
    }
    Node* remove(int idx)
    {
        Node* prev = getEntry(idx - 1);
        return prev->removeNext();
    }
    Node* find(int val)
    {
        for (Node* p = getHead(); p != NULL; p = p->getLink())
            if (p->hasData(val))
                return p;
            return NULL;
    }
    void replace(int idx, Node* replaceNode)
    {
        Node* prev = getEntry(idx - 1);
        if (prev != NULL)
        {
            delete prev->removeNext();
            prev->insertNext(replaceNode);
        }
    }
    int size()
    {
        int count = 0;
        for (Node* p = getHead(); p != NULL; p = p->getLink())
            count++;
        return count;
    }
    void display()
    {
        printf("[전체 항목 수 = %2d]: ", size());
        for (Node* p = getHead(); p != NULL; p = p->getLink())
            p->display();
        printf("\n");
    }
};