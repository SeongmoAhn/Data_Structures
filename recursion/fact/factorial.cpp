#include <cstdio>

// 재귀를 이용한 팩토리얼 함수
int fact_rec(int n)
{
    if (n == 1)
        return 1;
    else
        return (n * fact_rec(n - 1));
}

// 반복을 이용한 팩토리얼 함수
int fact_iter(int n)
{
    int result = 1;
    for (int i = 1; i <= n; i++)
        result *= i;
    return result;
}

int main(void)
{
    printf("fact_rec(10): %d\n", fact_rec(10));
    printf("fact_iter(10): %d\n", fact_iter(10));
    return 0;
}