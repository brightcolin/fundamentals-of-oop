#include "CP_Circle.h"
#include <iostream>

CP_Circle::CP_Circle(int x, int y, int r, char c) :
    CP_Shape(x, y, c), m_radius(r) {}

void CP_Circle::mb_show()
{
    std::cout << "圆形圆心：（" << m_x << "," << m_y << "）"
        << "  圆形半径：" << m_radius
        << "  填充字符：" << m_char << std::endl;
}

bool CP_Circle::mb_isIn(int x, int y) {
    int dx = x - m_x;
    int dy = y - m_y;
    if (dx * dx + dy * dy <= m_radius * m_radius) {
        return true;
    }
    return false;
}