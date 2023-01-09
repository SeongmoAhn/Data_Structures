#include "CircularQueue.h"

class CircularDeque : public CircularQueue
{
public:
    CircularDeque() { }

    void addRear(int val) { enqueue(val); }
    int deleteFront() { return dequeue(); }
    int getFront() { return peek(); }
    void addFront(int val)
    {
        if (isFull())
            error("error : Deque is Full\n");
        
        else
        {
            data[front] = val;
            front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
        }
    }
    int deleteRear()
    {
        if (isEmpty())
            error("error : Deque is Empty\n");
        
        else
        {
            int ret = data[rear];
            rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
            return ret;
        }
    }
    int getRear()
    {
        if (isEmpty())
            error("error : Deque is Empty\n");

        else
            return data[rear];
    }
    void display()
    {
        printf("Deque : ");
        int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
        for (int i = front + 1; i <= maxi; i++)
            printf("[%2d] ", data[i % MAX_QUEUE_SIZE]);
        printf("\n");
    }
};