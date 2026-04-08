#include "testlib.h"
#include <regex>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    registerValidation(argc, argv);

    string s = inf.readLine();
    ensure(regex_match(s, regex("\\d{1,10}(\\.\\d{1,2}){0,1}")));
    inf.readEof();

    return 0;
}