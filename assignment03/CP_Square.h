#ifndef CP_SQUARE_H
#define CP_SQUARE_H

#include "CP_RegularPolygon.h"
#include <string>

class Square : public RegularPolygon {
public:
    Square(double side);
    std::string name() const override;
    void draw() const override;
};

#endif