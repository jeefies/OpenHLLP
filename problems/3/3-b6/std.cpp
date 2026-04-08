#include <iostream>
#include <cmath>

using namespace std;

const string c_digit[] = {"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};
const string c_shi = "拾", c_bai = "佰", c_qian = "仟";
const string c_yi = "亿", c_wan = "万", c_yuan = "圆", c_jiao = "角", c_fen = "分", c_zheng = "整";

string convert4(int x, const string suffix = "") // 将0-9999的数字转换为大写，并添加后缀
{
    if (x == 0) return "";
    string res;
    if (x >= 1000)
        res += c_digit[x / 1000] + c_qian, x %= 1000;
    else
        res += c_digit[0];
    if (x >= 100)
        res += c_digit[x / 100] + c_bai, x %= 100;
    else if (res.compare(res.length() - 2, 2, c_digit[0]) != 0)
        res += c_digit[0];
    if (x >= 10)
        res += c_digit[x / 10] + c_shi, x %= 10;
    else if (res.compare(res.length() - 2, 2, c_digit[0]) != 0)
        res += c_digit[0];
    if (x > 0)
        res += c_digit[x];
    if (res.compare(res.length() - 2, 2, c_digit[0]) == 0)
        res = res.substr(0, res.length() - 2);
    return res + suffix;
}

string convert2(int x) // 转换角分部分
{
    if (x == 0) return c_zheng;
    else if (x % 10 == 0) return c_digit[x / 10] + c_jiao + c_zheng;
    else if (x >= 10) return c_digit[x / 10] + c_jiao + c_digit[x % 10] + c_fen;
    else return c_digit[0] + c_digit[x] + c_fen;
}

int main()
{
    puts("请输入[0-100亿)之间的数字:");
    double xlf;
    cin >> xlf;
    long long x = llround(xlf * 100);

    // 不存在的段不输出，存在的段输出对应的数字和单位，每段千位如为零则加前缀零
    string ans = convert4(x / 10000000000, c_yi) + convert4(x / 1000000 % 10000, c_wan) + convert4(x / 100 % 10000) + c_yuan + convert2(x % 100);

    if (ans.compare(0, 2, c_yuan) == 0) ans = ans.substr(2);  // 处理金额小于 ￥1 的情况
    if (ans.compare(0, 2, c_digit[0]) == 0) ans = ans.substr(2);  // 去除开头的前缀零
    if (ans == c_zheng) ans = c_digit[0] + c_yuan + c_zheng;  // 处理输入为0的情况

    cout << "大写结果是:" << endl;
    cout << ans << endl;

    return 0;
}