#include <basestringsolver.h>

using namespace std;

class SubStringSolver : public BaseStringSolver
{
public:

    int match(char c, char d) override
    {
        return c == d ? 0 : MAXLEN;
    }
};
