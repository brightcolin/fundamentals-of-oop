#include<iostream>
using namespace std;
#include"CP_Circle.h"

void CP_Circle::mb_draw()
{
    int minX=(int)(m_centerX-m_radius);
    int maxX=(int)(m_centerX+m_radius);
    int minY=(int)(m_centerY-m_radius);
    int maxY=(int)(m_centerY+m_radius);
    if(minX>maxX)
        swap(minX,maxX);
    if(minY>maxY)
        swap(minY,maxY);

    int i,j;
    for(j=0;j<minY;j++)
        cout<<endl;
    for(;j<=maxY;j++)
    {
        for(i=0;i<minX;i++)
            cout<<" ";
        for(;i<=maxX;i++)
        {
            if(mb_isIn(i,j))
                cout<<m_char;
            else cout<<" ";
        }
        cout<<endl;
    }
}

bool  CP_Circle::mb_isIn(double x,double y)
{
    double dx=x-m_centerX;
    double dy=y-m_centerY;
    if(dx*dx+dy*dy>m_radius*m_radius)
        return false;
    return true;
}

void CP_Circle::mb_input()
{
    cout<<"请输入圆盘的圆心坐标、半径和填充的字符：";
    cin>>m_centerX>>m_centerY>>m_radius>>m_char;
    cout<<"输入的";
    mb_show();
}

void CP_Circle::mb_show()
{
    cout<<"圆盘的圆心坐标是("<<m_centerX<<","<<m_centerY<<"),";
    cout<<"半径是"<<m_radius<<",";
    cout<<"填充的字符是"<<m_char<<"."<<endl;
    
}