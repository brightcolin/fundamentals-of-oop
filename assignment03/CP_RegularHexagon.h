#ifndef CP_REGULARHEXAGON_H
#define CP_REGULARHEXAGON_H

#include "CP_RegularPolygon.h"
#include <string>

class RegularHexagon : public RegularPolygon {
public:
    RegularHexagon(double side);
    std::string name() const override;
    void draw() const override;
};

#endif