// SrcAMGraph.cpp
#include "SrcAMGraph.h"
int main(void)
{
    SrcAMGraph g;
    g.load("graph.txt");
    printf("๊ทธ๋ํ(graph.txt)\n");
    g.display();

    printf("DFS ==> ");
    g.resetVisted();
    g.DFS(0);
    printf("\n");

    return 0;
}