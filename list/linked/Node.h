// Node.h
#include <cstdio>

class Node
{
private:
    Node* link;
    int data;

public:
    Node(int val = 0) : data(val), link(NULL) { }
    Node* getLink() { return link; }
    void setLink(Node* next) { link = next; }
    void display() { printf(" <%2d>", data); }
    bool hasData(int val) { return data == val; }
    void insertNext(Node* next)
    {
        if (next != NULL)
        {
            next->link = link;
            link = next;
        }
    }
    Node* removeNext()
    {
        Node* removed = link;
        if (removed != NULL)
            link = removed->link;
        return removed;
    }
};