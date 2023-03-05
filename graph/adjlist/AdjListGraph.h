// AdjListGraph.h
#include "Node.h"
#include <cstdlib>
#define MAX_VTXS 256
class AdjListGraph
{
protected:
    int size;
    char vertices[MAX_VTXS];
    Node* adj[MAX_VTXS];
public:
    AdjListGraph() : size(0) {}
    ~AdjListGraph() { reset(); }
    void reset(void)
    {
        for (int i = 0; i < size; i++)
            if (adj[i] != NULL)
                delete adj[i];
            size = 0;
    }
    bool isEmpty() { return (size == 0); }
    bool isFull() { return (size >= MAX_VTXS); }
    char getVertex(int i) { return vertices[i]; }

    void insertVertex(char val)
    {
        if (!isFull())
        {
            vertices[size] = val;
            adj[size++] = NULL;
        }
        else
            printf("Error: 그래프 정점 개수 초과\n");
    }
    void insertEdge(int u, int v)
    {
        adj[u] = new Node(v, adj[u]);
        adj[v] = new Node(u, adj[v]); // 방향 그래프에서는 이 줄 불필요
    }

    void display(FILE* fp = stdout)
    {
        fprintf(fp, "%d\n", size);
        for (int i = 0; i < size; i++)
        {
            fprintf(fp, "%c ", getVertex(i));
            for (Node* v = adj[i]; v != NULL; v = v->getLink())
                fprintf(fp, " %c", getVertex(v->getId()));
            fprintf(fp, "\n");
        }
    }
    Node* adjacent(int v) { return adj[v]; }

    // 파일 입력 함수
    void load(const char* filename)
    {
        FILE* fp;
        if ((fp = fopen(filename, "r")) == NULL)
        {
            fprintf(stderr, "%s 파일을 열 수 없습니다.\n", filename);
            exit(1);
        }
        int n;
        fscanf(fp, "%d", &n);
        for (int i = 0; i < n; i++)
        {
            char str[80];
            fscanf(fp, "%s", str);
            insertVertex(str[0]);
            for (int j = 0; j < n; j++)
            {
                int val;
                fscanf(fp, "%d", &val);
                if (val != 0)
                    insertEdge(i, j);
            }
        }
        fclose(fp);
    }
    // 파일 저장 함수
    void store(const char* filename)
    {
        FILE* fp;
        if ((fp = fopen(filename, "w")) == NULL)
        {
            fprintf(stderr, "%s 파일을 열 수 없습니다.\n", filename);
            exit(1);
        }
        display(fp);
        fclose(fp);
    }
};