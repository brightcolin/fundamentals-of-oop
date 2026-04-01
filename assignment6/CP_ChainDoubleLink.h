#ifndef CP_CHAINDOUBLELINK_H
#define CP_CHAINDOUBLELINK_H

#include "CP_Student.h"

class CP_ChainDoubleLink
{
public:
    CP_Student          m_data;
    CP_ChainDoubleLink *m_previous;
    CP_ChainDoubleLink *m_next;

public:
    CP_ChainDoubleLink() : m_previous(NULL), m_next(NULL) {}
    ~CP_ChainDoubleLink();
    
    bool mb_insertSorted(CP_Student s);
    void mb_deleteNode(CP_ChainDoubleLink *p);
    void mb_deleteByScore(int score);
    CP_ChainDoubleLink* mb_findNodeById(int id);
    int mb_getNodeCount();

private:
    bool mb_insertBefore(CP_ChainDoubleLink *pos, CP_Student s);
};

#endif
