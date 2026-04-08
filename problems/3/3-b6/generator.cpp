#include "testlib.h"

#include <cstdio>
#include <string>

using namespace std;

char randdig(bool nonZero)
{
    if (nonZero) return '0' + rnd.next(1, 9);
    else return '0';
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    int i = rnd.next(0, (1 << 12) - 1);

    string s;
    s += randdig((i >> 11) & 1);
    s += randdig((i >> 10) & 1);
    s += randdig((i >> 9) & 1);
    s += randdig((i >> 8) & 1);
    s += randdig((i >> 7) & 1);
    s += randdig((i >> 6) & 1);
    s += randdig((i >> 5) & 1);
    s += randdig((i >> 4) & 1);
    s += randdig((i >> 3) & 1);
    s += randdig((i >> 2) & 1);
    s += '.';
    s += randdig((i >> 1) & 1);
    s += randdig((i >> 0) & 1);

    while (s.size() >= 2 && s[0] == '0' && s[1] != '.')
        s.erase(s.begin());
    while (s.size() >= 2 && s.back() == '0' && s[s.size() - 2] != '.' && rnd.next(0, 1))
        s.pop_back();
    if (!s.empty() && s.back() == '.')
        s.pop_back();

    println(s);

    return 0;
}