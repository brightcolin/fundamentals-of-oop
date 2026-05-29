#ifndef CP_NODEDOUBLELINK_H
#define CP_NODEDOUBLELINK_H

#include "CP_Student.h"

class CP_NodeDoubleLink
{
public:
    CP_Student       m_data;
    CP_NodeDoubleLink *m_previous;
    CP_NodeDoubleLink *m_next;

public:
    CP_NodeDoubleLink() : m_previous(NULL), m_next(NULL) {}
};

#endif
