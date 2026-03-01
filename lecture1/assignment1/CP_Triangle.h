#ifndef CP_TRIANGLE_H
#define CP_TRIANGLE_H
#include "CP_Shape.h"

class CP_Triangle : public CP_Shape
{
    int m_base;
    int m_height; 
    
public:
    CP_Triangle(int x, int y, int b, int h, char c);
    void mb_show();
    bool mb_isIn(int x, int y);
};

#endif