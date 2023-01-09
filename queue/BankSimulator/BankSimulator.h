// BankSimulator.h

#include "Customer.h"
#include "CustomerQueue.h"
class BankSimulator
{
    int nSimulation;
    double probArrival;
    int tMaxService;
    int totalWaitTime;
    int nCustomers;
    int nServedCustomers;
    CircularQueue queue;

    // 랜덤 숫자를 생성해 고객 도착 여부와 서비스 시간 자동 생성
    double Random() { return rand() / (double)RAND_MAX; }
    bool IsNewCustomer() { return Random() < probArrival; }
    int RandServiceTime() { return (int)(tMaxService * Random()) + 1; }

    // 새로 도착한 고객을 큐에 삽입
    void InsertCustomer(int arrivalTime)
    {
        Customer a(++nCustomers, arrivalTime, RandServiceTime());
        printf("고객 %d 방문 (서비스 시간 : %d분)\n", a.id, a.tService);
        queue.enqueue(a);
    }

public:
    // 생성자
    BankSimulator() : nCustomers(0), totalWaitTime(0), nServedCustomers(0) { }

    // 시뮬레이션 파라미터 입력
    void readSimulationParameters()
    {
        printf("시뮬레이션 할 최대 시간 = ");
        scanf("%d", &nSimulation);
        printf("단위 시간에 도착하는 고객 수 = ");
        scanf("%lf", &probArrival);
        printf("한 고객에 대한 최대 서비스 시간 = ");
        scanf("%d", &tMaxService);
        printf("===================================================\n");
    }

    // 시뮬레이션 실행
    void run()
    {
        int clock = 0;
        int serviceTime = -1;
        while (clock < nSimulation)
        {
            clock++;
            printf("현재 시각 = %d\n", clock);

            if (IsNewCustomer())
                InsertCustomer(clock);
            
            if (serviceTime > 0)
                serviceTime--;

            else
            {
                if (queue.isEmpty())
                    continue;
                
                Customer a = queue.dequeue();
                nServedCustomers++;
                totalWaitTime += clock - a.tArrival;
                printf("고객 %d 서비스 시작 (대기 시간 : %d분)\n", a.id, clock - a.tArrival);
                serviceTime = a.tService - 1;
            }
        }
    }
     
    // 시뮬레이션 결과 출력
    void printStat()
    {
        printf("===================================================\n");
        printf("서비스 받은 고객 수 = %d\n", nServedCustomers);
        printf("전체 대기 시간 = %d분\n", totalWaitTime);
        printf("서비스 고객 평균 대기 시간 = %-5.2f분\n", (double)totalWaitTime / nServedCustomers);
        printf("현재 대기 고객 수 = %d\n", nCustomers - nServedCustomers);
    }
};