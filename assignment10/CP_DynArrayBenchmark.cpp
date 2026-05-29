#include <iostream>
#include <chrono>
#include <iomanip>
#include <algorithm>
using namespace std;
#include "CP_DListRaw.h"
#include "CP_DListSmart.h"

static double sf_benchRawPush(int n)
{
    auto start = chrono::high_resolution_clock::now();
    CP_DListRaw<int> list;
    for (int i = 0; i < n; i++) list.mb_pushBack(i);
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration<double, milli>(end - start).count();
}

static double sf_benchSmartPush(int n)
{
    auto start = chrono::high_resolution_clock::now();
    CP_DListSmart<int> list;
    for (int i = 0; i < n; i++) list.mb_pushBack(i);
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration<double, milli>(end - start).count();
}

static double sf_benchRawPop(int n)
{
    CP_DListRaw<int> list;
    for (int i = 0; i < n; i++) list.mb_pushBack(i);
    auto start = chrono::high_resolution_clock::now();
    while (!list.mb_empty()) list.mb_popFront();
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration<double, milli>(end - start).count();
}

static double sf_benchSmartPop(int n)
{
    CP_DListSmart<int> list;
    for (int i = 0; i < n; i++) list.mb_pushBack(i);
    auto start = chrono::high_resolution_clock::now();
    while (!list.mb_empty()) list.mb_popFront();
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration<double, milli>(end - start).count();
}

static void sf_drawBar(const string &label, double ms, double maxMs)
{
    int barLen = (int)(ms / maxMs * 40);
    if (barLen < 1) barLen = 1;
    if (barLen > 40) barLen = 40;
    cout << setw(16) << label << " |";
    for (int i = 0; i < barLen; i++) cout << "#";
    cout << " " << fixed << setprecision(3) << ms << " ms" << endl;
}

int main(int argc, char* argv[])
{
    cout << "================================================" << endl;
    cout << "  Raw Pointer vs Smart Pointer DList Benchmark" << endl;
    cout << "================================================" << endl;

    int sizes[] = {1000, 5000, 10000, 50000, 100000, 500000};
    int numSizes = 6;

    cout << "\n" << setw(10) << "N"
         << setw(14) << "Raw_push"
         << setw(14) << "Smart_push"
         << setw(10) << "Ratio"
         << setw(14) << "Raw_pop"
         << setw(14) << "Smart_pop"
         << setw(10) << "Ratio"
         << endl;
    cout << string(86, '-') << endl;

    for (int i = 0; i < numSizes; i++)
    {
        int n = sizes[i];
        double rawPush = sf_benchRawPush(n);
        double smartPush = sf_benchSmartPush(n);
        double rawPop = sf_benchRawPop(n);
        double smartPop = sf_benchSmartPop(n);
        double ratioPush = (rawPush > 0.001) ? smartPush / rawPush : 0;
        double ratioPop = (rawPop > 0.001) ? smartPop / rawPop : 0;

        cout << setw(10) << n
             << setw(12) << fixed << setprecision(3) << rawPush << " ms"
             << setw(12) << smartPush << " ms"
             << setw(9) << setprecision(2) << ratioPush << "x"
             << setw(12) << setprecision(3) << rawPop << " ms"
             << setw(12) << smartPop << " ms"
             << setw(9) << setprecision(2) << ratioPop << "x"
             << endl;
    }

    
    {
        int n = sizes[numSizes - 1];
        double rp = sf_benchRawPush(n);
        double sp = sf_benchSmartPush(n);
        double maxV = max(rp, sp);

        cout << "\n  [N=" << n << "] pushBack:" << endl;
        sf_drawBar("Raw pointer", rp, maxV);
        sf_drawBar("Smart pointer", sp, maxV);
    }

    cout << "\n================================================" << endl;
    cout << "  Code Comparison:" << endl;
    cout << "    CP_DListRaw.h   : raw pointer (new/delete)" << endl;
    cout << "    CP_DListSmart.h : shared_ptr + weak_ptr" << endl;
    cout << "    Smart pointer version eliminates all manual" << endl;
    cout << "    delete calls, preventing memory leaks." << endl;
    cout << "    Raw pointer version is faster due to lower" << endl;
    cout << "    overhead (no reference counting)." << endl;
    cout << "================================================" << endl;

    system("pause");
    return 0;
}
