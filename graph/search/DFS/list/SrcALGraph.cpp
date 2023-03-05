// SrcALGraph.cpp
#include "SrcALGraph.h"
int main(void)
{
    SrcALGraph g;
    g.load("graph.txt");
    printf("그래프(graph.txt)\n");
    g.display();

    printf("DFS ==> ");
    g.resetVisted();
    g.DFS(0);
    printf("\n");

    return 0;
}