#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "CP_IntSorterTest.h"

using namespace std;

static int g_pass = 0;
static int g_fail = 0;

static void gb_check(const char* name, bool ok)
{
    if(ok){
        cout << "[PASS] " << name << endl;
        g_pass++;
    } else {
        cout << "[FAIL] " << name << endl;
        g_fail++;
    }
}

static void gb_checkBoth(const char* name,
                          vector<int> input,
                          vector<int> expSort,
                          vector<int> expDedup)
{
    
    vector<int> tmp = input;
    sort(tmp.begin(), tmp.end());
    string s1 = string(name) + " [sort]";
    gb_check(s1.c_str(), tmp == expSort);

    set<int> st(input.begin(), input.end());
    vector<int> res(st.begin(), st.end());
    string s2 = string(name) + " [dedup]";
    gb_check(s2.c_str(), res == expDedup);
}

static void gb_test1()
{
    cout << "\n[T1] general case with duplicates" << endl;
    int a[] = {5,3,8,3,1,8,2,5};
    int es[] = {1,2,3,3,5,5,8,8};
    int ed[] = {1,2,3,5,8};
    gb_checkBoth("T1",
        vector<int>(a, a+8),
        vector<int>(es, es+8),
        vector<int>(ed, ed+5));
}


static void gb_test2()
{
    cout << "\n[T2] already sorted" << endl;
    int a[] = {1,2,3,4,5};
    vector<int> v(a, a+5);
    gb_checkBoth("T2", v, v, v);
}

static void gb_test3()
{
    cout << "\n[T3] reverse sorted" << endl;
    int a[] = {9,7,5,3,1};
    int es[] = {1,3,5,7,9};
    vector<int> ve(es, es+5);
    gb_checkBoth("T3", vector<int>(a,a+5), ve, ve);
}

static void gb_test4()
{
    cout << "\n[T4] all elements identical" << endl;
    int a[] = {7,7,7,7};
    int es[] = {7,7,7,7};
    int ed[] = {7};
    gb_checkBoth("T4",
        vector<int>(a,a+4),
        vector<int>(es,es+4),
        vector<int>(ed,ed+1));
}

static void gb_test5()
{
    cout << "\n[T5] single element" << endl;
    int a[] = {42};
    vector<int> v(a,a+1);
    gb_checkBoth("T5", v, v, v);
}

static void gb_test6()
{
    cout << "\n[T6] no duplicates" << endl;
    int a[] = {4,1,7,2,9,3};
    int es[] = {1,2,3,4,7,9};
    vector<int> ve(es,es+6);
    gb_checkBoth("T6", vector<int>(a,a+6), ve, ve);
}

void gb_testIntSorter()
{
    g_pass = 0; g_fail = 0;
    cout << "========================================" << endl;
    cout << "CP_IntSorter Test (6 situations)" << endl;
    cout << "========================================" << endl;

    gb_test1();
    gb_test2();
    gb_test3();
    gb_test4();
    gb_test5();
    gb_test6();

    cout << "\n========================================" << endl;
    cout << "Results: " << g_pass << " pass, "
         << g_fail << " fail, "
         << g_pass+g_fail << " total" << endl;
    if(g_fail == 0)
        cout << "All tests passed!" << endl;
    cout << "========================================" << endl;
}
