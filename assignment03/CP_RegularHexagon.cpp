#include "CP_RegularHexagon.h"
#include <iostream>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

RegularHexagon::RegularHexagon(double side)
    : RegularPolygon(6, side) {}

std::string RegularHexagon::name() const {
    return "Regular Hexagon";
}

void RegularHexagon::draw() const {
    int size = (int)(m_side * 1.5);
    double centerX = size, centerY = size;
    double radius = m_side;

    double vx[6], vy[6];
    for (int i = 0; i < 6; i++) {
        vx[i] = centerX + radius * cos(i * 2 * M_PI / 6);
        vy[i] = centerY + radius * sin(i * 2 * M_PI / 6);
    }

    for (int y = 0; y <= size * 2; y++) {
        for (int x = 0; x <= size * 4; x++) {
            double px = x / 2.0, py = y;
            bool inside = false;
            for (int i = 0, j = 5; i < 6; j = i++) {
                if (((vy[i] > py) != (vy[j] > py)) &&
                    (px < (vx[j] - vx[i]) * (py - vy[i]) / (vy[j] - vy[i]) + vx[i])) {
                    inside = !inside;
                }
            }
            std::cout << (inside ? "*" : " ");
        }
        std::cout << std::endl;
    }
}