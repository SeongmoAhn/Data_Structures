// ArrayList.h
#include <cstdio>
#include <cstdlib>
#define MAX_LIST_SIZE 100

void error(const char *errorstr) // 에러 문장 출력 함수
{
    fprintf(stderr, "%s\n", errorstr);
    exit(1);
}

class ArrayList
{
private: // data, length 변수의 정보 은닉을 위해 private으로
    int data[MAX_LIST_SIZE];
    int length; // 현재 리스트 내의 항목 개수 정보
public:
    ArrayList(void) { length = 0; } // 리스트 생성 시 항목 수 0으로 초기화

    void insert(int pos, int x)
    {
        if (!isFull() && pos >= 0 && pos <= length)
        {
            for (int i = length; i > pos; i--) // 데이터를 넣기 위해 요소들을 한 칸씩 뒤로 밀기
                data[i] = data[i - 1];
            data[pos] = x;
            length++;
        }
        else
            error("포화상태 오류 또는 삽입 위치 오류\n");
    }
    void remove(int pos) // 반환하지 않고 삭제만 하는 함수
    {
        if (!isEmpty() && pos >= 0 && pos < length)
        {
            for (int i = pos + 1; i < length; i++) // 삭제할 요소 뒤에 요소들을 한 칸씩 앞으로 당기기
                data[i - 1] = data[i];
            length--;
        }
        else
            error("공백상태 오류 또는 삭제 위치 오류\n");
    }
    int getEntry(int pos) { return data[pos]; }
    bool isEmpty() { return length == 0; }
    bool isFull() { return length == MAX_LIST_SIZE; }
    bool find(int item)
    {
        for (int i = 0; i < length; i++)
            if (data[i] == item)
                return true;

            return false;
    }
    void replace(int pos, int x) { data[pos] = x; }
    int size() { return length; }
    void display()
    {
        printf("[배열로 구현한 리스트 전체 항목 수 = %2d]: ", size());
        for (int i = 0; i < size(); i++)
            printf("[%2d] ", data[i]);
        printf("\n");
    }
    void clear() { length = 0; }
};