#include "CP_Rect.h"
#include <iostream>

CP_Rect::CP_Rect(int x, int y, int w, int h, char c) :
    CP_Shape(x, y, c), m_width(w), m_height(h) {}

void CP_Rect::mb_show()
{
    std::cout << "矩形左上角：（" << m_x << "," << m_y << "）"
        << "  矩形宽：" << m_width
        << "  矩形高：" << m_height
        << "  填充字符：" << m_char << std::endl;
}

bool CP_Rect::mb_isIn(int x, int y) {
    if (x >= m_x && x < (m_x + m_width)
        && y >= m_y && y < (m_y + m_height))
    {
        return true;
    }
    return false;
}