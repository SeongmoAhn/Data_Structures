// Record.h: 사전을 위한 레코드 클래스
#include <cstdio>
#include <cstring>
#define MAX_WORD_SIZE 40
#define MAX_MEANING_SIZE 200
class Record
{
private:
    char word[MAX_WORD_SIZE];
    char meaning[MAX_MEANING_SIZE];
public:
    Record(char* w = "", char* m = "") { set(w, m); }
    void set(char* w, char* m)
    {
        strcpy(word, w);
        strcpy(meaning, m);
    }
    int compare(Record* n) { return compare(n->word); }
    int compare(char* w) { return strcmp(w, word); }
    int compareMeaning(char* m) { return strcmp(meaning, m); }
    void display() { printf(" %12s: %-40s\n", word, meaning); }
    void copy(Record* n) { set(n->word, n->meaning); }
};