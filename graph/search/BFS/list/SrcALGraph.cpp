// SrcALGraph.cpp
#include "SrcALGraph.h"
int main(void)
{
    SrcALGraph g;
    g.load("graph.txt");
    printf("๊ทธ๋ํ(graph.txt)\n");
    g.display();

    printf("BFS ==> ");
    g.resetVisted();
    g.BFS(0);
    printf("\n");

    return 0;
}