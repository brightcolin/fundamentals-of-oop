#include <iostream>
#include <new>
using namespace std;

#include "CP_ChainDoubleLink.h"

CP_ChainDoubleLink::~CP_ChainDoubleLink()
{
    if (m_previous == NULL) return;
    m_previous->m_next = NULL;   
    delete m_next;               
}


bool CP_ChainDoubleLink::mb_insertBefore(CP_ChainDoubleLink *pos, CP_Student s)
{
    CP_ChainDoubleLink *pNew = new(nothrow) CP_ChainDoubleLink;
    if (pNew == NULL) return false;

    pNew->m_data          = s;
    pNew->m_next          = pos;
    pNew->m_previous      = pos->m_previous;
    pos->m_previous->m_next = pNew;
    pos->m_previous       = pNew;
    return true;
}

bool CP_ChainDoubleLink::mb_insertSorted(CP_Student s)
{
    
    if (m_previous == NULL)
    {
        m_previous = this;
        m_next     = this;
        m_data     = s;
        return true;
    }

    
    if (s.m_ID < m_data.m_ID)
    {
        if (!mb_insertBefore(m_next, m_data)) return false;  
        m_data = s;                                           
        return true;
    }

    
    CP_ChainDoubleLink *pos = m_next;
    while (pos != this && pos->m_data.m_ID <= s.m_ID)
        pos = pos->m_next;

    return mb_insertBefore(pos, s);
}


void CP_ChainDoubleLink::mb_deleteNode(CP_ChainDoubleLink *p)
{
    if (m_previous == NULL) return;

    if (p == this)                     
    {
        if (p->m_previous == this)     
        {
            p->m_previous = NULL;
            return;
        }
        m_data = p->m_next->m_data;   
        p      = p->m_next;           
    }
   
    p->m_previous->m_next = p->m_next;
    p->m_next->m_previous = p->m_previous;
    p->m_previous         = p;         
    delete p;
}

void CP_ChainDoubleLink::mb_deleteByScore(int score)
{
    if (m_previous == NULL) return;

    
    while (m_previous != NULL && m_data.m_score == score)
        mb_deleteNode(this);

    if (m_previous == NULL) return;   

    
    CP_ChainDoubleLink *p = m_next;
    while (p != this)
    {
        CP_ChainDoubleLink *next = p->m_next;  
        if (p->m_data.m_score == score)
            mb_deleteNode(p);
        p = next;
    }
}


CP_ChainDoubleLink* CP_ChainDoubleLink::mb_findNodeById(int id)
{
    if (m_previous == NULL) return NULL;

    CP_ChainDoubleLink *p = this;
    do
    {
        if (p->m_data.m_ID == id) return p;   
        if (p->m_data.m_ID >  id) return NULL; 
        p = p->m_next;
    } while (p != this);

    return NULL;
}

int CP_ChainDoubleLink::mb_getNodeCount()
{
    if (m_previous == NULL) return 0;

    int n = 0;
    CP_ChainDoubleLink *p = this;
    do { n++; p = p->m_next; } while (p != this);
    return n;
}
