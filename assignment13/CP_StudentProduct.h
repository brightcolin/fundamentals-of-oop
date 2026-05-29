#ifndef CP_STUDENTPRODUCT_H
#define CP_STUDENTPRODUCT_H

#include "CP_NodeDoubleLink.h"
#include "CP_StudentFactory.h"

class CP_StudentProduct
{
public:
    CP_NodeDoubleLink *m_head;   

public:
    CP_StudentProduct();
    ~CP_StudentProduct();

    bool mb_insertSorted(CP_Student s, CP_StudentFactory &factory);
    bool mb_deleteById(int id, CP_StudentFactory &factory);
    int  mb_deleteByScore(int score, CP_StudentFactory &factory);
    CP_NodeDoubleLink* mb_findNodeById(int id);
    int mb_getNodeCount();  
    bool mb_isEmpty() const;
    void mb_deleteAll(CP_StudentFactory &factory);
};

#endif
