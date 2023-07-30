#include <basestringsolver.h>

class SubStringSolver : public BaseStringSolver
{
public:
    virtual ~SubStringSolver() {};

    void row_init(int i) override
    {
        m[0][i].cost = 0;
        m[0][i].parent = -1;
    }

    void goal_cell(int *i, int*j, int sLen, int jLen) override
    {
        int k;
        *i = sLen - 1;
        *j = 0;
        for(k = 1; k < jLen; k++)
        {
            if (m[*i][k].cost < m[*i][*j].cost)
            {
                *j = k;
            }
        }
    }
};
