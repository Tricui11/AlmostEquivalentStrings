#include <basestringsolver.h>
#include <solvercreator.cpp>
#include <subsequencesolver.cpp>

class SubsequenceSolverCreator : public SolverCreator
{
public:

    BaseStringSolver* createSolver() const override
    {
        return new SubsequenceSolver();
    }
};
