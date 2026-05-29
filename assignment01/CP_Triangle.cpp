#include "CP_Triangle.h"
#include <iostream>

CP_Triangle::CP_Triangle(int x, int y, int b, int h, char c)
    : CP_Shape(x, y, c), m_base(b), m_height(h) {}

void CP_Triangle::mb_show()
{
    std::cout << "等腰三角形顶点：（" << m_x << "," << m_y << "）"
        << "  底边宽：" << m_base
        << "  高度：" << m_height
        << "  填充字符：" << m_char << std::endl;
}

bool CP_Triangle::mb_isIn(int x, int y) {
    int dy = y - m_y;
    if (dy >= 0 && dy < m_height) {
        int dist = (x - m_x) >= 0 ? (x - m_x) : (m_x - x); // abs
        if (2 * dist * m_height <= m_base * dy) {
            return true;
        }
    }
    return false;
}