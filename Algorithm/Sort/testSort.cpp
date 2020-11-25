#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include "Sort.h"

template <typename T> void setRandomVector(std::vector<T>& );

int main()
{
    Sort<int> testsort;
    std::vector<int> _array(30);
    
    setRandomVector(_array);

    // testsort.BubbleSort(_array);
    // testsort.InsertSort(_array);
    testsort.ShellSort(_array);

    std::cout << "Sequence order: ";
    for (auto it = _array.begin(); it != _array.end(); it++)
        std::cout << *it << ' ';
    std::cout << std::endl;

    return 0;
}

template <typename T>
void setRandomVector(std::vector<T>& _array)
{
    std::uniform_int_distribution<T> u(0, _array.size());
    std::default_random_engine e(time(0));

    std::cout << "Random Order: ";
    for (auto it = _array.begin(); it != _array.end(); it++)
    {
        *it = u(e);
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}
