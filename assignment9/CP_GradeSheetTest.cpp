#include <iostream>
#include <fstream>
using namespace std;
#include "CP_GradeSheetTest.h"

void CP_GradeSheetTest::mb_check(const string &name,bool condition)
{
    m_totalTests++;
    if(condition)
    {
        m_passedTests++;
        cout<<"  [PASS] "<<name<<endl;
    }
    else
    {
        cout<<"  [FAIL] "<<name<<endl;
    }
}

void CP_GradeSheetTest::mb_testAdd()
{
    cout<<"\n===== T1: Add Tests ====="<<endl;

    CP_GradeSheet sheet;
 
    bool r1=sheet.mb_add("2024001",90);
    mb_check("add first student",r1&&sheet.mb_size()==1);
    bool r2=sheet.mb_add("2024002",85);
    mb_check("add second student",r2&&sheet.mb_size()==2);
    bool r3=sheet.mb_add("2024001",70);
    mb_check("add duplicate ID (should fail)",!r3&&sheet.mb_size()==2);
    bool r4=sheet.mb_add("",60);
    mb_check("add empty ID (should fail)",!r4&&sheet.mb_size()==2);

    int g;
    sheet.mb_query("2024001",g);
    mb_check("verify first grade=90",g==90);
}


void CP_GradeSheetTest::mb_testRemove()
{
    cout<<"\n===== T2: Remove Tests ====="<<endl;

    CP_GradeSheet sheet;
    sheet.mb_add("A001",88);
    sheet.mb_add("A002",77);
    sheet.mb_add("A003",66);

    bool r1=sheet.mb_remove("A002");
    mb_check("remove existing student",r1&&sheet.mb_size()==2);
    bool r2=sheet.mb_remove("A999");
    mb_check("remove non-existent (should fail)",!r2&&sheet.mb_size()==2);

    sheet.mb_remove("A001");
    sheet.mb_remove("A003");
    mb_check("remove all until empty",sheet.mb_size()==0);
}

void CP_GradeSheetTest::mb_testModify()
{
    cout<<"\n===== T3: Modify Tests ====="<<endl;

    CP_GradeSheet sheet;
    sheet.mb_add("S01",50);
    sheet.mb_add("S02",60);
    bool r1=sheet.mb_modify("S01",99);
    int g;
    sheet.mb_query("S01",g);
    mb_check("modify existing: 50->99",r1&&g==99);
    bool r2=sheet.mb_modify("S99",80);
    mb_check("modify non-existent (should fail)",!r2);
    sheet.mb_query("S02",g);
    mb_check("other record unchanged",g==60);
}

void CP_GradeSheetTest::mb_testQuery()
{
    cout<<"\n===== T4: Query Tests ====="<<endl;

    CP_GradeSheet sheet;
    sheet.mb_add("Q1",100);
    sheet.mb_add("Q2",0);

    int g;
    bool r1=sheet.mb_query("Q1",g);
    mb_check("query existing: grade=100",r1&&g==100);
    bool r2=sheet.mb_query("Q2",g);
    mb_check("query grade=0",r2&&g==0);
    bool r3=sheet.mb_query("Q999",g);
    mb_check("query non-existent (should fail)",!r3);
    CP_GradeSheet empty;
    bool r4=empty.mb_query("Q1",g);
    mb_check("query on empty sheet (should fail)",!r4);
}


void CP_GradeSheetTest::mb_testClear()
{
    cout<<"\n===== T5: Clear Tests ====="<<endl;

    CP_GradeSheet sheet;
    sheet.mb_add("C1",10);
    sheet.mb_add("C2",20);
    sheet.mb_add("C3",30);

    sheet.mb_clear();
    mb_check("clear: size becomes 0",sheet.mb_size()==0);
    sheet.mb_clear();
    mb_check("clear empty sheet (no crash)",sheet.mb_size()==0);
    sheet.mb_add("C4",40);
    mb_check("add after clear works",sheet.mb_size()==1);
}


void CP_GradeSheetTest::mb_testFile()
{
    cout<<"\n===== T6: File I/O Tests ====="<<endl;

    CP_GradeSheet sheet1;
    sheet1.mb_add("F001",95);
    sheet1.mb_add("F002",87);
    sheet1.mb_add("F003",73);
    bool w=sheet1.mb_writeFile("_test_grade.txt");
    mb_check("write 3 records to file",w);

    CP_GradeSheet sheet2;
    bool r=sheet2.mb_readFile("_test_grade.txt");
    mb_check("read back from file",r&&sheet2.mb_size()==3);


    int g;
    sheet2.mb_query("F001",g);
    bool ok1=(g==95);
    sheet2.mb_query("F002",g);
    bool ok2=(g==87);
    sheet2.mb_query("F003",g);
    bool ok3=(g==73);
    mb_check("data integrity after read",ok1&&ok2&&ok3);

    CP_GradeSheet sheet3;
    bool r2=sheet3.mb_readFile("_no_such_file_xyz.txt");
    mb_check("read non-existent file (should fail)",!r2);

    CP_GradeSheet sheet4;
    sheet4.mb_add("F000",100);
    sheet4.mb_readFile("_test_grade.txt");
    mb_check("read appends to existing data",sheet4.mb_size()==4);
    remove("_test_grade.txt");
}


void CP_GradeSheetTest::mb_testInvalid()
{
    cout<<"\n===== T7: Invalid Input Handling ====="<<endl;

    CP_GradeSheet sheet;
    sheet.mb_add("X1",80);
    bool r1=sheet.mb_add("X1",90);
    mb_check("reject duplicate add",!r1);

    CP_GradeSheet empty;
    bool r2=empty.mb_remove("X1");
    mb_check("remove from empty (should fail)",!r2);

    bool r3=empty.mb_modify("X1",50);
    mb_check("modify on empty (should fail)",!r3);

    bool r4=empty.mb_writeFile("_test_empty.txt");
    mb_check("write empty sheet (should succeed)",r4);

    CP_GradeSheet sheet2;
    bool r5=sheet2.mb_readFile("_test_empty.txt");
    mb_check("read empty file (should warn)",!r5&&sheet2.mb_size()==0);

    remove("_test_empty.txt");
}

void CP_GradeSheetTest::mb_runAll()
{
    m_totalTests=0;
    m_passedTests=0;

    cout<<"============================================"<<endl;
    cout<<"   CP_GradeSheet Automated Test Suite"<<endl;
    cout<<"============================================"<<endl;

    mb_testAdd();
    mb_testRemove();
    mb_testModify();
    mb_testQuery();
    mb_testClear();
    mb_testFile();
    mb_testInvalid();

    cout<<"\n============================================"<<endl;
    cout<<"  Total: "<<m_totalTests
        <<"  Passed: "<<m_passedTests
        <<"  Failed: "<<(m_totalTests-m_passedTests)<<endl;
    if(m_totalTests==m_passedTests)
        cout<<"  ALL TESTS PASSED!"<<endl;
    else
        cout<<"  SOME TESTS FAILED!"<<endl;
    cout<<"============================================"<<endl;
}
