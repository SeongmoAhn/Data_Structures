// Node.h
#include "Student.h"
class Node : public Student {
    Node* next;

public:
    Node(int id = 0, const char* name = "", const char* dept = "")
        : Student(id, name, dept) { next = NULL; }
    ~Node(void) { }
    Node* getLink() { return next; }
    void setLink(Node* p) { next = p; }
};
