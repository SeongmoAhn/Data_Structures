// LineEditor.h: 연결 리스트를 이용한 라인 편집기 클래스
#include <cstdlib>
#include "LinkedList.h"
class LineEditor: public LinkedList
{
public:
    void Display(FILE* fp = stdout)
    {
        int i = 0;
        for (Node* cur = getHead(); cur != NULL; cur = cur->getLink(), i++)
        {
            fprintf(stderr, "%3d: ", i);
            cur->print(fp);
        }
    }
    void InsertLine()
    {
        int lineNum;
        char line[MAX_CHAR_PER_LINE];
        printf(" 입력 행 번호: ");
        scanf("%d", &lineNum);
        printf(" 입력 행 내용: ");
        fflush(stdin); // enter 처리
        fgets(line, MAX_CHAR_PER_LINE, stdin);
        insert(lineNum, new Node(line));
    }
    void DeleteLine()
    {
        int lineNum;
        printf(" 삭제 행 번호: ");
        scanf("%d", &lineNum);
        delete remove(lineNum);
    }
    void ReplaceLine()
    {
        int lineNum;
        char line[MAX_CHAR_PER_LINE];
        printf(" 변경 행 번호: ");
        scanf("%d", &lineNum);
        printf(" 변경 행 내용: ");
        fflush(stdin); // enter 처리
        fgets(line, MAX_CHAR_PER_LINE, stdin);
        replace(lineNum, new Node(line));
    }
    void LoadFile(const char* fname)
    {
        FILE* fp;
        if ((fp = fopen(fname, "r")) == NULL)
        {
            fprintf(stderr, "%s 파일을 열 수 없습니다.\n", fname);
            exit(1);
        } 
        if (fp != NULL)
        {
            char line[MAX_CHAR_PER_LINE];
            while (fgets(line, MAX_CHAR_PER_LINE, fp))
                insert(size(), new Node(line));
            fclose(fp);
        }
    }
    void StoreFile(const char* fname)
    {
        FILE* fp;
        if ((fp = fopen(fname, "w")) == NULL)
        {
            fprintf(stderr, "%s 파일을 열 수 없습니다.\n", fname);
            exit(1);
        }
        if (fp != NULL)
        {
            Display(fp);
            fclose(fp);
        }
    }
};