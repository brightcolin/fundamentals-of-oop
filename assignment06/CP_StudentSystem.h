#ifndef CP_STUDENTSYSTEM_H
#define CP_STUDENTSYSTEM_H

#include "CP_ChainDoubleLink.h"

class CP_StudentSystem
{
public:
    CP_ChainDoubleLink *m_head;

public:
    CP_StudentSystem() : m_head(NULL) {}
    ~CP_StudentSystem() { delete m_head; }

    void mb_run();

private:
    void mb_printMainMenu()   const;
    void mb_printAllStudent() const;
};

#endif