#include <iostream>
#include <utility>
using namespace std;
#include "CP_DynArrayTest.h"
#include "CP_DynArray.h"
#include "CP_A.h"
#include "CP_DListRaw.h"
#include "CP_DListSmart.h"

void CP_DynArrayTest::mb_check(const string &name, bool condition)
{
    m_totalTests++;
    if (condition)
    {
        m_passedTests++;
        cout << "  [PASS] " << name << endl;
    }
    else
    {
        cout << "  [FAIL] " << name << endl;
    }
}

void CP_DynArrayTest::mb_testDefaultCtor()
{
    cout << "\n===== T1: Default Constructor =====" << endl;
    cout << "--- Create CP_DynArray<int> with no args ---" << endl;
    CP_DynArray<int> p;
    mb_check("default ctor: get()==nullptr", p.mb_get() == nullptr);
    mb_check("default ctor: bool==false", !p);
    cout << "--- p goes out of scope ---" << endl;
}

void CP_DynArrayTest::mb_testPtrCtor()
{
    cout << "\n===== T2: Pointer Constructor =====" << endl;
    cout << "--- Create CP_DynArray<int>(new int(42)) ---" << endl;
    CP_DynArray<int> p(new int(42));
    mb_check("ptr ctor: get()!=nullptr", p.mb_get() != nullptr);
    mb_check("ptr ctor: *p==42", *p == 42);
    mb_check("ptr ctor: bool==true", (bool)p);

    cout << "--- Create CP_DynArray<string>(new string(\"hello\")) ---" << endl;
    CP_DynArray<string> ps(new string("hello"));
    mb_check("ptr ctor<string>: *ps==\"hello\"", *ps == "hello");
    cout << "--- both go out of scope ---" << endl;
}

void CP_DynArrayTest::mb_testMoveCtor()
{
    cout << "\n===== T3: Move Constructor =====" << endl;
    cout << "--- p1(new int(99)), then p2(move(p1)) ---" << endl;
    CP_DynArray<int> p1(new int(99));
    int* raw = p1.mb_get();
    CP_DynArray<int> p2(move(p1));

    mb_check("move ctor: source becomes nullptr", p1.mb_get() == nullptr);
    mb_check("move ctor: target has original ptr", p2.mb_get() == raw);
    mb_check("move ctor: *p2==99", *p2 == 99);
    mb_check("move ctor: source bool==false", !p1);
    cout << "--- both go out of scope ---" << endl;
}


void CP_DynArrayTest::mb_testMoveAssign()
{
    cout << "\n===== T4: Move Assignment =====" << endl;
    cout << "--- p1(new int(10)), p2(new int(20)), p2=move(p1) ---" << endl;
    CP_DynArray<int> p1(new int(10));
    CP_DynArray<int> p2(new int(20));
    int* raw1 = p1.mb_get();

    p2 = move(p1);
    mb_check("move assign: source nullptr", p1.mb_get() == nullptr);
    mb_check("move assign: target has source ptr", p2.mb_get() == raw1);
    mb_check("move assign: *p2==10", *p2 == 10);

    cout << "--- p3 default, p4(new int(30)), p3=move(p4) ---" << endl;
    CP_DynArray<int> p3;
    CP_DynArray<int> p4(new int(30));
    p3 = move(p4);
    mb_check("move assign to empty: *p3==30", *p3 == 30);
    mb_check("move assign to empty: source nullptr", p4.mb_get() == nullptr);
    cout << "--- all go out of scope ---" << endl;
}

void CP_DynArrayTest::mb_testGet()
{
    cout << "\n===== T5: get() =====" << endl;
    CP_DynArray<int> p1;
    mb_check("get() on empty: nullptr", p1.mb_get() == nullptr);

    int* raw = new int(77);
    CP_DynArray<int> p2(raw);
    mb_check("get() returns original ptr", p2.mb_get() == raw);
    mb_check("get() value correct", *p2.mb_get() == 77);
}

void CP_DynArrayTest::mb_testSwap()
{
    cout << "\n===== T6: swap() =====" << endl;
    CP_DynArray<int> p1(new int(111));
    CP_DynArray<int> p2(new int(222));
    int* raw1 = p1.mb_get();
    int* raw2 = p2.mb_get();

    p1.mb_swap(p2);
    mb_check("swap: p1 has p2's old ptr", p1.mb_get() == raw2);
    mb_check("swap: p2 has p1's old ptr", p2.mb_get() == raw1);
    mb_check("swap: *p1==222", *p1 == 222);
    mb_check("swap: *p2==111", *p2 == 111);

    cout << "--- swap with empty ---" << endl;
    CP_DynArray<int> p3;
    CP_DynArray<int> p4(new int(333));
    int* raw4 = p4.mb_get();
    p3.mb_swap(p4);
    mb_check("swap with empty: p3 has ptr", p3.mb_get() == raw4);
    mb_check("swap with empty: p4 is nullptr", p4.mb_get() == nullptr);
}

void CP_DynArrayTest::mb_testWithCPA()
{
    cout << "\n===== T7: With CP_A (observe ctor/dtor) =====" << endl;

    cout << "--- Create CP_DynArray<CP_A>(new CP_A(3)) ---" << endl;
    CP_DynArray<CP_A> p1(new CP_A(3));
    mb_check("CP_A ptr ctor: p1->m_n==3", p1->m_n == 3);

    cout << "--- Move construct p2 from p1 ---" << endl;
    CP_DynArray<CP_A> p2(move(p1));
    mb_check("CP_A move ctor: p1 nullptr", p1.mb_get() == nullptr);
    mb_check("CP_A move ctor: p2->m_n==3", p2->m_n == 3);

    cout << "--- Move assign p3=move(p2) ---" << endl;
    CP_DynArray<CP_A> p3;
    p3 = move(p2);
    mb_check("CP_A move assign: p2 nullptr", p2.mb_get() == nullptr);
    mb_check("CP_A move assign: p3->m_n==3", p3->m_n == 3);

    cout << "--- Swap p3 with p4(new CP_A(7)) ---" << endl;
    CP_DynArray<CP_A> p4(new CP_A(7));
    p3.mb_swap(p4);
    mb_check("CP_A swap: p3->m_n==7", p3->m_n == 7);
    mb_check("CP_A swap: p4->m_n==3", p4->m_n == 3);

    cout << "--- All go out of scope (observe CP_A destructors) ---" << endl;
}

void CP_DynArrayTest::mb_testDListRaw()
{
    cout << "\n===== T8: DList (Raw Pointer) =====" << endl;
    CP_DListRaw<int> list;

    list.mb_pushBack(10);
    list.mb_pushBack(20);
    list.mb_pushBack(30);
    mb_check("raw pushBack: size==3", list.mb_size() == 3);
    mb_check("raw front==10", list.mb_front() == 10);
    mb_check("raw back==30", list.mb_back() == 30);

    list.mb_pushFront(5);
    mb_check("raw pushFront: front==5", list.mb_front() == 5);
    mb_check("raw size==4", list.mb_size() == 4);

    cout << "  Forward:  ";
    list.mb_show();
    cout << "  Reverse:  ";
    list.mb_showReverse();

    list.mb_popFront();
    mb_check("raw popFront: front==10", list.mb_front() == 10);

    list.mb_popBack();
    mb_check("raw popBack: back==20", list.mb_back() == 20);

    list.mb_clear();
    mb_check("raw clear: empty", list.mb_empty());
    mb_check("raw clear: size==0", list.mb_size() == 0);

    bool r = list.mb_popFront();
    mb_check("raw popFront on empty: false", !r);
}

void CP_DynArrayTest::mb_testDListSmart()
{
    cout << "\n===== T9: DList (Smart Pointer) =====" << endl;
    CP_DListSmart<int> list;

    list.mb_pushBack(10);
    list.mb_pushBack(20);
    list.mb_pushBack(30);
    mb_check("smart pushBack: size==3", list.mb_size() == 3);
    mb_check("smart front==10", list.mb_front() == 10);
    mb_check("smart back==30", list.mb_back() == 30);

    list.mb_pushFront(5);
    mb_check("smart pushFront: front==5", list.mb_front() == 5);
    mb_check("smart size==4", list.mb_size() == 4);

    cout << "  Forward:  ";
    list.mb_show();
    cout << "  Reverse:  ";
    list.mb_showReverse();

    list.mb_popFront();
    mb_check("smart popFront: front==10", list.mb_front() == 10);

    list.mb_popBack();
    mb_check("smart popBack: back==20", list.mb_back() == 20);

    list.mb_clear();
    mb_check("smart clear: empty", list.mb_empty());
    mb_check("smart clear: size==0", list.mb_size() == 0);

    bool r = list.mb_popFront();
    mb_check("smart popFront on empty: false", !r);
}

void CP_DynArrayTest::mb_runAll()
{
    m_totalTests = 0;
    m_passedTests = 0;

    cout << "============================================" << endl;
    cout << "   CP_DynArray & DList Test Suite" << endl;
    cout << "============================================" << endl;

    mb_testDefaultCtor();
    mb_testPtrCtor();
    mb_testMoveCtor();
    mb_testMoveAssign();
    mb_testGet();
    mb_testSwap();
    mb_testWithCPA();
    mb_testDListRaw();
    mb_testDListSmart();

    cout << "\n============================================" << endl;
    cout << "  Total: " << m_totalTests
         << "  Passed: " << m_passedTests
         << "  Failed: " << (m_totalTests - m_passedTests) << endl;
    if (m_totalTests == m_passedTests)
        cout << "  ALL TESTS PASSED!" << endl;
    else
        cout << "  SOME TESTS FAILED!" << endl;
    cout << "============================================" << endl;
}
