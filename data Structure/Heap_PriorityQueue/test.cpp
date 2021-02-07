#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

void _swap(int& lt, int& rt) {
    auto tmp = lt;
    lt = rt;
    rt = tmp;
}

int main()
{
    vector<int> arr { 1, 2, 3, 4, 5 };
    cout << "*arr.begin() = " << *arr.begin() << '\n';
    cout << "*(arr.end() - 1) = " << *(arr.end() - 1) << '\n';
    cout << "arr.cbegin() = " << *arr.cbegin() << '\n';
    cout << "arr.cend() - 1 = " << *(arr.cend() - 1) << '\n';
    cout << "arr.crbegin() = " << *arr.crbegin() << '\n';
    cout << "arr.crend() = " << *arr.crend() << std::endl;

    cout << "first : last = " << *arr.begin() << ':' << *arr.rbegin() << endl;
    _swap(*arr.begin(), *arr.rbegin());
    cout << "first : last = " << *arr.begin() << ':' << *arr.rbegin() << endl;

}