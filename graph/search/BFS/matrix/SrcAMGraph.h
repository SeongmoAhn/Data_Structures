// SrcAMGraph.h
#include "AdjMatGraph.h"
#include <queue>
using namespace std;
class SrcAMGraph : public AdjMatGraph
{
private:
    bool visited[MAX_VTXS];
public:
    void resetVisted()
    {
        for (int i = 0; i < size; i++)
            visited[i] = false;
    }
    bool isLinked(int u, int v) { return getEdge(u, v) != 0; }

    // DFS 함수
    void DFS(int v)
    {
        visited[v] = true;
        printf("%c ", getVertex(v));

        for (int w = 0; w < size; w++)
            if (isLinked(v, w) && visited[w] == false)
                DFS(w);
    }
    
    // BFS 함수
    void BFS(int v)
    {
        visited[v] = true;
        printf("%c ", getVertex(v));

        queue<int> que;
        que.push(v);

        while (!que.empty())
        {
            int v = que.front();
            que.pop();
            for (int w = 0; w < size; w++)
            {
                if (isLinked(v, w) && visited[w] == false)
                {
                    visited[w] = true;
                    printf("%c ", getVertex(w));
                    que.push(w);
                }
            }
        }
    }
};