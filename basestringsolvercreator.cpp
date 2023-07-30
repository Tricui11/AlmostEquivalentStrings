#include <basestringsolver.h>
#include <solvercreator.cpp>

class BaseStringSolverCreator : public SolverCreator
{
public:

    BaseStringSolver* createSolver() const override
    {
        return new BaseStringSolver();
    }
};
