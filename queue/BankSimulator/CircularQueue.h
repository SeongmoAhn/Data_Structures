#include <cstdio>
#include <cstdlib>
#define MAX_QUEUE_SIZE 100

inline void error(const char* str) // 오류 처리 함수
{
    fprintf(stderr, "%s\n", str);
    exit(1);
}

class CircularQueue
{
protected:
    int front;
    int rear;
    int data[MAX_QUEUE_SIZE];

public:
    CircularQueue() { front = rear = 0; }
    bool isEmpty() { return (front == rear); }
    bool isFull() { return ((rear + 1) % MAX_QUEUE_SIZE == front); }

    void enqueue(int val)
    {
        if (isFull())
            error("error : Queue is Full");

        else
        {
            rear = (rear + 1) % MAX_QUEUE_SIZE;
            data[rear] = val;
        }
    }

    int dequeue()
    {
        if (isEmpty())
            error("error : Queue is Empty");
        
        else
        {
            front = (front + 1) % MAX_QUEUE_SIZE;
            return data[front];
        }
    }

    int peek()
    {
        if (isEmpty())
            error("error : Queue is Empty");
        
        else
            return data[(front + 1) % MAX_QUEUE_SIZE];
    }

    void display()
    {
        printf("Queue : ");
        int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;

        for (int i = front + 1; i <= maxi; i++)
            printf("[%2d] ", data[i % MAX_QUEUE_SIZE]);
        printf("\n");
    }
};