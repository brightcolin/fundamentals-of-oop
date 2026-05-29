#include <iostream>
using namespace std;
#include "CP_IntByString.h"

// ======================== 构造与基本操作 ========================

CP_IntByString::CP_IntByString(const string &data,int flag)
{
    mb_setValue(flag,data);
}

void CP_IntByString::mb_getValue(int &flag,string &data) const
{
    flag=m_flag;
    data=m_data;
}

void CP_IntByString::mb_setValue(const string &data)
{
    int i;
    int n=(int)data.size();
    int s=0;
    m_flag=1;
    m_data="";
    for(i=0;i<n;i++)
    {
        switch(s)
        {
            case 0:
                if(data[i]=='+')
                {
                    s=1;
                }
                else if(data[i]=='-')
                {
                    s=1;
                    m_flag=-1;
                }
                else if(data[i]=='0')
                {
                    s=3;
                }
                else if(data[i]>='1'&&data[i]<='9')
                {
                    s=2;
                    m_data+=data[i];
                }
                break;
            case 1:
                if(data[i]=='-')
                {
                    m_flag=(m_flag==1?-1:1);
                }
                else if(data[i]=='0')
                {
                    s=3;
                }
                else if(data[i]>='1'&&data[i]<='9')
                {
                    s=2;
                    m_data+=data[i];
                }
                break;
            case 2:
                if(data[i]>='0'&&data[i]<='9')
                {
                    m_data+=data[i];
                }
                break;
             case 3:
                if(data[i]>='1'&&data[i]<='9')
                {
                    s=2;
                    m_data+=data[i];
                }
                 break;
        }
    }
}

void CP_IntByString::mb_setValue(int flag,const string &data)
{
    mb_setValue(data);
    if(flag==-1)
    {
        m_flag=(m_flag==1?-1:1);
    }
}

void CP_IntByString::mb_show(const char*s) const
{
    cout<<s;
    if(m_data.size()<=0)
    {
        cout<<"0";
        return;
    }
    if(m_flag==-1)
    {
        cout<<"-";
    }
    cout<<m_data;
}

string CP_IntByString::mb_toString() const
{
    if(m_data.size()<=0)
    {
        return "0";
    }
    string result="";
    if(m_flag==-1)
    {
        result="-";
    }
    result+=m_data;
    return result;
}

// ======================== 辅助静态函数 ========================

string CP_IntByString::sf_removeLeadingZeros(const string &s)
{
    int i=0;
    int n=(int)s.size();
    while(i<n-1&&s[i]=='0')
    {
        i++;
    }
    string result=s.substr(i);
    if(result=="0") return "";
    return result;
}

int CP_IntByString::sf_absCmp(const string &a,const string &b)
{
    // 空串视为0
    if(a.size()!=b.size())
    {
        return a.size()>b.size()?1:-1;
    }
    if(a==b) return 0;
    return a>b?1:-1;
}

// 无符号加法: a + b (均为无前导零的数字串, 空串视为0)
string CP_IntByString::sf_absAdd(const string &a,const string &b)
{
    if(a.empty()) return b;
    if(b.empty()) return a;

    string result="";
    int i=(int)a.size()-1;
    int j=(int)b.size()-1;
    int carry=0;

    while(i>=0||j>=0||carry>0)
    {
        int sum=carry;
        if(i>=0)
        {
            sum+=a[i]-'0';
            i--;
        }
        if(j>=0)
        {
            sum+=b[j]-'0';
            j--;
        }
        carry=sum/10;
        result=(char)('0'+sum%10)+result;
    }
    return sf_removeLeadingZeros(result);
}

// 无符号减法: a - b, 要求 a >= b
string CP_IntByString::sf_absSub(const string &a,const string &b)
{
    if(b.empty()) return a;
    if(a.empty()) return "";

    string result="";
    int i=(int)a.size()-1;
    int j=(int)b.size()-1;
    int borrow=0;

    while(i>=0)
    {
        int diff=(a[i]-'0')-borrow;
        if(j>=0)
        {
            diff-=(b[j]-'0');
            j--;
        }
        if(diff<0)
        {
            diff+=10;
            borrow=1;
        }
        else
        {
            borrow=0;
        }
        result=(char)('0'+diff)+result;
        i--;
    }
    return sf_removeLeadingZeros(result);
}

// 无符号乘法: a * b
string CP_IntByString::sf_absMul(const string &a,const string &b)
{
    if(a.empty()||b.empty()) return "";

    int na=(int)a.size();
    int nb=(int)b.size();
    // 用数组存储中间结果
    int *tmp=new int[na+nb]();

    for(int i=na-1;i>=0;i--)
    {
        for(int j=nb-1;j>=0;j--)
        {
            int mul=(a[i]-'0')*(b[j]-'0');
            int p1=i+j;
            int p2=i+j+1;
            int sum=mul+tmp[p2];
            tmp[p2]=sum%10;
            tmp[p1]+=sum/10;
        }
    }

    string result="";
    for(int i=0;i<na+nb;i++)
    {
        result+=(char)('0'+tmp[i]);
    }
    delete[] tmp;
    return sf_removeLeadingZeros(result);
}

// 无符号除法: a / b, 返回商
string CP_IntByString::sf_absDiv(const string &a,const string &b)
{
    if(b.empty()) return ""; // 除以0, 返回0
    if(a.empty()) return ""; // 0 / b = 0
    if(sf_absCmp(a,b)<0) return ""; // a < b, 商为0

    string quotient="";
    string remainder="";

    for(int i=0;i<(int)a.size();i++)
    {
        remainder+=a[i];
        remainder=sf_removeLeadingZeros(remainder);
        if(remainder.empty()) remainder="";

        // 试商: 找最大的d使得 b*d <= remainder
        int d=0;
        // 使用减法逐步试商
        string tmp=remainder;
        while(sf_absCmp(tmp,b)>=0)
        {
            tmp=sf_absSub(tmp,b);
            d++;
        }
        quotient+=(char)('0'+d);
        remainder=tmp;
    }
    return sf_removeLeadingZeros(quotient);
}

// 无符号取模: a % b, 返回余数
string CP_IntByString::sf_absMod(const string &a,const string &b)
{
    if(b.empty()) return "";
    if(a.empty()) return "";
    if(sf_absCmp(a,b)<0) return a;

    string remainder="";
    for(int i=0;i<(int)a.size();i++)
    {
        remainder+=a[i];
        remainder=sf_removeLeadingZeros(remainder);
        if(remainder.empty()) remainder="";

        string tmp=remainder;
        while(sf_absCmp(tmp,b)>=0)
        {
            tmp=sf_absSub(tmp,b);
        }
        remainder=tmp;
    }
    return remainder;
}

// ======================== 运算符重载 ========================

CP_IntByString CP_IntByString::operator+(const CP_IntByString &other) const
{
    CP_IntByString result;
    // 同号: 绝对值相加, 取相同的符号
    if(m_flag==other.m_flag)
    {
        result.m_data=sf_absAdd(m_data,other.m_data);
        if(result.m_data.empty())
            result.m_flag=1;
        else
            result.m_flag=m_flag;
    }
    else
    {
        // 异号: 绝对值相减, 取绝对值较大者的符号
        int cmp=sf_absCmp(m_data,other.m_data);
        if(cmp==0)
        {
            result.m_flag=1;
            result.m_data="";
        }
        else if(cmp>0)
        {
            result.m_data=sf_absSub(m_data,other.m_data);
            result.m_flag=m_flag;
        }
        else
        {
            result.m_data=sf_absSub(other.m_data,m_data);
            result.m_flag=other.m_flag;
        }
    }
    return result;
}

CP_IntByString CP_IntByString::operator-(const CP_IntByString &other) const
{
    // a - b = a + (-b)
    CP_IntByString neg;
    neg.m_data=other.m_data;
    if(other.m_data.empty())
        neg.m_flag=1;
    else
        neg.m_flag=(other.m_flag==1?-1:1);
    return (*this)+neg;
}

CP_IntByString CP_IntByString::operator*(const CP_IntByString &other) const
{
    CP_IntByString result;
    result.m_data=sf_absMul(m_data,other.m_data);
    if(result.m_data.empty())
    {
        result.m_flag=1;
    }
    else
    {
        result.m_flag=(m_flag==other.m_flag?1:-1);
    }
    return result;
}

CP_IntByString CP_IntByString::operator/(const CP_IntByString &other) const
{
    CP_IntByString result;
    result.m_data=sf_absDiv(m_data,other.m_data);
    if(result.m_data.empty())
    {
        result.m_flag=1;
    }
    else
    {
        result.m_flag=(m_flag==other.m_flag?1:-1);
    }
    return result;
}

bool CP_IntByString::operator==(const CP_IntByString &other) const
{
    // 两个0相等(不管flag)
    if(m_data.empty()&&other.m_data.empty()) return true;
    return (m_flag==other.m_flag)&&(m_data==other.m_data);
}

bool CP_IntByString::operator!=(const CP_IntByString &other) const
{
    return !(*this==other);
}
