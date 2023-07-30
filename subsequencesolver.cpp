#include <basestringsolver.h>

using namespace std;

class SubsequenceSolver : public BaseStringSolver
{
public:

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
            res.append(s[i]);
            res.append(' ');
        }
    }
};
