#include <iostream>

using namespace std;

int main()
{
    puts("请输入年，月，日");

	int y, m, d;
    scanf("%d %d %d", &y, &m, &d);

	if (m < 1 || m > 12)
		return puts("输入错误-月份不正确"), 0;

	int daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0))
		daysInMonth[2] = 29;

	if (d < 1 || d > daysInMonth[m])
		return puts("输入错误-日与月的关系非法"), 0;

	int ans = d;
	for (int i = 1; i < m; i++)
		ans += daysInMonth[i];

	printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, ans);

	return 0;
}