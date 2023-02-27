// MaxHeap.h
#include "HeapNode.h"
#define MAX_ELEMENT 200
class MaxHeap
{
private:
    HeapNode node[MAX_ELEMENT];
    int size;
public:
    MaxHeap() : size(0) {}
    bool isEmpty() { return size == 0; }
    bool isFull() { return size == MAX_ELEMENT - 1; }

    HeapNode& getParent(int i) { return node[i / 2]; }
    HeapNode& getLeft(int i) { return node[i * 2]; }
    HeapNode& getRight(int i) { return node[i * 2 + 1]; }

    void insert(int key)
    {
        if (isFull()) return; // 힙이 가득 차면 노드 삽입 불가
        int i = ++size; // 노드 삽입을 위해 인덱스 증가

        // 트리를 거슬러 올라가면서 부모 노드와 비교
        while (i != 1 && key > getParent(i).getKey())
        {
            node[i] = getParent(i); // 부모 노드만 끌어 내림
            i /= 2; // 삽입할 위치로 인덱스만 변경
        }
        node[i].setKey(key); // 최종 위치에 키 값만 복사
    }
    HeapNode remove()
    {
        if (isEmpty()) return NULL;
        HeapNode item = node[1]; // 루트 노드(삭제할 요소)
        HeapNode last = node[size--]; // 힙 트리의 마지막 노드
        int parent = 1; // 마지막 노드의 위치를 루트로 생각함
        int child = 2; // 루트의 왼쪽 자식 인덱스
        while (child <= size) // 힙 트리를 벗어나지 않는 동안 반복
        {
            if (child < size // 현재 노드의 자식 노드 중 더 큰 자식 노드를 찾음
                && getLeft(parent).getKey() < getRight(parent).getKey())
                child++; // 오른쪽 자식노드가 더 큰 경우

            // 마지막 노드가 자식노드보다 크면 위치 찾기 완료
            if (last.getKey() >= node[child].getKey())
                break;
            // 아직 위치를 못찾았다면, 한 단계 아래로 이동
            node[parent] = node[child];
            parent = child;
            child *= 2;
        }
        node[parent] = last; // 마지막 노드를 최종 위치에 저장
        return item; // 삭제하려 했던 루트 노드 반환
    }
    HeapNode find() { return node[1]; }

    void display()
    {
        for (int i = 1, level = 1; i <= size; i++)
        {
            if (i == level)
            {
                printf("\n");
                level *= 2;
            }
            node[i].display();
        }
        printf("\n-----------------------------");
    }
};