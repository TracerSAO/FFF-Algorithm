#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <vector>

class Sort
{
public:
    template <typename T>
    bool BubbleSort(std::vector<T>& _array);
private:
    template <typename T>
    void swap(T& left, T& right);
};

/**
 * Function: Exchange the values of the two elements
 * Note: void
 * Time: 11/24/2020
*/
template <typename T>
void
swap(T& left, T& right)
{
    T tmp = left;
    left = right;
    right = tmp;
}

/**
 * Function: Bubble Sort
 * Note: 返回值为 bool，默认执行时，只返回 true，
 *       后续，会添加待处理元素类型错误处理 —— 若元素类型不支持 比较 运算则返回 false
 * Time: 11/24/2020
*/
template <typename T>
bool
Sort::BubbleSort(std::vector<T>& _array)
{
    if (_array.size() == 0 || _array.size() == 1)
        return true;
    
    for (auto who = _array.end() - 1; who != _array.begin(); who--)
    {
        for (auto xVSwho = _array.begin(); xVSwho != who; xVSwho++)
        {
            if (*xVSwho > *(xVSwho + 1))
                swap(*xVSwho, *(xVSwho));
        }
    }
    return true;
}



#endif  //SORT_H