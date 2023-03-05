// WGraphMST.cpp
#include "WGraphMST.h"
int main(void)
{
    WGraphMST g;
    g.load("graph.txt");
    printf("MST By Kruskal's Algorithm\n");
    g.Kruskal();

    return 0;
}