/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-22 16:42:15
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-22 16:57:17
 */
/*
 * @lc app=leetcode.cn id=1189 lang=cpp
 *
 * [1189] “气球” 的最大数量
 */

// @lc code=start
class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        unordered_map<char, int> mm;
        for (auto i : text)
        {
            mm[i] += 1;
        }
        mm['o'] /= 2;
        mm['l'] /= 2;
        return min(mm['b'], min(mm['a'], min(mm['l'], min(mm['o'], mm['n']))));
    }
};
// @lc code=end
