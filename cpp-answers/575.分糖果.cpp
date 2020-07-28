/*
 * @Author: your name
 * @Date: 2020-06-13 22:38:55
 * @LastEditTime: 2020-06-13 22:42:32
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \undefinede:\leetcode刷题\575.分糖果.cpp
 */
/*
 * @lc app=leetcode.cn id=575 lang=cpp
 *
 * [575] 分糖果
 */

// @lc code=start
class Solution
{
public:
    int distributeCandies(vector<int> &candies)
    {
        unordered_set<int> st(candies.begin(), candies.end());
        return min(st.size(), candies.size() / 2);
    }
};
// @lc code=end
