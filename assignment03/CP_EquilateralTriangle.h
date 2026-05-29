#ifndef CP_EQUILATERALTRIANGLE_H
#define CP_EQUILATERALTRIANGLE_H

#include "CP_RegularPolygon.h"
#include <string>

class EquilateralTriangle : public RegularPolygon {
public:
    EquilateralTriangle(double side);
    std::string name() const override;
    void draw() const override;
};

#endif