#pragma once

class CP_Circle
{
    public:
        double m_centerX,m_centerY,m_radius;
        char m_char;

        CP_Circle(double cx=0.0,double cy=0.0,
            double r=1.0,char c='c')
            :m_centerX(cx),m_centerY(cy),m_radius(r),m_char(c){};
        ~CP_Circle(){};

        void mb_draw();
        bool mb_isIn(double x,double y);
        void mb_input();
        void mb_show();

};