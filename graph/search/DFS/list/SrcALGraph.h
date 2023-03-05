// SrcALGraph.h
#include "AdjListGraph.h"
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
};