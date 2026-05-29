#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "CP_IntSorter.h"

using namespace std;

template <class T>
void gt_showVector(const vector<T>& v)
{
    cout << "size=" << v.size() << " capacity=" << v.capacity() << endl;
    cout << "Contents:" << v.size();
    for(int i = 0; i < (int)v.size(); i++)
        cout << ":[" << i << "] " << v[i];
    cout << endl;
}

template <class T>
void gt_showSet(const set<T>& s)
{
    cout << "Set Contents:" << s.size();
    int i = 0;
    typename set<T>::iterator it;
    for(it = s.begin(); it != s.end(); it++, i++)
        cout << ":[" << i << "] " << *it;
    cout << endl;
}

void gb_readInput(vector<int>& v)
{
    int n = 0;
    cout << "Enter count n: ";
    cin >> n;
    if(n <= 0){
        cout << "n must be positive." << endl;
        return;
    }
    cout << "Enter " << n << " integers: ";
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
}

void gb_sortNoDedup(const vector<int>& v)
{
    cout << "\n--- Sort with algorithm::sort (keep duplicates) ---" << endl;
    vector<int> tmp = v;   
    cout << "Before: ";
    gt_showVector(tmp);
    sort(tmp.begin(), tmp.end());
    cout << "After:  ";
    gt_showVector(tmp);
}

void gb_sortDedup(const vector<int>& v)
{
    cout << "\n--- Sort with set (remove duplicates) ---" << endl;
    set<int> s(v.begin(), v.end());
    cout << "Result: ";
    gt_showSet(s);
}

void gb_run()
{
    vector<int> v;
    gb_readInput(v);
    if(v.empty()) return;

    cout << "\nOriginal input: ";
    gt_showVector(v);

    gb_sortNoDedup(v);
    gb_sortDedup(v);
}
