// Node.h: 연결 리스트를 위한 노드 클래스
#include "Line.h"
class Node : public Line{
private:
    Node* next;
public:
    Node(const char* str = ""): Line(str), next(NULL) {}
    void setLink(Node* newNode) { next = newNode; }
    Node* getLink() { return next; }
    void insertNext(Node* newNode)
    {
        if (newNode != NULL)
        {
            newNode->next = next;
            next = newNode;
        }
    }
    Node* removeNext()
    {
        Node* removed = next;
        if (removed != NULL)
            next = removed->next;
        return removed;
    }
};