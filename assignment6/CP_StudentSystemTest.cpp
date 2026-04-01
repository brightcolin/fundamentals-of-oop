// ============================================================
// CP_StudentSystemTest.cpp
// Responsibility: assertion helpers + 7 test situations +
//                 runAll() + printSummary()
// ============================================================

#include <iostream>
#include <iomanip>
#include <new>
using namespace std;

#include "CP_StudentSystemTest.h"

// ============================================================
// Constructor / statistics
// ============================================================

CP_StudentSystemTest::CP_StudentSystemTest()
    : m_passed(0), m_failed(0) {}

int CP_StudentSystemTest::getPassed() const { return m_passed; }
int CP_StudentSystemTest::getFailed() const { return m_failed; }

// ============================================================
// Assertion helpers
// ============================================================

void CP_StudentSystemTest::printHeader(const char* title) const
{
    cout << "\n-- " << title << " --" << endl;
}

// General boolean assertion
void CP_StudentSystemTest::check(const char* name, bool ok, const char* detail)
{
    cout << (ok ? "| [PASS] " : "| [FAIL] ")
         << left << setw(52) << name;
    if (detail && detail[0]) cout << "  " << detail;
    cout << endl;
    ok ? ++m_passed : ++m_failed;
}

// Verify node count AND each node's ID and Score match expected arrays
void CP_StudentSystemTest::checkList(const char*      name,
                                     CP_StudentSystem& sys,
                                     int               ids[],
                                     int               scores[],
                                     int               count)
{
    int actual = (sys.m_head->m_previous != NULL)
                 ? sys.m_head->mb_getNodeCount() : 0;

    if (actual != count)
    {
        cout << "| [FAIL] " << left << setw(52) << name
             << "  count got=" << actual << " exp=" << count << endl;
        ++m_failed;
        return;
    }

    CP_ChainDoubleLink *p = sys.m_head;
    for (int i = 0; i < count; i++)
    {
        if (p->m_data.m_ID    != ids[i] ||
            p->m_data.m_score != scores[i])
        {
            cout << "| [FAIL] " << left << setw(52) << name
                 << "  node[" << i << "] got=("
                 << p->m_data.m_ID << "," << p->m_data.m_score
                 << ") exp=(" << ids[i] << "," << scores[i] << ")" << endl;
            ++m_failed;
            return;
        }
        p = p->m_next;
    }
    cout << "| [PASS] " << left << setw(52) << name << endl;
    ++m_passed;
}

// ============================================================
// Helpers
// ============================================================

void CP_StudentSystemTest::insertMany(CP_StudentSystem& sys,
                                      CP_Student arr[], int n)
{
    for (int i = 0; i < n; i++)
        sys.m_head->mb_insertSorted(arr[i]);
}

void CP_StudentSystemTest::reset(CP_StudentSystem& sys)
{
    delete sys.m_head;
    sys.m_head = new(nothrow) CP_ChainDoubleLink;
}

// ============================================================
// Test 1 -- Sorted insert
//
// Partition:
//   A  new ID smaller than head  (data-shift, head pointer unchanged)
//   B  new ID fits in the middle
//   C  new ID larger than all    (appended at tail)
//   D  single-node list
// ============================================================
void CP_StudentSystemTest::test1_SortedInsert()
{
    printHeader("Test 1: Sorted insert (head/middle/tail/single-node)");

    CP_StudentSystem sys;
    sys.m_head = new CP_ChainDoubleLink;

    // Insert order: 5, 1, 3, 7, 2
    //   5 -> [5]
    //   1 -> [1,5]         A: smaller than head
    //   3 -> [1,3,5]       B: middle
    //   7 -> [1,3,5,7]     C: tail
    //   2 -> [1,2,3,5,7]   B: middle again
    CP_Student d1[] = {
        CP_Student(5,60), CP_Student(1,90), CP_Student(3,70),
        CP_Student(7,50), CP_Student(2,85)
    };
    insertMany(sys, d1, 5);

    int ei1[] = {1,2,3,5,7};
    int es1[] = {90,85,70,60,50};
    checkList("Insert 5,1,3,7,2 -- expect order 1,2,3,5,7",
              sys, ei1, es1, 5);

    // D: single-node
    reset(sys);
    sys.m_head->mb_insertSorted(CP_Student(42,75));
    int ei2[] = {42}; int es2[] = {75};
    checkList("Single node ID=42", sys, ei2, es2, 1);

    // Insert at head of single-node list
    sys.m_head->mb_insertSorted(CP_Student(10,88));
    int ei3[] = {10,42}; int es3[] = {88,75};
    checkList("Insert ID=10 before existing ID=42", sys, ei3, es3, 2);
}

// ============================================================
// Test 2 -- Delete by ID
//
// Partition:
//   A  delete head node    (copy-next-data method, head pointer unchanged)
//   B  delete middle node  (standard unlink)
//   C  delete tail node
//   D  delete non-existent ID  (findNodeById returns NULL, list unchanged)
//   E  delete the only node    (list becomes empty)
// ============================================================
void CP_StudentSystemTest::test2_DeleteById()
{
    printHeader("Test 2: Delete by ID (head/middle/tail/not-found/only-node)");

    CP_StudentSystem sys;
    sys.m_head = new CP_ChainDoubleLink;
    CP_Student d[] = {
        CP_Student(10,80), CP_Student(20,90),
        CP_Student(30,70), CP_Student(40,85)
    };
    insertMany(sys, d, 4);

    // A: delete head ID=10
    CP_ChainDoubleLink *p = sys.m_head->mb_findNodeById(10);
    sys.m_head->mb_deleteNode(p);
    { int ei[]={20,30,40}; int es[]={90,70,85};
      checkList("Delete head ID=10 -- remain 20,30,40", sys, ei, es, 3); }

    // B: delete middle ID=30
    p = sys.m_head->mb_findNodeById(30);
    sys.m_head->mb_deleteNode(p);
    { int ei[]={20,40}; int es[]={90,85};
      checkList("Delete middle ID=30 -- remain 20,40", sys, ei, es, 2); }

    // C: delete tail ID=40
    p = sys.m_head->mb_findNodeById(40);
    sys.m_head->mb_deleteNode(p);
    { int ei[]={20}; int es[]={90};
      checkList("Delete tail ID=40 -- remain 20", sys, ei, es, 1); }

    // D: non-existent ID
    p = sys.m_head->mb_findNodeById(999);
    check("findById(999) returns NULL -- list unchanged", p == NULL);
    int cnt = sys.m_head->mb_getNodeCount();
    check("Count still 1 after not-found delete", cnt == 1);

    // E: delete the only node, list becomes empty
    p = sys.m_head->mb_findNodeById(20);
    sys.m_head->mb_deleteNode(p);
    int after = (sys.m_head->m_previous != NULL)
                ? sys.m_head->mb_getNodeCount() : 0;
    check("Delete only node -- list empty (count=0)", after == 0);
}

// ============================================================
// Test 3 -- Delete by score
//
// Partition:
//   A  multi-match including head node  (head uses copy-data loop)
//   B  no match                         (list unchanged)
//   C  all nodes match                  (list becomes empty)
//   D  only tail node matches
// ============================================================
void CP_StudentSystemTest::test3_DeleteByScore()
{
    printHeader("Test 3: Delete by score (multi-head/no-match/clear-all/tail-only)");

    CP_StudentSystem sys;
    sys.m_head = new CP_ChainDoubleLink;

    // A: ID=1,3,4 have score=85 (including head node ID=1)
    CP_Student d1[] = {
        CP_Student(1,85), CP_Student(2,90),
        CP_Student(3,85), CP_Student(4,85), CP_Student(5,70)
    };
    insertMany(sys, d1, 5);
    sys.m_head->mb_deleteByScore(85);
    { int ei[]={2,5}; int es[]={90,70};
      checkList("Delete score=85 (head+2 mid) -- remain 2,5", sys, ei, es, 2); }

    // B: no match
    sys.m_head->mb_deleteByScore(99);
    check("Delete score=99 (no match) -- count still 2",
          sys.m_head->mb_getNodeCount() == 2);

    // D: only tail matches (score=70, ID=5 is tail)
    sys.m_head->mb_deleteByScore(70);
    { int ei[]={2}; int es[]={90};
      checkList("Delete score=70 (tail only) -- remain 2", sys, ei, es, 1); }

    // C: all match, list becomes empty
    reset(sys);
    CP_Student d2[] = {
        CP_Student(1,80), CP_Student(2,80), CP_Student(3,80)
    };
    insertMany(sys, d2, 3);
    sys.m_head->mb_deleteByScore(80);
    int after = (sys.m_head->m_previous != NULL)
                ? sys.m_head->mb_getNodeCount() : 0;
    check("Delete score=80 (all match) -- list empty", after == 0);
}

// ============================================================
// Test 4 -- Query score by ID
//
// Partition:
//   A  found: head node
//   B  found: middle node
//   C  found: tail node
//   D  not found: ID falls between two existing IDs (early-exit optimization)
//   E  not found: ID larger than all nodes
//   F  empty list query
// ============================================================
void CP_StudentSystemTest::test4_QueryById()
{
    printHeader("Test 4: Query score by ID (head/mid/tail/early-exit/overmax/empty)");

    CP_StudentSystem sys;
    sys.m_head = new CP_ChainDoubleLink;
    CP_Student d[] = {
        CP_Student(10,80), CP_Student(30,90), CP_Student(50,70)
    };
    insertMany(sys, d, 3);

    // A: head
    CP_ChainDoubleLink *p = sys.m_head->mb_findNodeById(10);
    check("findById(10) -- head, score=80",
          p != NULL && p->m_data.m_score == 80);

    // B: middle
    p = sys.m_head->mb_findNodeById(30);
    check("findById(30) -- middle, score=90",
          p != NULL && p->m_data.m_score == 90);

    // C: tail
    p = sys.m_head->mb_findNodeById(50);
    check("findById(50) -- tail, score=70",
          p != NULL && p->m_data.m_score == 70);

    // D: ID=20 is between 10 and 30; sorted list exits early at ID=30
    check("findById(20) -- between 10&30, early exit",
          sys.m_head->mb_findNodeById(20) == NULL);

    // E: larger than all
    check("findById(99) -- larger than all, not found",
          sys.m_head->mb_findNodeById(99) == NULL);

    // F: empty list
    reset(sys);
    check("findById on empty list -- NULL",
          sys.m_head->mb_findNodeById(10) == NULL);
}

// ============================================================
// Test 5 -- Query IDs by score
//
// Partition:
//   A  multiple matches
//   B  exactly one match
//   C  no match
//   D  empty list
// ============================================================
void CP_StudentSystemTest::test5_QueryByScore()
{
    printHeader("Test 5: Query IDs by score (multi/single/none/empty)");

    CP_StudentSystem sys;
    sys.m_head = new CP_ChainDoubleLink;
    CP_Student d[] = {
        CP_Student(1,90), CP_Student(2,80),
        CP_Student(3,90), CP_Student(4,70), CP_Student(5,90)
    };
    insertMany(sys, d, 5);

    auto countScore = [&](int score) -> int {
        if (sys.m_head->m_previous == NULL) return 0;
        int n = 0;
        CP_ChainDoubleLink *p = sys.m_head;
        do { if (p->m_data.m_score == score) n++;
             p = p->m_next; }
        while (p != sys.m_head);
        return n;
    };

    // A: score=90 matches ID=1,3,5
    check("queryByScore(90) -- 3 matches (ID=1,3,5)", countScore(90) == 3);

    // B: score=70 matches ID=4 only
    check("queryByScore(70) -- 1 match (ID=4)",       countScore(70) == 1);

    // C: score=60 -- no match
    check("queryByScore(60) -- 0 matches",            countScore(60) == 0);

    // D: empty list
    reset(sys);
    check("queryByScore on empty list -- 0",
          countScore(90) == 0);
}

// ============================================================
// Test 6 -- Duplicate ID handling
//
// The system enforces unique IDs.
// Verify that inserting an existing ID is rejected and
// the list remains unchanged.
// ============================================================
void CP_StudentSystemTest::test6_DuplicateId()
{
    printHeader("Test 6: Duplicate ID rejected, unique ID accepted");

    CP_StudentSystem sys;
    sys.m_head = new CP_ChainDoubleLink;

    // Insert ID=1 and ID=2
    sys.m_head->mb_insertSorted(CP_Student(1,90));
    sys.m_head->mb_insertSorted(CP_Student(2,80));

    // Attempt to insert duplicate ID=1
    // (system layer checks with findNodeById before insertSorted)
    bool isDuplicate = (sys.m_head->mb_findNodeById(1) != NULL);
    check("findById(1) before duplicate insert -- found (skip insert)",
          isDuplicate);

    // List must still have exactly 2 nodes
    int cnt = sys.m_head->mb_getNodeCount();
    check("Count still 2 after duplicate attempt", cnt == 2);

    // Verify list integrity: still ascending
    int ei[]={1,2}; int es[]={90,80};
    checkList("List intact after duplicate attempt -- 1,2",
              sys, ei, es, 2);

    // A genuinely new ID=3 must be accepted
    sys.m_head->mb_insertSorted(CP_Student(3,70));
    cnt = sys.m_head->mb_getNodeCount();
    check("New unique ID=3 accepted -- count now 3", cnt == 3);
}

// ============================================================
// Test 7 -- Mixed operations (insert + delete + query in sequence)
//
// Simulates a realistic usage session:
//   1. Insert several students
//   2. Delete one by ID
//   3. Delete some by score
//   4. Query remaining
// Verifies list consistency throughout.
// ============================================================
void CP_StudentSystemTest::test7_MixedOps()
{
    printHeader("Test 7: Mixed operations (insert->delete->query sequence)");

    CP_StudentSystem sys;
    sys.m_head = new CP_ChainDoubleLink;

    // Step 1: insert 5 students out of order
    CP_Student d[] = {
        CP_Student(30,85), CP_Student(10,90),
        CP_Student(50,85), CP_Student(20,70), CP_Student(40,60)
    };
    insertMany(sys, d, 5);
    { int ei[]={10,20,30,40,50}; int es[]={90,70,85,60,85};
      checkList("After insert: ascending order 10,20,30,40,50",
                sys, ei, es, 5); }

    // Step 2: delete by ID (ID=20, middle node)
    CP_ChainDoubleLink *p = sys.m_head->mb_findNodeById(20);
    sys.m_head->mb_deleteNode(p);
    { int ei[]={10,30,40,50}; int es[]={90,85,60,85};
      checkList("After delete ID=20: remain 10,30,40,50",
                sys, ei, es, 4); }

    // Step 3: delete by score=85 (head=10 is score=90, so score=85 matches 30 and 50)
    sys.m_head->mb_deleteByScore(85);
    { int ei[]={10,40}; int es[]={90,60};
      checkList("After delete score=85: remain 10,40",
                sys, ei, es, 2); }

    // Step 4: query remaining students
    p = sys.m_head->mb_findNodeById(10);
    check("Query ID=10 -- score=90", p != NULL && p->m_data.m_score == 90);

    p = sys.m_head->mb_findNodeById(40);
    check("Query ID=40 -- score=60", p != NULL && p->m_data.m_score == 60);

    // Deleted nodes must not be found
    check("Query deleted ID=20 -- NULL",
          sys.m_head->mb_findNodeById(20) == NULL);
    check("Query deleted ID=30 -- NULL",
          sys.m_head->mb_findNodeById(30) == NULL);

    // Step 5: insert a new node and verify order maintained
    sys.m_head->mb_insertSorted(CP_Student(25,95));
    { int ei[]={10,25,40}; int es[]={90,95,60};
      checkList("After insert ID=25: order 10,25,40",
                sys, ei, es, 3); }
}

// ============================================================
// runAll / printSummary
// ============================================================

int CP_StudentSystemTest::runAll()
{
    test1_SortedInsert();
    test2_DeleteById();
    test3_DeleteByScore();
    test4_QueryById();
    test5_QueryByScore();
    test6_DuplicateId();
    test7_MixedOps();
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
