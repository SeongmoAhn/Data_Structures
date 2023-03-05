// ConnectedComponent.cpp
#include "ConnectedComponentGraph.h"
int main(void)
{
    ConnectedComponentGraph g;
    for (int i = 0; i < 5; i++)
        g.insertVertex('A' + i);
    g.insertEdge(1, 0);
    g.insertEdge(2, 0);
    g.insertEdge(3, 4);

    printf("연결 성분 테스트 그래프\n");
    g.display();
    g.resetVisted();
    g.findConnectedComponent();

    return 0;
}