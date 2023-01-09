// CustomerQueue.h
// 큐에 저장할 데이터가 int가 아니라 Customer 객체이므로 관련 부분을 수정

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
    Customer data[MAX_QUEUE_SIZE];

public:
    CircularQueue() { front = rear = 0; }
    bool isEmpty() { return (front == rear); }
    bool isFull() { return ((rear + 1) % MAX_QUEUE_SIZE == front); }

    void enqueue(Customer val)
    {
        if (isFull())
            error("error : Queue is Full");

        else
        {
            rear = (rear + 1) % MAX_QUEUE_SIZE;
            data[rear] = val;
        }
    }

    Customer dequeue()
    {
        if (isEmpty())
            error("error : Queue is Empty");
        
        else
        {
            front = (front + 1) % MAX_QUEUE_SIZE;
            return data[front];
        }
    }

    Customer peek()
    {
        if (isEmpty())
            error("error : Queue is Empty");
        
        else
            return data[(front + 1) % MAX_QUEUE_SIZE];
    }
};