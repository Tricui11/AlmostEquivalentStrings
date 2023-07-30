#include "basestringsolver.h"

QString BaseStringSolver::string_compare(char *s, char *t, int sLen, int tLen)
{
    int i, j, k;
    int opt[3];
    bufResVector.assign(s, s + sLen);
    res.clear();
    for(i=0; i<MAXLEN; i++)
    {
        row_init(i);
        column_init(i);
    }

    for(i=1; i<sLen; i++)
    {
        for(j=1; j<tLen; j++)
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
    goal_cell(s, t, &i, &j, sLen, tLen);
    reconstruct_path(s, t, i, j);

    cout << res.toStdString() << endl;


    int sds = m[i][j].cost;

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

    void BaseStringSolver::goal_cell(char *s, char *t, int *i, int*j, int sLen, int tLen)
    {
        *i = sLen - 1;
        *j = tLen - 1;
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



        bufResVector.insert(bufResVector.begin() + j, t[j]);
        countOffset--;
        PrintVector(bufResVector);
    }

    void BaseStringSolver::delete_out(char *s, int i)
    {
        res.append("D");

        bufResVector.erase(bufResVector.begin() + i - countOffset++);
        PrintVector(bufResVector);
    }

    void BaseStringSolver::match_out(char *s, char *t, int i, int j)
    {
        if (s[i] != t[j])
        {
            res.append("S");

            bufResVector[j] = t[j];
            PrintVector(bufResVector);
        }
        else
        {
            res.append("M");
        }
    }

    void BaseStringSolver::PrintVector(vector<char> charVector)
    {
        for (char ch : charVector) {
            std::cout << ch;
        }
        std::cout << std::endl;
    }

