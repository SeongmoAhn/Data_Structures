#include "ArrayStack.h"

int main(void)
{
    ArrayStack stack;
    for (int i = 0; i < 10; i++)
        stack.push(i);
    stack.display();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.display();

    return 0;
}
/*
[Number of Stack elements : 10]
< 0>< 1>< 2>< 3>< 4>< 5>< 6>< 7>< 8>< 9>

[Number of Stack elements : 7]
< 0>< 1>< 2>< 3>< 4>< 5>< 6>
*/