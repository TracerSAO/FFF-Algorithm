/**
 * 217. Contains Duplicate
 * 
 * Given an array of integers, find if the array contains any duplicates.
 * Your function should return true if any value appears at least twice in the array, 
 *      and it should return false if every element is distinct.
*/

/*
    Example 1:
    Input: [1,2,3,1]
    Output: true

    Example 2:
    Input: [1,2,3,4]
    Output: false

    Example 3:
    Input: [1,1,1,3,3,4,3,2,4,2]
    Output: true
*/

#include <iostream>
#include <vector>
#include <map>              // 图
#include <unordered_map>    // 哈希

using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums_) {
		/* method 1th - use map */
        //map<int, char> elemList;
		//for (auto it : nums_)
		//{
		//	if (elemList.find(it) != elemList.end())
		//		return true;
		//	else
		//		elemList[it] = ' ';
		//}
		//return false;

        /* method 2th - use hash (slightly faster than map...) */
		unordered_map<int, bool> elemList;
		for (auto it : nums_)
		{
			if (elemList.find(it) != elemList.end())
				return true;
			else elemList.insert(make_pair(it, 1));
		}
		return false;
	}
};

/*
    Result:
    Map average:  130 ms
    Hash average: 75  ms

    yuZhou:
        For faster algorithms, no idea at all for now :(
*/

int main()
{
    vector<int> list_ = { 1,1,1,3,3,4,3,2,4,2 };
    Solution solu;
    solu.containsDuplicate(list_) ? cout << "true" : cout << "false";
    cout << endl;

    return 1;
}

/*
    One more thing:
        这道题要想正确的解出来确实没有什么难度，但真正的难的是找到时间复杂度最小的那种算法！
        虽然我目前找不出来更优的解法，但是，对于为什么自己的算法会这么慢，我还是知道一些原因，
        
        算法上采用的就是普通的循环跌打判断，这一步就我目前的知识而言，绝对不可能还有更快的操作
        这里它慢，是慢在了我使用的数据结构上！

        我解题使用的是 map 和 hash 两种数据结构。
        如果这要说，map 和 hash 的 find 都不会慢，
        一个是具有树一样的二分搜索速度，一个压根就不是去找，而是直接去算，更是快的不行。

        但，时间的消耗就是在那里放着，
        真正消耗时间的：
            对 map 而言是 map 的插入操作，图是 like tree，树结构中，只有最初的二叉树会在插入上比较快；
                其他类型都是要对自身的结构进行维护，所以，会慢上很多。
            对 hash，我是有点搞不懂了，hash 是使用散列算法，去直接计算每个元素的唯一地址，
                结果 hash 也就只是比 map 快乐一些，但还不是很快，
                emmm？？？去看看 hash 的原理去！

*/