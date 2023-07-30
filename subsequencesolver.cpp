#include <basestringsolver.h>

using namespace std;

class SubsequenceSolver : public BaseStringSolver
{
public:
    virtual ~SubsequenceSolver() {};

    int match(char c, char d) override
    {
        return c == d ? 0 : MAXLEN;
    }

    void insert_out(char *t, int j) override
    {
    }

    void delete_out(char *s, int i) override
    {
    }

    void match_out(char *s, char *t, int i, int j) override
    {
        if (s[i] == t[j])
        {
            bufResVector.insert(bufResVector.begin() + j, t[j]);
            res.push_back(string(1, t[j]) + ' ');
        }
    }
};
