#include "basestringsolver.h"

QString BaseStringSolver::string_compare(char *s, char *t, int sLen, int tLen)
{
    int i, j, k;
    int opt[3];
    bufResVector.assign(s, s + sLen);
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
    goal_cell(&i, &j, sLen, tLen);
    reconstruct_path(s, t, i, j);

    QString result;
    for (const auto& str : res)
    {
        result.append(QString::fromStdString(str));
    }
    return result;
}

int BaseStringSolver::match(char c, char d)
{
    return c == d ? 0 : 1;
}

void BaseStringSolver::row_init(int i)
{
    m[0][i].cost = i;    
    m[0][i].parent = i>0 ? INSERT : -1;
}

void BaseStringSolver::column_init(int i)
{
    m[i][0].cost = i;
    m[i][0].parent = i>0 ? DELETE : -1;
}

void BaseStringSolver::goal_cell(int *i, int*j, int sLen, int tLen)
{
    *i = sLen - 1;
    *j = tLen - 1;
}

void BaseStringSolver::reconstruct_path(char *s, char *t, int i, int j)
{
    if (m[i][j].parent == -1 ) { return; }
    else if (m[i][j].parent == MATCH)
    {
        reconstruct_path(s, t, i-1, j-1);
        match_out(s, t, i, j);
        return;
    }
    else if (m[i][j].parent == INSERT)
    {
        reconstruct_path(s, t, i, j-1);
        insert_out(t, j);
        return;
    }
    else if (m[i][j].parent == DELETE)
    {
        reconstruct_path(s, t, i-1, j);
        delete_out(s, i);
        return;
    }
}

void BaseStringSolver::insert_out(char *t, int j)
{
    countOffset--;
    bufResVector.insert(bufResVector.begin() + j, t[j]);
    res.push_back(string(bufResVector.begin(), bufResVector.end()) + '\n');
}

void BaseStringSolver::delete_out(char *s, int i)
{
    bufResVector.erase(bufResVector.begin() + i - countOffset++);
    res.push_back(string(bufResVector.begin(), bufResVector.end()) + '\n');
}

void BaseStringSolver::match_out(char *s, char *t, int i, int j)
{
    if (s[i] != t[j])
    {
        bufResVector[j] = t[j];
        res.push_back(string(bufResVector.begin(), bufResVector.end()) + '\n');
    }
}
