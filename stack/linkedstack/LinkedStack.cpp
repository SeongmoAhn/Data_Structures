// LinkedStack.cpp
#include "LinkedStack.h"
int main(void)
{
    LinkedStack stack;
    stack.push(new Node(32091824, "seongmo", "cs"));
    stack.push(new Node(84781034, "sesang", "commercial"));
    stack.push(new Node(85729381, "yoonsung", "math"));
    stack.display();

    Node* node = stack.pop();
    printf("[Pop]\n");
    node->display();
    printf("\n");
    delete node;
    stack.display();

    return 0;
}
