/*

In the world of Dota2, there are two parties: the Radiant and the Dire.

The Dota2 senate consists of senators coming from two parties. 
Now the senate wants to make a decision about a change in the Dota2 game. 
The voting for this change is a round-based procedure. 
In each round, each senator can exercise one of the two rights:

    1.Ban one senator's right:
        A senator can make another senator lose all his rights in this and all the following rounds.
    2.Announce the victory:
        If this senator found the senators who still have rights to vote are all from the same party, 
        he can announce the victory and make the decision about the change in the game.
 

Given a string representing each senator's party belonging. 
The character 'R' and 'D' represent the Radiant party and the Dire party respectively. 
Then if there are n senators, the size of the given string will be n.

The round-based procedure starts from the first senator to the last senator in the given order. 
This procedure will last until the end of voting. 
All the senators who have lost their rights will be skipped during the procedure.

Suppose every senator is smart enough and will play the best strategy for his own party, 
you need to predict which party will finally announce the victory and make the change in the Dota2 game. 
The output should be Radiant or Dire.

*/



/*

Example 1:

Input: "RD"
Output: "Radiant"
Explanation: The first senator comes from Radiant and he can just ban the next senator's right in the round 1. 
And the second senator can't exercise any rights any more since his right has been banned. 
And in the round 2, the first senator can just announce the victory since he is the only guy in the senate who can vote.
 

Example 2:

Input: "RDD"
Output: "Dire"
Explanation: 
The first senator comes from Radiant and he can just ban the next senator's right in the round 1. 
And the second senator can't exercise any rights anymore since his right has been banned. 
And the third senator comes from Dire and he can ban the first senator's right in the round 1. 
And in the round 2, the third senator can just announce the victory since he is the only guy in the senate who can vote.
 

Note:

The length of the given string will in the range [1, 10,000].

*/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* 正确解法 */
class Solution {
public:
    string predictPartyVictory(string senate) {
        int R = 0, D = 0;
        for (char i : senate)
            if (i == 'R')
                R++;
            else D++;
        int l = senate.size();
        while (R != 0 && D != 0) {
            int i = 0, j = 0;
            for (int c = 0; c < l && R && D; c++) {
                if (senate[c] == 'R') {
                    while (D && senate[j] != 'D')
                        j = (j+1) % l;
                    i = j;
                    senate[j] = '-';
                    D--;
                } else if (senate[c] == 'D') {
                    while (R && senate[i] != 'R')
                        i = (i+1) % l;
                    j = i;
                    senate[i] = '-';
                    R--;
                }
            }
        }
        return D == 0 ? "Radiant" : "Dire";
    }
};

// 一下在是我理解错题意的情况下，所求解的题解，虽然它求解的不是题目的要求，但它是正确的
class _Solution_ {
public:
    string predictPartyVictory(string str) {
        if (2 == str.size() || 1 == str.size())
            return (('R' == str[0]) ? string("Radiant") : string("Dire"));

        vector<bool> flag(str.size(), 0);   // 0 表示没有被禁止 || 1 
        size_t start  = 0, end = str.size() - 1;
        size_t _first = 0, _last = 0;
        size_t Rflag, Dflag;
        for (;;)
        {
            cout << ">>>" << endl;
            flagOutput(flag);
            bool isSecond = 0;
            Rflag = 0, Dflag = 0;

            // 本位操控下一位
            for (size_t it = start; it < end; it++)
            {
                // 已被禁止投票
                if (flag[it]) continue;
                
                // 统计 R/D 阵营人数，用于判断是否终止最外层投票循环
                if ('R' == str[it]) Rflag++;
                if ('D' == str[it]) Dflag++;

                // 定位 有投票权的第二席位参议员 —— 用于接替陪审掉的首席参议员
                if (it != start && 0 == isSecond)
                {
                    _first = it;
                    isSecond = 1;
                }

                // 未被禁止投票，判断下一位参议院和自己属于同一阵营
                // 否则禁止下一位的投票权，是则支持下位（即：不做任何操作）
                size_t tmp = it + 1;
                for (; tmp <= end; tmp++)
                {
                    // 判断下一位参议员是否有投票权
                    if (!flag[tmp])
                    {
                        if (str[it] != str[tmp]) {
                            flag[tmp] = 1;
                            _last = it;   // 定位有效参议院的末尾下标
                            it = tmp;     // 跳过已经没有选举权的参议员
                            break;
                        }
                        _last = tmp;      // 同上
                        it = tmp - 1;
                        break;
                    }
                }
                //if (tmp == end)
                //{
                //    _last = it;
                //    break;
                //}
            }

            // 正确定位到真正有效的末尾参议员
            if (flag[end]) end = _last;

            // 必须要执行的一步：
            // 末尾参议员 审判 首席参议员
            if (str[end] != str[start])
            {
                flag[start] = 1;
                start = _first;
                'R' == str[end] ? Rflag++ : Dflag++;
            }

            flagOutput(flag);
            cout << "<<<" << endl;
            if (0 == Dflag || 0 == Rflag) break;
        }
        return ((0 == Dflag) ? string("Radiant") : string("Dire"));
    }

    void flagOutput(vector<bool>& array_)
    {
        for (auto it : array_)
            cout << it << ' ';
        cout << endl;
    }
};


int main()
{
    Solution solu;
    cout << solu.predictPartyVictory("DDRRR") << endl;

    /*
        D - D - D - R - R - R
        D - D - D - x - R - R   -->  x - D - D - x - R - R
        x - D - D - x - x - R   -->  x - x - D - x - x - R
        x - x - D - x - x - x
    */

    /*
        D - D - R - R - R - R
        D - D - x - R - R - R   -->  x - D - x - R - R - R
        x - D - x - x - R - R   -->  x - x - x - x - R - R
        x - x - x - x - x - x
    */

    // 以上，为理解错误的题解的处理过程
    // 以下，为正确题解的处理过程

    /*
        D - D - R - R - R
        D - D - x - R - R
        D - D - x - x - R
        x - D - x - x - R
        x - D - x - x - x
    */
}