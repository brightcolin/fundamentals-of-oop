#ifndef CP_STUDENTSYSTEM_H
#define CP_STUDENTSYSTEM_H

#include "CP_StudentProduct.h"
#include "CP_StudentFactory.h"

class CP_StudentSystem
{
public:
    CP_StudentProduct m_product;   
    CP_StudentFactory m_factory;   

public:
    CP_StudentSystem() {}
    ~CP_StudentSystem() {}

    void mb_run();

private:
    void mb_printMainMenu()   const;
    void mb_printAllStudent() const;
};

#endif
