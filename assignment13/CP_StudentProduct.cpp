#include <iostream>
#include <new>
using namespace std;

#include "CP_StudentProduct.h"

CP_StudentProduct::CP_StudentProduct()
    : m_head(NULL)
{
}

CP_StudentProduct::~CP_StudentProduct()
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
    m_head = NULL;
}

bool CP_StudentProduct::mb_isEmpty() const
{
    return (m_head == NULL);
}

int CP_StudentProduct::mb_getNodeCount()
{
    if (m_head == NULL) return 0;

    int n = 0;
    CP_NodeDoubleLink *p = m_head;
    do
    {
        n++;
        p = p->m_next;
    } while (p != m_head);
    return n;
}

bool CP_StudentProduct::mb_insertSorted(CP_Student s, CP_StudentFactory &factory)
{
    CP_NodeDoubleLink *pNew = factory.mb_getNode();
    if (pNew == NULL) return false;

    pNew->m_data = s;
 
    if (m_head == NULL)
    {
        m_head = pNew;
        pNew->m_previous = pNew;
        pNew->m_next     = pNew;
        return true;
    }

    if (s.m_ID < m_head->m_data.m_ID)
    {
        CP_NodeDoubleLink *tail = m_head->m_previous;
        pNew->m_next = m_head;
        pNew->m_previous = tail;
        tail->m_next = pNew;
        m_head->m_previous = pNew;
        m_head = pNew;
        return true;
    }

    CP_NodeDoubleLink *pos = m_head->m_next;
    while (pos != m_head && pos->m_data.m_ID <= s.m_ID)
        pos = pos->m_next;

    CP_NodeDoubleLink *prev = pos->m_previous;
    pNew->m_next = pos;
    pNew->m_previous = prev;
    prev->m_next = pNew;
    pos->m_previous = pNew;
    return true;
}

bool CP_StudentProduct::mb_deleteById(int id, CP_StudentFactory &factory)
{
    CP_NodeDoubleLink *p = mb_findNodeById(id);
    if (p == NULL) return false;

    if (p->m_next == p)
    {
        m_head = NULL;
        factory.mb_returnNode(p);
        return true;
    }

    if (p == m_head)
        m_head = p->m_next;

    p->m_previous->m_next = p->m_next;
    p->m_next->m_previous = p->m_previous;
    p->m_previous = NULL;
    p->m_next = NULL;
    factory.mb_returnNode(p);
    return true;
}

int CP_StudentProduct::mb_deleteByScore(int score, CP_StudentFactory &factory)
{
    if (m_head == NULL) return 0;
    int count = 0;

    if (m_head->m_next != m_head)
    {
        CP_NodeDoubleLink *p = m_head->m_next;
        while (p != m_head)
        {
            CP_NodeDoubleLink *next = p->m_next;
            if (p->m_data.m_score == score)
            {
                p->m_previous->m_next = p->m_next;
                p->m_next->m_previous = p->m_previous;
                p->m_previous = NULL;
                p->m_next = NULL;
                factory.mb_returnNode(p);
                count++;
            }
            p = next;
        }
    }

    while (m_head != NULL && m_head->m_data.m_score == score)
    {
        if (m_head->m_next == m_head)
        {
            CP_NodeDoubleLink *p = m_head;
            m_head = NULL;
            p->m_previous = NULL;
            p->m_next = NULL;
            factory.mb_returnNode(p);
            count++;
        }
        else
        {
            CP_NodeDoubleLink *p = m_head;
            m_head = p->m_next;
            p->m_previous->m_next = m_head;
            m_head->m_previous    = p->m_previous;
            p->m_previous = NULL;
            p->m_next = NULL;
            factory.mb_returnNode(p);
            count++;
        }
    }
    return count;
}

CP_NodeDoubleLink* CP_StudentProduct::mb_findNodeById(int id)
{
    if (m_head == NULL) return NULL;

    CP_NodeDoubleLink *p = m_head;
    do
    {
        if (p->m_data.m_ID == id) return p;
        if (p->m_data.m_ID > id) return NULL;  
        p = p->m_next;
    } while (p != m_head);

    return NULL;
}

void CP_StudentProduct::mb_deleteAll(CP_StudentFactory &factory)
{
    if (m_head == NULL) return;
    m_head->m_previous->m_next = NULL;

    CP_NodeDoubleLink *p = m_head;
    while (p != NULL)
    {
        CP_NodeDoubleLink *next = p->m_next;
        p->m_previous = NULL;
        p->m_next = NULL;
        factory.mb_returnNode(p);
        p = next;
    }
    m_head = NULL;
}
