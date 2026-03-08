#ifndef CP_REGULARPOLYGON_H
#define CP_REGULARPOLYGON_H

#include "CP_Shape.h"
#include <string>

class RegularPolygon : public Shape {
protected:
    int    m_n;
    double m_side;
public:
    RegularPolygon(int n, double side);
    double perimeter() const override;
    double area()      const override;
};

#endif