#include <iostream>
#include <algorithm>
#include "MyVector.h"
#include "CP_MyVectorDemo.h"

using namespace std;

static void gb_show(const char* label, const MyVector<int>& v)
{
    cout << label << "  size=" << v.size()
         << " capacity=" << v.capacity() << "  [";
    for(int i = 0; i < v.size(); i++){
        if(i) cout << ", ";
        cout << v[i];
    }
    cout << "]" << endl;
}

static void gb_demo1(const MyVector<int>& input)
{
    cout << "\n--- Demo 1: Capacity growth during push_back ---" << endl;
    MyVector<int> v;
    int prevCap = 0;
    for(int i = 0; i < input.size(); i++){
        v.push_back(input[i]);
        if(v.capacity() != prevCap){
            cout << "  pushed " << input[i]
                 << "  -> size=" << v.size()
                 << " capacity=" << v.capacity()
                 << " (reallocated)" << endl;
            prevCap = v.capacity();
        }
    }
    gb_show("Final:", v);
}

static void gb_demo2(const MyVector<int>& input)
{
    cout << "\n--- Demo 2: Sort user input via begin()/end() ---" << endl;
    MyVector<int> v(input);   
    gb_show("Before sort:", v);
    sort(v.begin(), v.end());
    gb_show("After sort: ", v);
}

static void gb_demo3(const MyVector<int>& input)
{
    cout << "\n--- Demo 3: Search with std::find ---" << endl;
    gb_show("Vector:", input);
    int target;
    cout << "  Enter value to search: ";
    cin >> target;
    const int* it = find(input.begin(), input.end(), target);
    if(it != input.end())
        cout << "  Found " << target
             << " at index " << (it - input.begin()) << endl;
    else
        cout << "  " << target << " not found." << endl;
}

static void gb_demo4(const MyVector<int>& input)
{
    cout << "\n--- Demo 4: resize and pop_back ---" << endl;
    MyVector<int> v(input);
    gb_show("Original:", v);

    int fill;
    cout << "  Enter fill value to add 3 more elements: ";
    cin >> fill;
    v.resize(v.size() + 3, fill);
    gb_show("After resize:", v);

    v.pop_back();
    gb_show("After pop_back:", v);

    v.clear();
    cout << "  After clear: size=" << v.size()
         << " capacity=" << v.capacity() << endl;
}

void gb_runDemo()
{
    cout << "========================================" << endl;
    cout << "MyVector<int> Interactive Demo" << endl;
    cout << "========================================" << endl;

    int n = 0;
    cout << "Enter count n: ";
    cin >> n;
    if(n <= 0){ cout << "n must be positive." << endl; return; }
    cout << "Enter " << n << " integers: ";

    MyVector<int> input;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        input.push_back(x);
    }
    cout << "Your input: ";
    gb_show("", input);

    gb_demo1(input);
    gb_demo2(input);
    gb_demo3(input);
    gb_demo4(input);

    cout << "\n========================================" << endl;
    cout << "Demo done." << endl;
    cout << "========================================" << endl;
}
