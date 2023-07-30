#include <basestringsolver.h>
#include <solvercreator.cpp>
#include <substringsolver.cpp>

class SubStringSolverCreator : public SolverCreator
{
public:

    BaseStringSolver* createSolver() const override
    {
        return new SubStringSolver();
    }
};
