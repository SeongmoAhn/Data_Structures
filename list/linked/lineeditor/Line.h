// Line.h: 한 줄의 문장을 저장하고 처리하는 항목 클래스
#include <cstdio>
#include <cstring>
#define MAX_CHAR_PER_LINE 1000
class Line
{
private:
    char data[MAX_CHAR_PER_LINE];
public:
    Line(const char* line = "") { strcpy(data, line); }
    void print(FILE* fp = stdout) { fprintf(fp, "%s", data); } // data 출력
    bool hasData(const char* str) { return !strcmp(str, data); } // str과 data가 같으면 1반환
};