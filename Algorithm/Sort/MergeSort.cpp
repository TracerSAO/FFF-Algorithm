#include <utility>
#include <algorithm>
#include <vector>
#include <random>
#include <ctime>
#include <iostream>

using namespace std;

class Solution {
public:
    static vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // NO.1 先对多维数组进行排序
        sort(intervals);

        vector<vector<int>> tmp;
        int* first = &intervals.begin()->at(0), * second = &intervals.begin()->at(1);
        // NO.2 再对进行合并处理
        for (auto it = intervals.begin(); it != intervals.end(); it++) {
            if (it + 1 == intervals.end()) {
                tmp.push_back({ *first, *second });
                break;
            }

            if (*second < (it + 1)->at(0)) {
                tmp.push_back({ *first, *second });

                first = &(it + 1)->at(0);
                second = &(it + 1)->at(1);
            }
            else if (*second <= (it + 1)->at(1)) {
                second = &(it + 1)->at(1);
            }
        }

        return tmp;
    }

    static void sort(vector<vector<int>>& arr) {
        __mergeSort(arr, 0, arr.size() - 1);
    }

    private:
    static void __mergeSort(vector<vector<int>>& arr, size_t lt, size_t rt) {
        if (lt >= rt) return;

        size_t mid = lt / 2 + rt / 2;
        __mergeSort(arr, lt, mid);
        __mergeSort(arr, mid + 1, rt);

        __mergeFoo(arr, lt, mid, rt);
    }

    /**
    * arr[ lt, ... , mid ] vs arr[ mid + 1, ... , rt ]
    */
    static void __mergeFoo(vector<vector<int>>& arr, size_t lt, size_t mid, size_t rt) {
        // 确定临时数组的长度
        vector<vector<int>> tmp(rt - lt + 1);   

        size_t i = lt, j = mid + 1;
        for (size_t k = 0; k < tmp.size(); k++) {
            if (i > mid) tmp[k] = arr[j++];
            else if (j > rt)  tmp[k] = arr[i++];
            else if (arr[j].at(0) < arr[i].at(0)) tmp[k] = arr[j++];
            else                      tmp[k] = arr[i++];
        }

        for (size_t i = lt; i <= rt; i++)
            arr[i] = tmp[i - lt];
    }

};

void vPrintf(vector<vector<int>>& arr) {
	for_each(arr.begin(), arr.end(),
		[](vector<int>& tmp) {
			cout << '{';
			for_each(tmp.begin(), tmp.end(),
				[](int& val) {
					cout << val << '_';
				});
			cout << '}';
		});
}

#define N 12

/*
输入: intervals = [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
*/

int main()
{
    vector<vector<int>> arr = { {1, 3}, {2, 6}, {8, 10}, {15, 18} };
    vPrintf(arr);

    //std::default_random_engine e(time(0));
    //std::uniform_int_distribution<size_t> u(0, 20);

    //vector<vector<int>> arr;
    //for (int i = 0; i < N; i++) {
    //    vector<int> tmp;
    //    for (int j = 0; j < 2; j++)
    //        tmp.push_back(u(e));
    //    arr.push_back(tmp);
    //}
    //vPrintf(arr);

    cout << endl;
    vector<vector<int>> tmp = Solution::merge(arr);
    vPrintf(tmp);
}

