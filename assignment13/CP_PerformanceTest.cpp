#include <iostream>
#include <iomanip>
#include <ctime>
#include <new>
using namespace std;

#include "CP_StudentProduct.h"
#include "CP_StudentFactory.h"

class CP_DirectProduct
{
public:
    CP_NodeDoubleLink *m_head;
    CP_DirectProduct() : m_head(NULL) {}
    ~CP_DirectProduct() { deleteAll(); }
 
    void mb_insertHead(CP_Student s)
    {
        CP_NodeDoubleLink *pNew = new(nothrow) CP_NodeDoubleLink;
        if (!pNew) return;
        pNew->m_data = s;
        if (m_head == NULL)
        {
            m_head = pNew;
            pNew->m_previous = pNew;
            pNew->m_next = pNew;
            return;
        }
        CP_NodeDoubleLink *tail = m_head->m_previous;
        pNew->m_next = m_head;
        pNew->m_previous = tail;
        tail->m_next = pNew;
        m_head->m_previous = pNew;
        m_head = pNew;
    }
 
    void mb_deleteHead()
    {
        if (m_head == NULL) return;
        if (m_head->m_next == m_head)
        {
            delete m_head;
            m_head = NULL;
            return;
        }
        CP_NodeDoubleLink *p = m_head;
        m_head = p->m_next;
        m_head->m_previous = p->m_previous;
        p->m_previous->m_next = m_head;
        delete p;
    }
 
    bool mb_insertSorted(CP_Student s)
    {
        CP_NodeDoubleLink *pNew = new(nothrow) CP_NodeDoubleLink;
        if (!pNew) return false;
        pNew->m_data = s;
        if (m_head == NULL)
        {
            m_head = pNew; pNew->m_previous = pNew; pNew->m_next = pNew;
            return true;
        }
        if (s.m_ID < m_head->m_data.m_ID)
        {
            CP_NodeDoubleLink *tail = m_head->m_previous;
            pNew->m_next = m_head; pNew->m_previous = tail;
            tail->m_next = pNew; m_head->m_previous = pNew;
            m_head = pNew;
            return true;
        }
        CP_NodeDoubleLink *pos = m_head->m_next;
        while (pos != m_head && pos->m_data.m_ID <= s.m_ID) pos = pos->m_next;
        CP_NodeDoubleLink *prev = pos->m_previous;
        pNew->m_next = pos; pNew->m_previous = prev;
        prev->m_next = pNew; pos->m_previous = pNew;
        return true;
    }

    void deleteAll()
    {
        if (m_head == NULL) return;
        m_head->m_previous->m_next = NULL;
        CP_NodeDoubleLink *p = m_head;
        while (p) { CP_NodeDoubleLink *n = p->m_next; delete p; p = n; }
        m_head = NULL;
    }
};

class CP_FactoryProduct
{
public:
    CP_NodeDoubleLink *m_head;
    CP_FactoryProduct() : m_head(NULL) {}

    void mb_insertHead(CP_Student s, CP_StudentFactory &fac)
    {
        CP_NodeDoubleLink *pNew = fac.mb_getNode();
        if (!pNew) return;
        pNew->m_data = s;
        if (m_head == NULL)
        {
            m_head = pNew;
            pNew->m_previous = pNew;
            pNew->m_next = pNew;
            return;
        }
        CP_NodeDoubleLink *tail = m_head->m_previous;
        pNew->m_next = m_head;
        pNew->m_previous = tail;
        tail->m_next = pNew;
        m_head->m_previous = pNew;
        m_head = pNew;
    }

    void mb_deleteHead(CP_StudentFactory &fac)
    {
        if (m_head == NULL) return;
        CP_NodeDoubleLink *p = m_head;
        if (m_head->m_next == m_head)
            m_head = NULL;
        else
        {
            m_head = p->m_next;
            m_head->m_previous = p->m_previous;
            p->m_previous->m_next = m_head;
        }
        p->m_previous = NULL;
        p->m_next = NULL;
        fac.mb_returnNode(p);
    }

    void mb_deleteAll(CP_StudentFactory &fac)
    {
        if (m_head == NULL) return;
        m_head->m_previous->m_next = NULL;
        CP_NodeDoubleLink *p = m_head;
        while (p)
        {
            CP_NodeDoubleLink *n = p->m_next;
            p->m_previous = NULL;
            p->m_next = NULL;
            fac.mb_returnNode(p);
            p = n;
        }
        m_head = NULL;
    }
};

void testA_PureAllocation(int N, int rounds)
{
    cout << "\n[A] Head-insert " << N << " + delete all, "
         << rounds << " rounds (O(1) ops, isolate alloc cost)" << endl;

    
    {
        clock_t start = clock();
        for (int r = 0; r < rounds; r++)
        {
            CP_DirectProduct prod;
            for (int i = 0; i < N; i++)
                prod.mb_insertHead(CP_Student(i, i));
            prod.deleteAll();
        }
        clock_t end = clock();
        cout << "  HW6  (new/delete):    " << fixed << setprecision(2)
             << 1000.0 * (end - start) / CLOCKS_PER_SEC << " ms" << endl;
    }
 
    {
        clock_t start = clock();
        CP_StudentFactory fac;
        for (int r = 0; r < rounds; r++)
        {
            CP_FactoryProduct prod;
            for (int i = 0; i < N; i++)
                prod.mb_insertHead(CP_Student(i, i), fac);
            prod.mb_deleteAll(fac);
        }
        clock_t end = clock();
        cout << "  HW13 (factory):       " << fixed << setprecision(2)
             << 1000.0 * (end - start) / CLOCKS_PER_SEC << " ms" << endl;
        fac.mb_deleteAll();
    }
}

void testB_SortedInsert(int N, int rounds)
{
    cout << "\n[B] Sorted-insert " << N << " + delete all, "
         << rounds << " rounds (O(n) traversal dominates)" << endl;
    
    {
        clock_t start = clock();
        for (int r = 0; r < rounds; r++)
        {
            CP_DirectProduct prod;
            for (int i = 1; i <= N; i++)
                prod.mb_insertSorted(CP_Student(i, i * 10));
            prod.deleteAll();
        }
        clock_t end = clock();
        cout << "  HW6  (new/delete):    " << fixed << setprecision(2)
             << 1000.0 * (end - start) / CLOCKS_PER_SEC << " ms" << endl;
    }

    {
        clock_t start = clock();
        CP_StudentFactory fac;
        for (int r = 0; r < rounds; r++)
        {
            CP_StudentProduct prod;
            for (int i = 1; i <= N; i++)
                prod.mb_insertSorted(CP_Student(i, i * 10), fac);
            prod.mb_deleteAll(fac);
        }
        clock_t end = clock();
        cout << "  HW13 (factory):       " << fixed << setprecision(2)
             << 1000.0 * (end - start) / CLOCKS_PER_SEC << " ms" << endl;
        fac.mb_deleteAll();
    }
}

void testC_Alternating(int N)
{
    cout << "\n[C] Alternating head-insert/head-delete, "
         << N << " ops (O(1), high-frequency alloc/free)" << endl;

    
    {
        clock_t start = clock();
        CP_DirectProduct prod;
        for (int i = 0; i < N; i++)
        {
            prod.mb_insertHead(CP_Student(i, i));
            prod.mb_insertHead(CP_Student(i + N, i));
            prod.mb_deleteHead();
        }
        prod.deleteAll();
        clock_t end = clock();
        cout << "  HW6  (new/delete):    " << fixed << setprecision(2)
             << 1000.0 * (end - start) / CLOCKS_PER_SEC << " ms" << endl;
    }

    
    {
        clock_t start = clock();
        CP_StudentFactory fac;
        CP_FactoryProduct prod;
        for (int i = 0; i < N; i++)
        {
            prod.mb_insertHead(CP_Student(i, i), fac);
            prod.mb_insertHead(CP_Student(i + N, i), fac);
            prod.mb_deleteHead(fac);
        }
        prod.mb_deleteAll(fac);
        clock_t end = clock();
        cout << "  HW13 (factory):       " << fixed << setprecision(2)
             << 1000.0 * (end - start) / CLOCKS_PER_SEC << " ms" << endl;
        fac.mb_deleteAll();
    }
}

int main()
{
    cout << "============================================================" << endl;
    cout << "  Performance: HW6 (new/delete) vs HW13 (Factory Method)"    << endl;
    cout << "============================================================" << endl;

    cout << "\n--- Scenario A: Pure alloc/free (O(1) head-insert) ---" << endl;
    testA_PureAllocation(10000, 500);
    testA_PureAllocation(100000, 50);

    cout << "\n--- Scenario B: Sorted insert (O(n) traversal dominates) ---" << endl;
    testB_SortedInsert(1000, 100);
    testB_SortedInsert(5000, 20);

    cout << "\n--- Scenario C: Alternating head-insert/delete (O(1)) ---" << endl;
    testC_Alternating(500000);
    testC_Alternating(2000000);

    cout << "\n============================================================" << endl;
    cout << "  Done." << endl;
    cout << "============================================================" << endl;
    return 0;
}
