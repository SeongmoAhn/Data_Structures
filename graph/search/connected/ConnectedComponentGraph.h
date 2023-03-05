// ConnectedComponentGraph.h
#include "SrcAMGraph.h"
class ConnectedComponentGraph : public SrcAMGraph
{
private:
    int label[MAX_VTXS];
public:
    // DFS
    void labelDFS(int v, int color)
    {
        visited[v] = true;
        label[v] = color;
        for (int w = 0; w < size; w++)
        {
            if (isLinked(v, w) && visited[w] == false)
                labelDFS(w, color);
        }
    }
    // 그래프의 연결 성분 검출 함수
    void findConnectedComponent()
    {
        int cnt = 0;
        for (int i = 0; i < size; i++)
            if (visited[i] == false)
                labelDFS(i, ++cnt);
            printf("그래프 연결성분 개수 = %d\n", cnt);
            for (int i = 0; i < size; i++)
                printf("%c=%d ", getVertex(i), label[i]);
            printf("\n");
    }
};