/*
    A sequence of numbers is called a wiggle sequence 
        if the differences between successive numbers strictly alternate between positive and negative. 
    The first difference (if one exists) may be either positive or negative. 
        A sequence with fewer than two elements is trivially a wiggle sequence.
    For example, [1,7,4,9,2,5] is a wiggle sequence 
        because the differences (6,-3,5,-7,3) are alternately positive and negative. 
    In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, 
        the first because its first two differences are positive 
        and the second because its last difference is zero.
    Given a sequence of integers, 
        return the length of the longest subsequence 
        that is a wiggle sequence. 
    A subsequence is obtained by deleting some number of 
        elements (eventually, also zero) from the original sequence, 
        leaving the remaining elements in their original order.
*/

/*
    Example 1:
    Input: [1,7,4,9,2,5]
    Output: 6
    Explanation: The entire sequence is a wiggle sequence.

    Example 2:
    Input: [1,17,5,10,13,15,10,5,16,8]
    Output: 7
    Explanation: There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].

    Example 3:
    Input: [1,2,3,4,5,6,7,8,9]
    Output: 2
*/


#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		// 少于两个元素的也是摆动数列 - 但不包括 两个 元素情况，因为差值可能为 0
		if (1 >= nums.size())
			return nums.size();

		int preview = nums[1] - nums[0];		// 定位已经确定的摆动数列的末尾元素 - 用于新发现的摆动数列的融合判断
		size_t count = 0;						// 统计摆动数列元素个数
		if (preview)	count++;

		for (size_t it = 1; it < nums.size() - 1; it++)
		{
			int tmp = nums[it + 1] - nums[it];
			if (0 == tmp) continue;
			if ((0 < tmp && 0 > preview) || (0 > tmp && 0 < preview) ||
				(0 < tmp && 0 == preview) || (0 > tmp && 0 == preview))
			{
				count++;
				preview = tmp;
			}
		}

		return count + 1;
	}
};

int main()
{
	vector<int> array_ = { 3,3,3,2,5 };
	Solution solu;
	cout << solu.wiggleMaxLength(array_) << endl;
}

// Analysis
/*
		1 - 7 - 4 - 9 - 2 - 5
		  -   +   -   +   -

	    1,17,5,10,13,15,10,5,16,8
		 +  - +  +  +  -  - +  -

		1 3 5 4
		 + + -
*/