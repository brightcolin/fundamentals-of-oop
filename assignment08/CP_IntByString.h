#ifndef CP_INTBYSTRING_H
#define CP_INTBYSTRING_H
#include <string>
using namespace std;

class CP_IntByString
{
private:
    int m_flag;       // 符号: 1为正, -1为负
    string m_data;    // 绝对值的数字串(无前导零)

    // 辅助函数: 无符号字符串加法
    static string sf_absAdd(const string &a,const string &b);
    // 辅助函数: 无符号字符串减法(要求 a >= b)
    static string sf_absSub(const string &a,const string &b);
    // 辅助函数: 无符号字符串乘法
    static string sf_absMul(const string &a,const string &b);
    // 辅助函数: 无符号字符串除法, 返回商
    static string sf_absDiv(const string &a,const string &b);
    // 辅助函数: 无符号字符串取模, 返回余数
    static string sf_absMod(const string &a,const string &b);
    // 辅助函数: 比较绝对值大小, 返回 1, 0, -1
    static int sf_absCmp(const string &a,const string &b);
    // 辅助函数: 去除前导零
    static string sf_removeLeadingZeros(const string &s);

public:
    CP_IntByString():m_flag(1){}
    CP_IntByString(const string &data,int flag=1);

    int mb_getFlag()const {return m_flag;}
    string mb_getData()const {return m_data;}

    void mb_getValue(int &flag,string &data) const;
    void mb_setValue(const string &data);
    void mb_setValue(int flag,const string &data);

    void mb_show(const char*s) const;

    // 转换为字符串(含符号)
    string mb_toString() const;

    // 运算符重载: 加法
    CP_IntByString operator+(const CP_IntByString &other) const;
    // 运算符重载: 减法
    CP_IntByString operator-(const CP_IntByString &other) const;
    // 运算符重载: 乘法
    CP_IntByString operator*(const CP_IntByString &other) const;
    // 运算符重载: 除法
    CP_IntByString operator/(const CP_IntByString &other) const;

    // 比较运算符
    bool operator==(const CP_IntByString &other) const;
    bool operator!=(const CP_IntByString &other) const;
};

#endif
