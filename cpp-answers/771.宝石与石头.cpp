/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-19 21:59:46
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-19 22:03:31
 */
/*
 * @lc app=leetcode.cn id=771 lang=cpp
 *
 * [771] 宝石与石头
 */

// @lc code=start
class Solution
{
public:
    int numJewelsInStones(string J, string S)
    {
        unordered_map<char, int> mp;
        for (auto c : S)
            mp[c]++;
        int res = 0;
        for (auto c : J)
            res += mp[c];
        return res;
    }
};
// @lc code=end
