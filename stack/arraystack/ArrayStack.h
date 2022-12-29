#include <cstdio>
#include <cstdlib>
const int MAX_STACK_SIZE = 20;

class ArrayStack
{
    int top;
    int data[MAX_STACK_SIZE];

public:
    ArrayStack() { top = -1; }
    ~ArrayStack() {}
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == (MAX_STACK_SIZE - 1); }

    void push(int x)
    {
        if (isFull())
        {
            fprintf(stderr, "Stack is Full\n");
            exit(1);
        }
        data[++top] = x;
    }

    int pop()
    {
        if (isEmpty())
        {
            fprintf(stderr, "Stack is Empty\n");
            exit(1);
        }
        return data[top--];
    }

    int peek()
    {
        if (isEmpty())
        {
            fprintf(stderr, "Stack is Empty\n");
            exit(1);
        }
        return data[top];
    }

    void display()
    {
        printf("[Number of Stack elements : %d]\n", top + 1);
        for (int i = 0; i <= top; i++)
            printf("<%2d>", data[i]);
        printf("\nn");
    }
};