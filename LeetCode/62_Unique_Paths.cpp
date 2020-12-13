/*

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

*/

/*
Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
Example 3:

Input: m = 7, n = 3
Output: 28
Example 4:

Input: m = 3, n = 3
Output: 6
 

Constraints:

1 <= m, n <= 100
It's guaranteed that the answer will be less than or equal to 2 * 109.

*/

#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int width_, int height_) {
        if (1 == width_ || 1 == height_)	return 1;

	vector<int> top_list(width_, 1);
	vector<int> bottom_list(width_);

	for (int NO = 1; NO < height_; NO++)
	{
		bottom_list[0] = top_list[0];
		for (int it = 1; it < width_; it++)
		{
			bottom_list[it] = bottom_list[it - 1] + top_list[it];
		}
		top_list = bottom_list;
	}

	return top_list[width_ - 1];
    }
};