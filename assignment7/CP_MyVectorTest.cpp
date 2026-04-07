#include <iostream>
#include <algorithm>
#include <stdexcept>
#include "MyVector.h"
#include "CP_MyVectorTest.h"

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

static void gb_t1()
{
    cout << "\n[T1] push_back / size / capacity" << endl;
    MyVector<int> v;
    gb_check("T1.1 empty size=0",      v.size() == 0);
    gb_check("T1.2 empty capacity=0",  v.capacity() == 0);
    gb_check("T1.3 empty() == true",   v.empty() == true);

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    gb_check("T1.4 size=3 after 3 pushes", v.size() == 3);
    gb_check("T1.5 capacity >= 3", v.capacity() >= 3);
    gb_check("T1.6 v[0]=10", v[0] == 10);
    gb_check("T1.7 v[2]=30", v[2] == 30);
}


static void gb_t2()
{
    cout << "\n[T2] operator[] / at() / reserve / resize" << endl;
    MyVector<int> v;
    for(int i = 0; i < 5; i++) v.push_back(i*10);

    v[2] = 999;
    gb_check("T2.1 operator[] write", v[2] == 999);
    gb_check("T2.2 v[0] not changed", v[0] == 0);
    gb_check("T2.3 at(1) = 10", v.at(1) == 10);

    bool threw = false;
    try { v.at(10); } catch(const out_of_range&){ threw = true; }
    gb_check("T2.4 at(10) throws out_of_range", threw);

    v.reserve(100);
    gb_check("T2.5 capacity >= 100 after reserve", v.capacity() >= 100);
    gb_check("T2.6 size unchanged after reserve",  v.size() == 5);

    v.resize(8, 77);
    gb_check("T2.7 size=8 after resize", v.size() == 8);
    gb_check("T2.8 new element = 77",  v[7] == 77);
    gb_check("T2.9 old element preserved", v[0] == 0);
}


static void gb_t3()
{
    cout << "\n[T3] pop_back / clear" << endl;
    MyVector<int> v;
    v.push_back(1); v.push_back(2); v.push_back(3);
    int cap = v.capacity();

    v.pop_back();
    gb_check("T3.1 size=2 after pop_back", v.size() == 2);
    gb_check("T3.2 capacity unchanged", v.capacity() == cap);
    gb_check("T3.3 last element is now v[1]=2", v[1] == 2);

    v.clear();
    gb_check("T3.4 size=0 after clear", v.size() == 0);
    gb_check("T3.5 capacity unchanged after clear", v.capacity() == cap);
    gb_check("T3.6 empty() == true", v.empty() == true);
}


static void gb_t4()
{
    cout << "\n[T4] copy constructor / operator=" << endl;
    MyVector<int> a;
    a.push_back(1); a.push_back(2); a.push_back(3);

    MyVector<int> b(a);   
    gb_check("T4.1 copy size=3", b.size() == 3);
    gb_check("T4.2 copy b[0]=1", b[0] == 1);
    b[0] = 99;
    gb_check("T4.3 deep copy: a[0] still 1", a[0] == 1);

    MyVector<int> c;
    c = a;   
    gb_check("T4.4 assign c[0]=1", c[0] == 1);
    c[0] = 88;
    gb_check("T4.5 deep copy: a[0] still 1", a[0] == 1);
}


static void gb_t5()
{
    cout << "\n[T5] iterators (std::sort and std::find)" << endl;
    MyVector<int> v;
    int arr[] = {5,3,8,1,9,2};
    for(int i = 0; i < 6; i++) v.push_back(arr[i]);

    sort(v.begin(), v.end());
    gb_check("T5.1 sorted: v[0]=1", v[0] == 1);
    gb_check("T5.2 sorted: v[5]=9", v[5] == 9);

    int* it = find(v.begin(), v.end(), 5);
    gb_check("T5.3 find(5) found",  it != v.end() && *it == 5);

    it = find(v.begin(), v.end(), 99);
    gb_check("T5.4 find(99) not found", it == v.end());
}

void gb_testMyVector()
{
    g_pass = 0; g_fail = 0;
    cout << "========================================" << endl;
    cout << "MyVector<T> Unit Test (5 situations)" << endl;
    cout << "========================================" << endl;

    gb_t1(); gb_t2(); gb_t3(); gb_t4(); gb_t5();

    cout << "\n========================================" << endl;
    cout << "Results: " << g_pass << " pass, "
         << g_fail << " fail, "
         << g_pass+g_fail << " total" << endl;
    if(g_fail == 0)
        cout << "All tests passed!" << endl;
    cout << "========================================" << endl;
}
