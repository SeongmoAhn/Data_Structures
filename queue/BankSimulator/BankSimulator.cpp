// BankSimulator.cpp

#include <ctime>
#include "BankSimulator.h"

int main(void)
{
    srand((unsigned int)time(NULL));
    BankSimulator sim;
    sim.readSimulationParameters();
    sim.run();
    sim.printStat();

    return 0;
}