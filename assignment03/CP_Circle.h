#ifndef CP_CIRCLE_H
#define CP_CIRCLE_H

#include "CP_Shape.h"
#include <string>

class Circle : public Shape {
    double m_radius;
public:
    Circle(double radius);
    double perimeter() const override;
    double area()      const override;
    std::string name() const override;
    void draw() const override;
};

#endif