#ifndef SolverCreator_H
#define SolverCreator_H
#include <basestringsolver.h>

class SolverCreator
{
public:
    virtual ~SolverCreator() {}
    virtual BaseStringSolver* createSolver() const = 0;
};

#endif
