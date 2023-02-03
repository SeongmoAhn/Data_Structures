// LinkedDeque.h
#include "DBLinkedList.h"

class LinkedDeque : public DBLinkedList
{
public:
    void addFront(Node* n) { insert(0, n); }
    Node* deleteFront() { return remove(0); }
    Node* getFront() { return getEntry(0); }
    void addRear(Node* n) { insert(size(), n); }
    Node* deleteRear() { return remove(size() - 1); }
    Node* getRear() { return getEntry(size() - 1); }
};