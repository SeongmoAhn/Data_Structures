// LinkedList.h: 단순 연결 리스트 클래스
#include "Node.h"
class LinkedList
{
protected:
    Node headNode; // head Node not head pointer
public:
    LinkedList(): headNode("") {}
    ~LinkedList() { clear(); }
    void clear() { while(!isEmpty()) delete remove(0); }
    Node* getHead() { return headNode.getLink(); }
    bool isEmpty() { return getHead() == NULL; }
    Node* getEntry(int idx)
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
    Node* find(const char* str)
    {
        for (Node* cur = getHead(); cur != NULL; cur = cur->getLink())
            if (cur->hasData(str))
                return cur;
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
        int cnt = 0;
        for (Node* cur = getHead(); cur != NULL; cur = cur->getLink())
            cnt++;
        return cnt;
    }
};