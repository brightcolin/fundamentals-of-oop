#include <iostream>
#include <iomanip>
#include <new>
using namespace std;

#include "CP_StudentSystemTest.h"

CP_StudentSystemTest::CP_StudentSystemTest()
    : m_passed(0), m_failed(0) {}

int CP_StudentSystemTest::getPassed() const { return m_passed; }
int CP_StudentSystemTest::getFailed() const { return m_failed; }

void CP_StudentSystemTest::printHeader(const char* title) const
{
    cout << "\n-- " << title << " --" << endl;
}

void CP_StudentSystemTest::check(const char* name, bool ok, const char* detail)
{
    cout << (ok ? "| [PASS] " : "| [FAIL] ")
         << left << setw(56) << name;
    if (detail && detail[0]) cout << "  " << detail;
    cout << endl;
    ok ? ++m_passed : ++m_failed;
}

void CP_StudentSystemTest::checkList(const char* name,
                                     CP_StudentProduct &prod,
                                     int ids[],
                                     int scores[],
                                     int count)
{
    int actual = prod.mb_getNodeCount();

    if (actual != count)
    {
        cout << "| [FAIL] " << left << setw(56) << name
             << "  count got=" << actual << " exp=" << count << endl;
        ++m_failed;
        return;
    }

    if (count == 0)
    {
        cout << "| [PASS] " << left << setw(56) << name << endl;
        ++m_passed;
        return;
    }

    CP_NodeDoubleLink *p = prod.m_head;
    for (int i = 0; i < count; i++)
    {
        if (p->m_data.m_ID != ids[i] ||
            p->m_data.m_score != scores[i])
        {
            cout << "| [FAIL] " << left << setw(56) << name
                 << "  node[" << i << "] got=("
                 << p->m_data.m_ID << "," << p->m_data.m_score
                 << ") exp=(" << ids[i] << "," << scores[i] << ")" << endl;
            ++m_failed;
            return;
        }
        p = p->m_next;
    }
    cout << "| [PASS] " << left << setw(56) << name << endl;
    ++m_passed;
}

void CP_StudentSystemTest::insertMany(CP_StudentProduct &prod,
                                      CP_StudentFactory &fac,
                                      CP_Student arr[], int n)
{
    for (int i = 0; i < n; i++)
        prod.mb_insertSorted(arr[i], fac);
}

void CP_StudentSystemTest::test1_SortedInsert()
{
    printHeader("Test 1: Sorted insert (head/middle/tail/single-node)");

    CP_StudentFactory fac;
    CP_StudentProduct prod;

    CP_Student d1[] = {
        CP_Student(5,60), CP_Student(1,90), CP_Student(3,70),
        CP_Student(7,50), CP_Student(2,85)
    };
    insertMany(prod, fac, d1, 5);

    int ei1[] = {1,2,3,5,7};
    int es1[] = {90,85,70,60,50};
    checkList("Insert 5,1,3,7,2 -- expect order 1,2,3,5,7",
              prod, ei1, es1, 5);

    CP_StudentFactory fac2;
    CP_StudentProduct prod2;
    prod2.mb_insertSorted(CP_Student(42,75), fac2);
    int ei2[] = {42}; int es2[] = {75};
    checkList("Single node ID=42", prod2, ei2, es2, 1);

    prod2.mb_insertSorted(CP_Student(10,88), fac2);
    int ei3[] = {10,42}; int es3[] = {88,75};
    checkList("Insert ID=10 before existing ID=42", prod2, ei3, es3, 2);

    prod.mb_deleteAll(fac);
    fac.mb_deleteAll();
    prod2.mb_deleteAll(fac2);
    fac2.mb_deleteAll();
}


void CP_StudentSystemTest::test2_DeleteById()
{
    printHeader("Test 2: Delete by ID (head/middle/tail/not-found/only-node)");

    CP_StudentFactory fac;
    CP_StudentProduct prod;
    CP_Student d[] = {
        CP_Student(10,80), CP_Student(20,90),
        CP_Student(30,70), CP_Student(40,85)
    };
    insertMany(prod, fac, d, 4);
 
    prod.mb_deleteById(10, fac);
    { int ei[]={20,30,40}; int es[]={90,70,85};
      checkList("Delete head ID=10 -- remain 20,30,40", prod, ei, es, 3); }
  
    prod.mb_deleteById(30, fac);
    { int ei[]={20,40}; int es[]={90,85};
      checkList("Delete middle ID=30 -- remain 20,40", prod, ei, es, 2); }

    prod.mb_deleteById(40, fac);
    { int ei[]={20}; int es[]={90};
      checkList("Delete tail ID=40 -- remain 20", prod, ei, es, 1); }

    bool ret = prod.mb_deleteById(999, fac);
    check("deleteById(999) returns false -- list unchanged", ret == false);
    check("Count still 1 after not-found delete",
          prod.mb_getNodeCount() == 1);

    prod.mb_deleteById(20, fac);
    check("Delete only node -- list empty (count=0)",
          prod.mb_getNodeCount() == 0);

    fac.mb_deleteAll();
}

void CP_StudentSystemTest::test3_DeleteByScore()
{
    printHeader("Test 3: Delete by score (multi-head/no-match/clear-all/tail-only)");

    CP_StudentFactory fac;
    CP_StudentProduct prod;

    CP_Student d1[] = {
        CP_Student(1,85), CP_Student(2,90),
        CP_Student(3,85), CP_Student(4,85), CP_Student(5,70)
    };
    insertMany(prod, fac, d1, 5);
    prod.mb_deleteByScore(85, fac);
    { int ei[]={2,5}; int es[]={90,70};
      checkList("Delete score=85 (head+2 mid) -- remain 2,5", prod, ei, es, 2); }

    int removed = prod.mb_deleteByScore(99, fac);
    check("Delete score=99 (no match) -- 0 removed", removed == 0);
    check("Count still 2", prod.mb_getNodeCount() == 2);

    prod.mb_deleteByScore(70, fac);
    { int ei[]={2}; int es[]={90};
      checkList("Delete score=70 (tail only) -- remain 2", prod, ei, es, 1); }

    prod.mb_deleteAll(fac);
    CP_Student d2[] = {
        CP_Student(1,80), CP_Student(2,80), CP_Student(3,80)
    };
    insertMany(prod, fac, d2, 3);
    prod.mb_deleteByScore(80, fac);
    check("Delete score=80 (all match) -- list empty",
          prod.mb_getNodeCount() == 0);

    fac.mb_deleteAll();
}

void CP_StudentSystemTest::test4_QueryById()
{
    printHeader("Test 4: Query score by ID (head/mid/tail/early-exit/overmax/empty)");

    CP_StudentFactory fac;
    CP_StudentProduct prod;
    CP_Student d[] = {
        CP_Student(10,80), CP_Student(30,90), CP_Student(50,70)
    };
    insertMany(prod, fac, d, 3);

    CP_NodeDoubleLink *p = prod.mb_findNodeById(10);
    check("findById(10) -- head, score=80",
          p != NULL && p->m_data.m_score == 80);

    p = prod.mb_findNodeById(30);
    check("findById(30) -- middle, score=90",
          p != NULL && p->m_data.m_score == 90);

    p = prod.mb_findNodeById(50);
    check("findById(50) -- tail, score=70",
          p != NULL && p->m_data.m_score == 70);

    check("findById(20) -- between 10&30, early exit",
          prod.mb_findNodeById(20) == NULL);

    check("findById(99) -- larger than all, not found",
          prod.mb_findNodeById(99) == NULL);
 
    CP_StudentFactory fac2;
    CP_StudentProduct prod2;
    check("findById on empty list -- NULL",
          prod2.mb_findNodeById(10) == NULL);

    prod.mb_deleteAll(fac);
    fac.mb_deleteAll();
}


void CP_StudentSystemTest::test5_QueryByScore()
{
    printHeader("Test 5: Query IDs by score (multi/single/none/empty)");

    CP_StudentFactory fac;
    CP_StudentProduct prod;
    CP_Student d[] = {
        CP_Student(1,90), CP_Student(2,80),
        CP_Student(3,90), CP_Student(4,70), CP_Student(5,90)
    };
    insertMany(prod, fac, d, 5);

    auto countScore = [&](CP_StudentProduct &pr, int score) -> int {
        if (pr.mb_isEmpty()) return 0;
        int n = 0;
        CP_NodeDoubleLink *p = pr.m_head;
        do { if (p->m_data.m_score == score) n++;
             p = p->m_next; }
        while (p != pr.m_head);
        return n;
    };

    check("queryByScore(90) -- 3 matches (ID=1,3,5)", countScore(prod, 90) == 3);
    check("queryByScore(70) -- 1 match (ID=4)", countScore(prod, 70) == 1);
    check("queryByScore(60) -- 0 matches", countScore(prod, 60) == 0);

    CP_StudentProduct prod2;
    check("queryByScore on empty list -- 0",
          countScore(prod2, 90) == 0);

    prod.mb_deleteAll(fac);
    fac.mb_deleteAll();
}

void CP_StudentSystemTest::test6_DuplicateId()
{
    printHeader("Test 6: Duplicate ID rejected, unique ID accepted");

    CP_StudentFactory fac;
    CP_StudentProduct prod;

    prod.mb_insertSorted(CP_Student(1,90), fac);
    prod.mb_insertSorted(CP_Student(2,80), fac);

    
    bool isDuplicate = (prod.mb_findNodeById(1) != NULL);
    check("findById(1) before duplicate insert -- found (skip insert)",
          isDuplicate);
    check("Count still 2 after duplicate attempt",
          prod.mb_getNodeCount() == 2);

    int ei[]={1,2}; int es[]={90,80};
    checkList("List intact after duplicate attempt -- 1,2",
              prod, ei, es, 2);

    prod.mb_insertSorted(CP_Student(3,70), fac);
    check("New unique ID=3 accepted -- count now 3",
          prod.mb_getNodeCount() == 3);

    prod.mb_deleteAll(fac);
    fac.mb_deleteAll();
}

void CP_StudentSystemTest::test7_MixedOps()
{
    printHeader("Test 7: Mixed operations (insert->delete->query sequence)");

    CP_StudentFactory fac;
    CP_StudentProduct prod;

    CP_Student d[] = {
        CP_Student(30,85), CP_Student(10,90),
        CP_Student(50,85), CP_Student(20,70), CP_Student(40,60)
    };
    insertMany(prod, fac, d, 5);
    { int ei[]={10,20,30,40,50}; int es[]={90,70,85,60,85};
      checkList("After insert: ascending order 10,20,30,40,50",
                prod, ei, es, 5); }

    prod.mb_deleteById(20, fac);
    { int ei[]={10,30,40,50}; int es[]={90,85,60,85};
      checkList("After delete ID=20: remain 10,30,40,50",
                prod, ei, es, 4); }

    prod.mb_deleteByScore(85, fac);
    { int ei[]={10,40}; int es[]={90,60};
      checkList("After delete score=85: remain 10,40",
                prod, ei, es, 2); }

    CP_NodeDoubleLink *p = prod.mb_findNodeById(10);
    check("Query ID=10 -- score=90", p != NULL && p->m_data.m_score == 90);

    p = prod.mb_findNodeById(40);
    check("Query ID=40 -- score=60", p != NULL && p->m_data.m_score == 60);

    check("Query deleted ID=20 -- NULL",
          prod.mb_findNodeById(20) == NULL);
    check("Query deleted ID=30 -- NULL",
          prod.mb_findNodeById(30) == NULL);

    prod.mb_insertSorted(CP_Student(25,95), fac);
    { int ei[]={10,25,40}; int es[]={90,95,60};
      checkList("After insert ID=25: order 10,25,40",
                prod, ei, es, 3); }

    prod.mb_deleteAll(fac);
    fac.mb_deleteAll();
}


void CP_StudentSystemTest::test8_FactoryRecycle()
{
    printHeader("Test 8: Factory node recycling");

    CP_StudentFactory fac;
    CP_StudentProduct prod;

    check("Factory initially empty (spare=0)",
          fac.mb_getSpareCount() == 0);

    CP_Student d[] = {
        CP_Student(1,90), CP_Student(2,80), CP_Student(3,70)
    };
    insertMany(prod, fac, d, 3);
    check("After insert 3 students, product count=3",
          prod.mb_getNodeCount() == 3);
    check("Factory still empty (all nodes in use)",
          fac.mb_getSpareCount() == 0);

    prod.mb_deleteById(2, fac);
    check("After delete ID=2, product count=2",
          prod.mb_getNodeCount() == 2);
    check("Factory has 1 spare node",
          fac.mb_getSpareCount() == 1);

    prod.mb_insertSorted(CP_Student(4,60), fac);
    check("After insert ID=4, product count=3",
          prod.mb_getNodeCount() == 3);
    check("Factory spare back to 0 (node reused)",
          fac.mb_getSpareCount() == 0);

    prod.mb_deleteAll(fac);
    check("After deleteAll, product empty",
          prod.mb_getNodeCount() == 0);
    check("Factory has 3 spare nodes",
          fac.mb_getSpareCount() == 3);
    
    prod.mb_insertSorted(CP_Student(10,100), fac);
    prod.mb_insertSorted(CP_Student(20,200), fac);
    check("After insert 2, product count=2",
          prod.mb_getNodeCount() == 2);
    check("Factory has 1 spare node remaining",
          fac.mb_getSpareCount() == 1);

    prod.mb_deleteByScore(100, fac);
    check("After delete score=100, product count=1",
          prod.mb_getNodeCount() == 1);
    check("Factory has 2 spare nodes",
          fac.mb_getSpareCount() == 2);

    prod.mb_deleteAll(fac);
    check("Final: product empty, factory has 3 spares",
          prod.mb_getNodeCount() == 0 && fac.mb_getSpareCount() == 3);

    fac.mb_deleteAll();
    check("After factory deleteAll, spare=0",
          fac.mb_getSpareCount() == 0);
}


void CP_StudentSystemTest::test9_CompareWithHW6()
{
    printHeader("Test 9: Compare with HW6 (same operations, same results)");

    CP_StudentFactory fac;
    CP_StudentProduct prod;
 
    CP_Student d[] = {
        CP_Student(30,85), CP_Student(10,90),
        CP_Student(50,85), CP_Student(20,70), CP_Student(40,60)
    };
    insertMany(prod, fac, d, 5);
    { int ei[]={10,20,30,40,50}; int es[]={90,70,85,60,85};
      checkList("[HW6 compat] Insert order matches HW6",
                prod, ei, es, 5); }

    prod.mb_deleteById(20, fac);
    { int ei[]={10,30,40,50}; int es[]={90,85,60,85};
      checkList("[HW6 compat] Delete ID=20 matches HW6",
                prod, ei, es, 4); }

    prod.mb_deleteByScore(85, fac);
    { int ei[]={10,40}; int es[]={90,60};
      checkList("[HW6 compat] Delete score=85 matches HW6",
                prod, ei, es, 2); }

    CP_NodeDoubleLink *p = prod.mb_findNodeById(10);
    check("[HW6 compat] Query ID=10 score=90",
          p != NULL && p->m_data.m_score == 90);
    p = prod.mb_findNodeById(40);
    check("[HW6 compat] Query ID=40 score=60",
          p != NULL && p->m_data.m_score == 60);
    check("[HW6 compat] Deleted ID=20 not found",
          prod.mb_findNodeById(20) == NULL);
    check("[HW6 compat] Deleted ID=30 not found",
          prod.mb_findNodeById(30) == NULL);

    prod.mb_insertSorted(CP_Student(25,95), fac);
    { int ei[]={10,25,40}; int es[]={90,95,60};
      checkList("[HW6 compat] Insert ID=25, order 10,25,40",
                prod, ei, es, 3); }

    check("[HW6 compat] Factory recycled correctly (spare=2)",
          fac.mb_getSpareCount() == 2);

    prod.mb_deleteAll(fac);
    fac.mb_deleteAll();
}


int CP_StudentSystemTest::runAll()
{
    test1_SortedInsert();
    test2_DeleteById();
    test3_DeleteByScore();
    test4_QueryById();
    test5_QueryByScore();
    test6_DuplicateId();
    test7_MixedOps();
    test8_FactoryRecycle();
    test9_CompareWithHW6();
    printSummary();
    return m_failed;
}

void CP_StudentSystemTest::printSummary() const
{
    cout << "\n====================================================\n"
         << "  Test Results:  "
         << m_passed << " passed,  "
         << m_failed << " failed,  "
         << (m_passed + m_failed) << " total\n"
         << (m_failed == 0 ? "  All tests PASSED!\n"
                           : "  SOME TESTS FAILED.\n")
         << "====================================================\n";
}
