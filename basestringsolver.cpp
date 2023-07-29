#include "basestringsolver.h"

using namespace std;

QString BaseStringSolver::string_compare(char *s, char *t)
{
    int i, j, k;
    int opt[3];
    res.clear();
    for(i=0; i<MAXLEN; i++)
    {
        row_init(i);
        column_init(i);
    }

    for(i=1; i<strlen(s); i++)
    {
        for(j=1; j<strlen(t); j++)
        {
            opt[MATCH] = m[i-1][j-1].cost + match(s[i], t[j]);
            opt[INSERT] = m[i][j-1].cost + 1;
            opt[DELETE] = m[i-1][j].cost + 1;
            m[i][j].cost = opt[MATCH];
            m[i][j].parent = MATCH;
            for(k=INSERT; k<=DELETE; k++)
            {
                if(opt[k] < m[i][j].cost)
                {
                    m[i][j].cost = opt[k];
                    m[i][j].parent = k;
                }
            }
        }
    }
    goal_cell(s, t, &i, &j);
    reconstruct_path(s, t, i, j);

    cout << res.toStdString() << endl;

    return res;
}


   int BaseStringSolver::match(char c, char d)
    {
        return c == d ? 0 : 1;
    }

    void BaseStringSolver::row_init(int i)
    {
        m[0][i].cost = i;
        if (i>0) m[0][i].parent = INSERT;
        else m[0][i].parent = -1;
    }
    void BaseStringSolver::column_init(int i)
    {
        m[i][0].cost = i;
        if (i>0) m[i][0].parent = DELETE;
        else m[i][0].parent = -1;
    }

    void BaseStringSolver::goal_cell(char *s, char *t, int *i, int*j)
    {
        *i = strlen(s) - 1;
        *j = strlen(t) - 1;
    }

    void BaseStringSolver::reconstruct_path(char *s, char *t, int i, int j)
    {
        if (m[i][j].parent == -1 ) return;
        if (m[i][j].parent == MATCH)
        {
            reconstruct_path(s, t, i-1, j-1);
            match_out(s, t, i, j);
            return;
        }
        if (m[i][j].parent == INSERT)
        {
            reconstruct_path(s, t, i, j-1);
            insert_out(t, j);
            return;
        }
        if (m[i][j].parent == DELETE)
        {
            reconstruct_path(s, t, i-1, j);
            delete_out(s, i);
            return;
        }
    }

    void BaseStringSolver::insert_out(char *t, int j)
    {
        res.append("I");

//        res.append("Insert symbol %1 at %2");
//        res.append('\n');
//        res = res.arg(t[j]).arg(j);
    }

    void BaseStringSolver::delete_out(char *s, int i)
    {
        res.append("D");

//        res.append("Delete symbol %1 at %2");
//        res.append('\n');
//        res = res.arg(s[i-1]).arg(i);
    }

    void BaseStringSolver::match_out(char *s, char *t, int i, int j)
    {
        if (s[i] != t[j])
        {
            res.append("S");

//            res.append("Changel symbol %1 to %2 at %3");
//            res.append('\n');
//            res = res.arg(s[i-1]).arg(t[i-1]).arg(i);
        }
        else
        {
            res.append("M");
        }
    }

