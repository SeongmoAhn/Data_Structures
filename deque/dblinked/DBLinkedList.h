// DBLinkedList.h
#include "Node.h"

class DBLinkedList
{
private:
    Node org; // head Node not head pointer

public:
    DBLinkedList(): org(0) {}
    ~DBLinkedList() { while (!isEmpty()) delete remove(0); }
    Node* getHead() {return org.getNext(); }
    bool isEmpty() { return getHead() == NULL; }
    Node* getEntry(int pos)
    {
        Node* n = &org;
        for (int i = -1; i < pos; i++, n = n->getNext())
            if (n == NULL)
                break;
        return n;
    }
    void insert(int pos, Node* n)
    {
        Node* prev = getEntry(pos - 1);
        if (prev != NULL)
            prev->insertNext(n);
    }
    Node* remove(int pos)
    {
        Node* n = getEntry(pos);
        return n->remove();
    }
    Node* find(int val)
    {
        for (Node* p = getHead(); p != NULL; p = p->getNext())
            if (p->hasData(val))
                return p;
        return NULL;
    }
    void replace(int pos, Node* n)
    {
        Node* prev = getEntry(pos - 1);
        if (prev != NULL)
        {
            delete prev->getNext()->remove();
            prev->insertNext(n);
        }
    }
    int size()
    {
        int count = 0;
        for (Node* p = getHead(); p != NULL; p = p->getNext())
            count++;
        return count;
    }
    void display()
    {
        printf("[덱 항목 수 = %2d]: ", size());
        for (Node* p = getHead(); p != NULL; p = p->getNext())
            p->display();
        printf("\n");
    }
    void clear() { while(!isEmpty()) delete remove(0); }
};