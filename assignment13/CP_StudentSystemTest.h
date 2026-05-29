#ifndef CP_STUDENTSYSTEMTEST_H
#define CP_STUDENTSYSTEMTEST_H

#include "CP_StudentProduct.h"
#include "CP_StudentFactory.h"

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

    void test1_SortedInsert();
    void test2_DeleteById();
    void test3_DeleteByScore();
    void test4_QueryById();
    void test5_QueryByScore();
    void test6_DuplicateId();
    void test7_MixedOps();
    void test8_FactoryRecycle();
    void test9_CompareWithHW6();

    void check(const char* name, bool ok, const char* detail = "");
    void checkList(const char* name, CP_StudentProduct &prod,
                   int ids[], int scores[], int count);
    void printHeader(const char* title) const;
    void insertMany(CP_StudentProduct &prod, CP_StudentFactory &fac,
                    CP_Student arr[], int n);
};

#endif
