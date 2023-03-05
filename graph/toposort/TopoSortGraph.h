// TopoSortGraph.h
#include "AdjListGraph.h"
#include <stack>
using namespace std;
class TopoSortGraph : public AdjListGraph
{
private:
    int inDeg[MAX_VTXS];
public:
    void insertDirEdge(int u, int v)
    {
        adj[u] = new Node(v, adj[u]);
    }
    // 위상 정렬 수행
    void TopoSort()
    {
        // 모든 정점의 진입 차수를 계산
        for (int i = 0; i < size; i++)
            inDeg[i] = 0;
        for (int i = 0; i < size; i++)
        {
            Node* node = adj[i];
            while (node != NULL)
            {
                inDeg[node->getId()]++;
                node = node->getLink();
            }
        }
        // 진입 차수가 0인 정점을 스택에 삽입
        stack<int> s;
        for (int i = 0; i < size; i++)
            if (inDeg[i] == 0)
                s.push(i);

        // 위상 순서를 생성
        while (s.empty() == false)
        {
            int w = s.top();
            s.pop();
            printf(" %c ", getVertex(w));
            Node* node = adj[w];
            while (node != NULL)
            {
                int u = node->getId();
                inDeg[u]--;
                if (inDeg[u] == 0)
                    s.push(u);
                node = node->getLink();
            }
        }
        printf("\n");
    }
};