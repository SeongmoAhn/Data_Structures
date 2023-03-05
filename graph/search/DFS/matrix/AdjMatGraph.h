// AdjMatGraph.h
#include <cstdio>
#include <cstdlib>
#define MAX_VTXS 256
class AdjMatGraph
{
protected:
    int size;
    char vertices[MAX_VTXS];
    int adj[MAX_VTXS][MAX_VTXS];
public:
    AdjMatGraph() { reset(); }
    char getVertex(int i) { return vertices[i]; }
    int getEdge(int i, int j) { return adj[i][j]; }
    void setEdge(int i, int j, int val) { adj[i][j] = val; }

    bool isEmpty() { return size == 0; }
    bool isFull() { return size >= MAX_VTXS; }

    // 그래프 초기화 ==> 공백 상태의 그래프
    void reset()
    {
        size = 0;
        for (int i = 0; i < MAX_VTXS; i++)
            for (int j = 0; j < MAX_VTXS; j++)
                setEdge(i, j, 0);
    }

    // 정점 삽입 연산
    void insertVertex(char name)
    {
        if (!isFull())
            vertices[size++] = name;
        else
            printf("Error: 그래프 정점 개수 초과\n");
    }
    // 간선 삽입 연산: 무방향 그래프
    void insertEdge(int u, int v)
    {
        setEdge(u, v, 1);
        setEdge(v, u, 1); // 방향 그래프에서는 이 줄 불필요
    }

    // 그래프 정보 출력(화면 or 파일)
    void display(FILE* fp = stdout)
    {
        fprintf(fp, "%d\n", size);
        for (int i = 0; i < size; i++)
        {
            fprintf(fp, "%c ", getVertex(i));
            for (int j = 0; j < size; j++)
                fprintf(fp, " %3d", getEdge(i, j));
            fprintf(fp, "\n");
        }
    }

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