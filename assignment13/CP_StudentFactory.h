#ifndef CP_STUDENTFACTORY_H
#define CP_STUDENTFACTORY_H

#include "CP_NodeDoubleLink.h"

class CP_StudentFactory
{
public:
    CP_NodeDoubleLink *m_head;   
    int                m_count;  

public:
    CP_StudentFactory();
    ~CP_StudentFactory();
 
    CP_NodeDoubleLink* mb_getNode();
 
    void mb_returnNode(CP_NodeDoubleLink *p);
    int mb_getSpareCount() const;
    void mb_deleteAll();
};

#endif
