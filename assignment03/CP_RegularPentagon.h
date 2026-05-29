#ifndef CP_REGULARPENTAGON_H
#define CP_REGULARPENTAGON_H

#include "CP_RegularPolygon.h"
#include <string>

class RegularPentagon : public RegularPolygon {
public:
    RegularPentagon(double side);
    std::string name() const override;
    void draw() const override;
};

#endif