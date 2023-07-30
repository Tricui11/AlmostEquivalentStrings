#ifndef BaseStringSolver_H
#define BaseStringSolver_H
#define MATCH 0
#define INSERT 1
#define DELETE 2
#define MAXLEN 25
#include <QTextStream>
#include <cell.cpp>
#include <iostream>
#include <vector>

using namespace std;

class BaseStringSolver
{
public:
    Cell m[MAXLEN+1][MAXLEN+1];
    vector<char> bufResVector;
    vector<string> res;
    int countOffset;

    virtual ~BaseStringSolver() {}

    QString string_compare(char *s, char *t, int sLen, int tLen);

    virtual void row_init(int i);

    void column_init(int i);

    virtual int match(char c, char d);

    virtual void goal_cell(int *i, int*j, int sLen, int tLen);

    void reconstruct_path(char *s, char *t, int i, int j);

    virtual void insert_out(char *t, int j);

    virtual void delete_out(char *s, int i);

    virtual void match_out(char *s, char *t, int i, int j);
};

#endif
