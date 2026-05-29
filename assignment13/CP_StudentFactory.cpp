#include <iostream>
#include <new>
using namespace std;

#include "CP_StudentFactory.h"

CP_StudentFactory::CP_StudentFactory()
    : m_head(NULL), m_count(0)
{
}

CP_StudentFactory::~CP_StudentFactory()
{
    mb_deleteAll();
}

CP_NodeDoubleLink* CP_StudentFactory::mb_getNode()
{
    CP_NodeDoubleLink *p = NULL;

    if (m_head == NULL)
    {
        
        p = new(nothrow) CP_NodeDoubleLink;
        return p;
    }

    if (m_head->m_next == m_head)
    {
        
        p = m_head;
        m_head = NULL;
    }
    else
    {
        
        p = m_head;
        m_head = p->m_next;
        m_head->m_previous = p->m_previous;
        p->m_previous->m_next = m_head;
    }

    p->m_previous = NULL;
    p->m_next     = NULL;
    p->m_data     = CP_Student();
    m_count--;
    return p;
}

void CP_StudentFactory::mb_returnNode(CP_NodeDoubleLink *p)
{
    if (p == NULL) return;

    p->m_data = CP_Student();  

    if (m_head == NULL)
    {
        
        m_head = p;
        p->m_previous = p;
        p->m_next     = p;
    }
    else
    {
        
        CP_NodeDoubleLink *tail = m_head->m_previous;
        p->m_next     = m_head;
        p->m_previous = tail;
        tail->m_next  = p;
        m_head->m_previous = p;
    }
    m_count++;
}

int CP_StudentFactory::mb_getSpareCount() const
{
    return m_count;
}

void CP_StudentFactory::mb_deleteAll()
{
    if (m_head == NULL) return;

    
    m_head->m_previous->m_next = NULL;

    CP_NodeDoubleLink *p = m_head;
    while (p != NULL)
    {
        CP_NodeDoubleLink *next = p->m_next;
        delete p;
        p = next;
    }
    m_head  = NULL;
    m_count = 0;
}
