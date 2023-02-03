// LinkedStack.cpp
#include "LinkedStack.h"

int main(void)
{
    LinkedStack stack;
    stack.push(new Node(203491723, "안성모", "컴퓨터학부"));
    stack.push(new Node(123743908, "이세상", "경제학과"));
    stack.push(new Node(891720439, "이윤성", "컴퓨터공학과"));
    stack.display();

    Node* node = stack.pop();
    printf("Pop\n");
    node->display();
    printf("\n");
    delete node;
    stack.display();

    return 0;
}