/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-21 07:57:00
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-21 07:58:53
 */
/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉K位数字
 */

// @lc code=start
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        string res;
        int n = num.size();
        int m = n - k;
        for (auto &c : num)
        {
            while (k && res.size() && res.back() > c)
            {
                res.pop_back();
                k--;
            }
            res.push_back(c);
        }
        res.resize(m);
        //去除前导0
        while (!res.empty() && res[0] == '0')
        {
            res.erase(res.begin());
        }
        return res.empty() ? "0" : res;
    }
};
// @lc code=end
