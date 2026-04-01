#ifndef CP_STUDENTSYSTEMTEST_H
#define CP_STUDENTSYSTEMTEST_H

#include "CP_StudentSystem.h"

// ============================================================
// CP_StudentSystemTest -- automated test framework
//
// Test situation partition (7 situations):
//   Test 1  Sorted insert         out-of-order insert, verify ascending order
//   Test 2  Delete by ID          head / middle / tail / not-found / only-node
//   Test 3  Delete by score       multi-match(head+body) / no-match / clear-all
//   Test 4  Query score by ID     found(head/mid/tail) / not-found / early-exit
//   Test 5  Query IDs by score    multi / single / none / empty-list
//   Test 6  Duplicate ID          duplicate rejected, unique ID accepted
//   Test 7  Mixed operations      insert + delete + query in sequence
// ============================================================

class CP_StudentSystemTest
{
public:
    CP_StudentSystemTest();

    int  runAll();
    void printSummary() const;

    int getPassed() const;
    int getFailed() const;

private:
    int m_passed;
    int m_failed;

    // 7 test situations
    void test1_SortedInsert();
    void test2_DeleteById();
    void test3_DeleteByScore();
    void test4_QueryById();
    void test5_QueryByScore();
    void test6_DuplicateId();
    void test7_MixedOps();

    // Assertion helpers
    void check(const char* name, bool ok, const char* detail = "");
    void checkList(const char* name, CP_StudentSystem& sys,
                   int ids[], int scores[], int count);
    void printHeader(const char* title) const;

    // Helpers: batch insert / reset list
    void insertMany(CP_StudentSystem& sys, CP_Student arr[], int n);
    void reset(CP_StudentSystem& sys);
};

#endif
