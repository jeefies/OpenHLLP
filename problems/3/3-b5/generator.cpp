#include "testlib.h"

bool isLeapYear(int y)
{
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

int daysInMonth(int y, int m)
{
    static const int md[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m < 1 || m > 12) return 0;  // Invalid month
    if (m == 2 && isLeapYear(y)) return 29;
    return md[m];
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    int y = rnd.next(INT_MIN, INT_MAX);
    int m = 1;
    int d = 1;

    int t = rnd.next(1, 10);  // 80% valid, 10% invalid month, 10% invalid day
    if (t <= 8)
    {
        m = rnd.next(1, 12);
        d = rnd.next(1, daysInMonth(y, m));
    }
    else if (t <= 9)
    {
        if (rnd.next(0, 1) == 0)
            m = rnd.next(INT_MIN, 0);
        else
            m = rnd.next(13, INT_MAX);
        d = rnd.next(-15, 45);
    }
    else
    {
        m = rnd.next(1, 12);
        int lim = daysInMonth(y, m);
        if (rnd.next(0, 1) == 0)
            d = rnd.next(INT_MIN, 0);
        else
            d = rnd.next(lim + 1, INT_MAX);
    }

    println(y, m, d);

    return 0;
}