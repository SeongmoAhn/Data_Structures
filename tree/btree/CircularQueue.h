// CircularQueue.h
#include "BinaryNode.h"
#include <cstdlib>
#define MAX_QUEUE_SIZE 100
inline void error(const char* errorstr)
{
    fprintf(stderr, "%s\n", errorstr);
    exit(1);
}

class CircularQueue
{
private:
    int front;
    int rear;
    BinaryNode* data[MAX_QUEUE_SIZE];
public:
    CircularQueue() { front = rear = 0; }
    bool isEmpty() { return front == rear; }
    bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }
    void enqueue(BinaryNode* n)
    {
        if (isFull())
            error(" Error: Queue is Full\n");
        else
        {
            rear = (rear + 1) % MAX_QUEUE_SIZE;
            data[rear] = n;
        }
    }
    BinaryNode* dequeue()
    {
        if (isEmpty())
        {
            error(" Error: Queue is Empty\n");
            return NULL;
        }
        else
        {
            front = (front + 1) % MAX_QUEUE_SIZE;
            return data[front];
        }
    }
};