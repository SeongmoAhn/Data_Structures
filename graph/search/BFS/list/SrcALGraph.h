// SrcALGraph.h
#include "AdjListGraph.h"
#include <queue>
using namespace std;
class SrcALGraph : public AdjListGraph
{
private:
    bool visited[MAX_VTXS];
public:
    void resetVisted()
    {
        for (int i = 0; i < size; i++)
            visited[i] = false;
    }
    bool isLinked(int u, int v)
    {
        for (Node* p = adj[u]; p != NULL; p = p->getLink())
            if (p->getId() == v)
                return true;
            return false;
    }

    // DFS
    void DFS(int v)
    {
        visited[v] = true;
        printf("%c ", getVertex(v));

        for (Node* p = adj[v]; p != NULL; p = p->getLink())
            if (visited[p->getId()] == false)
                DFS(p->getId());
    }

    // BFS
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
            for (Node* w = adj[v]; w != NULL; w = w->getLink())
            {
                int id = w->getId();
                if (!visited[id])
                {
                    visited[id] = true;
                    printf("%c ", getVertex(id));
                    que.push(id);
                }
            }
        }
    }
};