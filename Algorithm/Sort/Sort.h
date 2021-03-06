#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <vector>

template <typename T>
class Sort
{
public:
    bool BubbleSort(std::vector<T>& _array);
    bool InsertSort(std::vector<T>& _array);
    bool ShellSort(std::vector<T>& _array);

private:
    void swap(T& left, T& right);
};

/**
 * Function: Exchange the values of the two elements
 * Note: void
 * Time: 11/24/2020
*/
template <typename T> void
Sort<T>::swap(T& left, T& right)
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
template <typename T> bool
Sort<T>::BubbleSort(std::vector<T>& _array)
{
    if (_array.size() == 0 || _array.size() == 1)
        return true;
    
    for (auto who = _array.end() - 1; who != _array.begin(); who--)
    {
        for (auto xVSwho = _array.begin(); xVSwho != who; xVSwho++)
        {
            if (*xVSwho > *(xVSwho + 1))
                swap(*xVSwho, *(xVSwho + 1));
        }
    }
    return true;
}

/**
 * Function: Insert Sort
 * Note: void
 * Time: 11/24/2020
*/
template <typename T> bool
Sort<T>::InsertSort(std::vector<T>& _array)
{
    if (_array.size() == 1 || _array.size() == 0)
        return true;

    for (int field = 1; field < _array.size(); field++)
    {
        for (int subset = field; subset > 0; subset--)
        {
            if (_array[subset] < _array[subset - 1])
            {
                swap(_array[subset], _array[subset - 1]);
            }
        }
    }
    return true;
}


/**
 * Function: Shell Sort
 * Note: 尚未完全理解，下列的实现，采用的《算法》 一书中的实现方式，
 *      其中的元素遍历方式有点过于诡异，不是很能清楚的理解意图
 *      对于 希尔排序 会对有序度较高的数组产生的消极影响暂未分析
 * Time: 11/25/2020 
*/
template <typename T> bool
Sort<T>::ShellSort(std::vector<T>& _array)
{
    if (_array.size() == 1 || _array.size() == 0)
        return true;

    int H = _array.size();
    int h = 1;
    while (h < H/3) h = 3 * h + 1;
    while (h >= 1)
    {
        for (int i = h; i < H; i++)
        {
            for (int j = i; j >= h && (_array[j] < _array[j-h] ? 1:0); j -= h)
            {
                swap(_array[j-h], _array[j]);
            }
        }
        h /= 3;
    }

    return true;
}

#endif  //SORT_H