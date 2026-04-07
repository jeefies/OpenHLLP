#include "testlib.h"

int main(int argc, char* argv[])
{
    registerValidation(argc, argv);

    inf.readInt(INT_MIN, INT_MAX, "y");
    inf.readSpace();
    inf.readInt(INT_MIN, INT_MAX, "m");
    inf.readSpace();
    inf.readInt(INT_MIN, INT_MAX, "d");
    inf.readEoln();
    inf.readEof();

    return 0;
}