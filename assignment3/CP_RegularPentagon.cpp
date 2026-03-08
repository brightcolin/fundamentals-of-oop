#include "CP_RegularPentagon.h"
#include <iostream>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

RegularPentagon::RegularPentagon(double side) : RegularPolygon(5, side) {}
std::string RegularPentagon::name() const { return "Regular Pentagon"; }

void RegularPentagon::draw() const {
    int r = (int)m_side;
    double centerX = r, centerY = r;
    double vx[5], vy[5];
    for (int i = 0; i < 5; i++) {
        vx[i] = centerX + r * cos(i * 2 * M_PI / 5 - M_PI / 2);
        vy[i] = centerY + r * sin(i * 2 * M_PI / 5 - M_PI / 2);
    }

    for (int y = 0; y <= 2 * r; y++) {
        for (int x = 0; x <= 4 * r; x++) {
            double px = x / 2.0, py = y;
            bool inside = false;
            // 射线法判定点在多边形内
            for (int i = 0, j = 4; i < 5; j = i++) {
                if (((vy[i] > py) != (vy[j] > py)) &&
                    (px < (vx[j] - vx[i]) * (py - vy[i]) / (vy[j] - vy[i]) + vx[i]))
                    inside = !inside;
            }
            std::cout << (inside ? "*" : " ");
        }
        std::cout << std::endl;
    }
}