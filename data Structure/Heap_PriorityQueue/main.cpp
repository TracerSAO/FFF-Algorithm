#include "MaxHeap.h"
#include <vector>
#include <random>
#include <ctime>
#include <cstdio>

int main()
{
    std::default_random_engine e(time(0));
    std::uniform_int_distribution<int> u(0, 100);

    int num = 20;
    std::vector<int> arr;
    for (int i = 0; i < num; i++)
        arr.push_back(u(e));

    MAXHeap<int> maxHeap;
    for (int i = 0; i < num; i++)
        maxHeap.add(arr[i]);
    for (int i = 0; i < num; i++) {
        arr[i] = maxHeap.extractMax();
    }

    for (int i = 1; i < num; i++) {
        if (arr[i] > arr[i - 1]) {
            printf("MAXHeap is Error!\n");
            return 0;
        }
    }

    printf("MAXHeap is OK :)\n");
    for (int i = 0; i < num; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}