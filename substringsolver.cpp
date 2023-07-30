#include <basestringsolver.h>

using namespace std;

class SubStringSolver : public BaseStringSolver
{
public:

    void row_init(int i) override
    {
        m[0][i].cost = 0;
        m[0][i].parent = -1;
    }

    void goal_cell(char *s, char *t, int *i, int*j, int sLen, int jLen) override
    {
        int k;
        *i = strlen(s) - 1;
        *j = 0;
        for(k = 1; k < strlen(t); k++)
        {
            if (m[*i][k].cost < m[*i][*j].cost)
            {
                *j = k;
            }
        }
    }
};
