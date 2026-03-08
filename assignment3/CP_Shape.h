#ifndef CP_SHAPE_H
#define CP_SHAPE_H

#include <string>

class Shape {
public:
    virtual double perimeter() const = 0;
    virtual double area()      const = 0;
    virtual std::string name() const = 0;
    virtual void draw()        const = 0;
    virtual ~Shape() {}
};

#endif