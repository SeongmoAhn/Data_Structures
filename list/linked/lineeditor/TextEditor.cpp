// TextEditor.cpp
#include "LineEditor.h"

void Usage()
{
    printf("[메뉴 입력] i : 입력, d : 삭제, r : 변경 , p : 출력, l : 파일 읽기, s : 파일 저장, q : 종료 => ");
}
int main(void)
{
    char command;
    LineEditor editor;
    do
    {
        Usage();
        command = getchar();
        switch (command)
        {
        case 'd':
            editor.DeleteLine();
            break;
        case 'i':
            editor.InsertLine();
            break;
        case 'r':
            editor.ReplaceLine();
            break;
        case 'l':
            editor.LoadFile("Test.txt");
            break;
        case 's':
            editor.StoreFile("Test.txt");
            break;
        case 'p':
            editor.Display();
            break;
        case 'q':
            break;
        }
    } while (command != 'q');
    return 0; 
}