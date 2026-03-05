#ifndef CP_RECT_H
#define CP_RECT_H
#include "CP_Shape.h"

class CP_Rect : public CP_Shape
{
    int m_width, m_height;
public:
    CP_Rect(int x, int y, int w, int h, char c);
    void mb_show();
    bool mb_isIn(int x, int y);
};

#endif