// WGraph.h
#include "AdjMatGraph.h"
#define INF 9999 // 값이 INF 이상이면 간선이 없다고 판단
class WGraph : public AdjMatGraph
{
public:
    void insertEdge(int u, int v, int weight)
    {
        if (weight > INF)
            weight = INF;
        setEdge(u, v, weight);
    }
    bool hasEdge(int i, int j) { return (getEdge(i, j) < INF); }
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
            int val;
            fscanf(fp, "%s", str);
            insertVertex(str[0]);
            for (int j = 0; j < n; j++)
            {
                fscanf(fp, "%d", &val);
                insertEdge(i, j, val);
            }
        }
        fclose(fp);
    }
};