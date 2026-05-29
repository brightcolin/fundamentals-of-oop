#ifndef CP_CIRCLE_H
#define CP_CIRCLE_H
#include "CP_Shape.h"

class CP_Circle : public CP_Shape
{
    int m_radius;
public:
    CP_Circle(int x, int y, int r, char c);
    void mb_show();
    bool mb_isIn(int x, int y);
};

#endif