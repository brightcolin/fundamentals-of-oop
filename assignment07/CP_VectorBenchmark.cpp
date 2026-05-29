#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "MyVector.h"
#include "CP_VectorBenchmark.h"

using namespace std;

static double gb_ms(clock_t start, clock_t end)
{
    return 1000.0 * (end - start) / CLOCKS_PER_SEC;
}

static void gb_bar(const char* label, double ms, double scale)
{
    int bars = (int)(ms * scale);
    if(bars < 1 && ms > 0) bars = 1;
    if(bars > 40) bars = 40;

    cout << left << setw(12) << label << " |";
    for(int i = 0; i < bars; i++) cout << "#";
    cout << " " << fixed << setprecision(1) << ms << " ms" << endl;
}


template <class VEC>
static void gt_bench(const char* name, int N,
                     double& outPush, double& outAccess, double& outSort)
{
    srand(42);
    clock_t t0 = clock();
    VEC v;
    for(int i = 0; i < N; i++)
        v.push_back(rand() % 1000000);
    clock_t t1 = clock();

    volatile long long sum = 0;
    for(int i = 0; i < (int)v.size(); i++)
        sum += v[i];
    clock_t t2 = clock();

    sort(v.begin(), v.end());
    clock_t t3 = clock();

    outPush   = gb_ms(t0, t1);
    outAccess = gb_ms(t1, t2);
    outSort   = gb_ms(t2, t3);
}

void gb_runBenchmark()
{
    int sizes[] = {100000, 500000, 1000000};
    int nSizes = 3;

    cout << "========================================" << endl;
    cout << "MyVector vs std::vector Benchmark" << endl;
    cout << "(push_back N ints, read all, sort)" << endl;
    cout << "========================================" << endl;

    
    cout << "\n" << left
         << setw(12) << "Container"
         << setw(10) << "N"
         << setw(12) << "push(ms)"
         << setw(12) << "access(ms)"
         << setw(12) << "sort(ms)"
         << "total(ms)" << endl;
    cout << string(70, '-') << endl;

    for(int k = 0; k < nSizes; k++){
        int N = sizes[k];
        double vPush, vAccess, vSort;
        double mPush, mAccess, mSort;

        gt_bench<vector<int>>("std::vector", N, vPush, vAccess, vSort);
        gt_bench<MyVector<int>>("MyVector",  N, mPush, mAccess, mSort);

        cout << left
             << setw(12) << "std::vector"
             << setw(10) << N
             << setw(12) << fixed << setprecision(1) << vPush
             << setw(12) << vAccess
             << setw(12) << vSort
             << vPush+vAccess+vSort << endl;
        cout << left
             << setw(12) << "MyVector"
             << setw(10) << N
             << setw(12) << mPush
             << setw(12) << mAccess
             << setw(12) << mSort
             << mPush+mAccess+mSort << endl;

        
        cout << "\n  [N=" << N << "] push_back comparison:" << endl;
        double maxPush = vPush > mPush ? vPush : mPush;
        double scale   = (maxPush > 0) ? 35.0/maxPush : 1.0;
        gb_bar("std::vector", vPush, scale);
        gb_bar("MyVector",    mPush, scale);

        cout << "\n  [N=" << N << "] sort comparison:" << endl;
        double maxSort = vSort > mSort ? vSort : mSort;
        scale = (maxSort > 0) ? 35.0/maxSort : 1.0;
        gb_bar("std::vector", vSort, scale);
        gb_bar("MyVector",    mSort, scale);
        cout << endl;
    }

    cout << "Conclusion: MyVector performance is close to" << endl;
    cout << "std::vector because both use the same doubling" << endl;
    cout << "strategy and expose raw pointers as iterators." << endl;
    cout << "========================================" << endl;
}
