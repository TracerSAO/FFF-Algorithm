#ifndef MAXHeap_H
#define MAXHeap_H

/**
 * 实现策略：std::vector<> -> self::array<>
 * 1. 先采用 STL 中 vector container
 * 2. 再编写完毕后，再自定 vector container，进行替换 —— 练习内存管理
*/

#include <vector>
#include <utility>
#include <cstdio>

template <typename T>
class MAXHeap {
public:
    MAXHeap() = default;
    MAXHeap(const std::initializer_list<T>& ll);
    MAXHeap(const std::vector<T>& ll);
    // MAXHeap(const MAXHeap& MAXHeap);
    // MAXHeap& operator=(const MAXHeap& MAXHeap);
    // ~MAXHeap();

    // 增 - 删 - 改 - 查
    void add(const T& value);

    // 以下三个成员函数需要添加对于 “异常的处理”，即：判空的操作
    // 因为使用的 GP ，所以无法像 Linux API 那样，直接将错误抛出为 -1
    // 具体的实现方案，暂未想到，待后面填坑！
    const T& findMax() const;
    T        extractMax();
    T        extract_add(const T& value);

    bool isEmpty() const;
    int  size() const;
    
    // 临时添加
    auto begin() {
        return arrHeap.begin();
    }
    auto end() {
        return arrHeap.end();
    }

private:
    int _parent(int index) const;
    int _leftChild(int index) const;
    int _rightChild(int index) const;

    // 上浮
    void _siftUp(int index);
    // 下沉
    void _siftDown(int index);

    void _swap(T& lt, T& rt);

private:
    std::vector<T> arrHeap;
};


template <typename T>
MAXHeap<T>::MAXHeap(const std::initializer_list<T>& ll)
{
    for (auto it : ll) {
        arrHeap.push_back(it);
        _siftUp(arrHeap.size() - 1);
    }
}

template <typename T>
MAXHeap<T>::MAXHeap(const std::vector<T>& ll)
{
    arrHeap = ll;

    int k = size() - 1;
    k = _parent(k);
    for (int i = k; i >= 0; i--)
        _siftDown(i);
}

template <typename T>
void MAXHeap<T>::add(const T& val)
{
    arrHeap.push_back(val);
    _siftUp(arrHeap.size() - 1);
}

template <typename T>
const T& MAXHeap<T>::findMax() const { return arrHeap[0]; }

template <typename T>
T MAXHeap<T>::extractMax()
{
    T tmp = arrHeap[0];
    _swap(*arrHeap.begin(), *arrHeap.rbegin());
    arrHeap.pop_back();
    _siftDown(0);

    return tmp;
}

template <typename T>
T MAXHeap<T>::extract_add(const T& val)
{
    T tmp = arrHeap[0];
    arrHeap[0] = val;
    _siftDown(0);

    return tmp;
}

template <typename T>
bool MAXHeap<T>::isEmpty() const { return arrHeap.size() == 0 ? true : false; }

template <typename T>
int MAXHeap<T>::size() const { return arrHeap.size(); }

/**
 * 默认 index(下标) 从零开始
*/
template <typename T>
int MAXHeap<T>::_parent(int index) const {
    return (index - 1) / 2;
}

template <typename T>
int MAXHeap<T>::_leftChild(int index) const {
    return 2 * index + 1;
}

template <typename T>
int MAXHeap<T>::_rightChild(int index) const {
    return 2 * index + 2;
}

template <typename T>
void MAXHeap<T>::_siftUp(int index)
{
    while (0 < index) {
        int k = _parent(index);
        if (arrHeap[index] > arrHeap[k]) {
            _swap(arrHeap[index], arrHeap[k]);
        }
        index = k;
    }
}

template <typename T>
void MAXHeap<T>::_siftDown(int index)
{
    // 即使右孩子不成立，那还有左孩子嘞
    while (_leftChild(index) < size()) {
        int k = _leftChild(index);
        if (_rightChild(index) < size() && arrHeap[_rightChild(index)] > arrHeap[k])
            k = _rightChild(index);
        
        if (arrHeap[index] < arrHeap[k]) {
            _swap(arrHeap[index], arrHeap[k]);
            index = k;
        }
        else break;
    }
}

template <typename T>
void MAXHeap<T>::_swap(T& lt, T& rt)
{
    auto tmp = lt;
    lt = rt;
    rt = tmp;
}

#endif // MAXHeap.h