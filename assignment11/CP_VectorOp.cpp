#include <iostream>
#include <algorithm>
#include <numeric>
#include <random>
#include <execution>
using namespace std;
#include "CP_VectorOp.h"

void CP_VectorOp::mb_generate(int n)
{
    m_n=n;
    m_v1.resize(n);
    m_v2.resize(n);

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dist(-100.0f,100.0f);

    m_s=dist(gen);

    generate(m_v1.begin(),m_v1.end(),[&]()->float{
        return dist(gen);
    });

    generate(m_v2.begin(),m_v2.end(),[&]()->float{
        return dist(gen);
    });
}

vector<float> CP_VectorOp::mb_scalarMul() const
{
    vector<float> result(m_n);
    
    transform(m_v1.begin(),m_v1.end(),result.begin(),
        [this](float x)->float{
            return m_s*x;
        });
    return result;
}

vector<float> CP_VectorOp::mb_scalarMulPar() const
{
    vector<float> result(m_n);
    float s=m_s;
    
    transform(execution::par,m_v1.begin(),m_v1.end(),result.begin(),
        [s](float x)->float{
            return s*x;
        });
    return result;
}

float CP_VectorOp::mb_dotProduct() const
{
    
    float result=transform_reduce(
        m_v1.begin(),m_v1.end(),
        m_v2.begin(),
        0.0f,
        [](float a,float b)->float{ return a+b; },
        [](float a,float b)->float{ return a*b; }
    );
    return result;
}

float CP_VectorOp::mb_dotProductPar() const
{
    float result=transform_reduce(
        execution::par,
        m_v1.begin(),m_v1.end(),
        m_v2.begin(),
        0.0f,
        [](float a,float b)->float{ return a+b; },
        [](float a,float b)->float{ return a*b; }
    );
    return result;
}

void CP_VectorOp::mb_show() const
{
    cout<<"n = "<<m_n<<", s = "<<m_s<<endl;
    if(m_n<=20)
    {
        sb_showVector("v1",m_v1);
        sb_showVector("v2",m_v2);
    }
    else
    {
        cout<<"(vectors too large to display, showing first 5 elements)"<<endl;
        cout<<"v1: ";
        for(int i=0;i<5&&i<m_n;i++) cout<<m_v1[i]<<" ";
        cout<<"..."<<endl;
        cout<<"v2: ";
        for(int i=0;i<5&&i<m_n;i++) cout<<m_v2[i]<<" ";
        cout<<"..."<<endl;
    }
}

void CP_VectorOp::sb_showVector(const string &name,const vector<float> &v)
{
    int n=(int)v.size();
    cout<<name<<" ("<<n<<" elements): ";
    int show=(n<20?n:20);
    for(int i=0;i<show;i++)
        cout<<v[i]<<" ";
    if(n>20) cout<<"...";
    cout<<endl;
}

void CP_VectorOp::mb_setData(float s,const vector<float> &v1,const vector<float> &v2)
{
    m_s=s;
    m_v1=v1;
    m_v2=v2;
    m_n=(int)v1.size();
}
