#ifndef BaseStringSolver_H
#define BaseStringSolver_H
#define MATCH 0
#define INSERT 1
#define DELETE 2
#define MAXLEN 25
#include <QTextStream>
#include <cell.h>
#include <iostream>
#include <vector>

using namespace std;

class BaseStringSolver
{
public:

    Cell m[MAXLEN+1][MAXLEN+1];
    QString res;
    vector<char> bufResVector;
    int countOffset;

    QString string_compare(char *s, char *t, int sLen, int tLen);

    virtual int match(char c, char d);

    virtual void row_init(int i);

    void column_init(int i);

    virtual void goal_cell(char *s, char *t, int *i, int*j, int sLen, int tLen);

    void reconstruct_path(char *s, char *t, int i, int j);

    virtual void insert_out(char *t, int j);

    virtual void delete_out(char *s, int i);

    virtual void match_out(char *s, char *t, int i, int j);

    void PrintVector(vector<char> charVector);
};

#endif
