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

class BaseStringSolver
{
public:

    Cell m[MAXLEN+1][MAXLEN+1];
    QString res;

    QString string_compare(char *s, char *t);

    virtual int match(char c, char d);

    virtual void row_init(int i);

    void column_init(int i);

    virtual void goal_cell(char *s, char *t, int *i, int*j);

    void reconstruct_path(char *s, char *t, int i, int j);

    void insert_out(char *t, int j);

    void delete_out(char *s, int i);

    void match_out(char *s, char *t, int i, int j);
};

#endif
