// Node.h
#include <cstdio>

class Node
{
private:
    Node* prev;
    Node* next;
    int data;

public:
    Node(int val = 0) : data(val), prev(NULL), next(NULL) {}
    Node* getPrev() { return prev; }
    Node* getNext() { return next; }
    void setPrev(Node* p) { prev = p; }
    void setNext(Node* n) { next = n; }
    void display() { printf(" <%2d>", data); }
    bool hasData(int val) { return data == val; }
    void insertNext(Node* n)
    {
        if (n != NULL)
        {
            n->prev = this;
            n->next = next;
            if (next != NULL)
                next->prev = n;
            next = n;
        }
    }
    Node* remove()
    {
        if (prev != NULL)
            prev->next = next;
        if (next != NULL)
            next->prev = prev;
        return this;
    }
};