/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-27 22:39:47
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-27 22:43:02
 */
/*
 * @lc app=leetcode.cn id=728 lang=cpp
 *
 * [728] 自除数
 */

// @lc code=start
class Solution
{
public:
    int check(int num)
    {
        int p = num;
        while (p)
        {
            if (p % 10 == 0 || num % (p % 10) != 0)
                return 0;
            p /= 10;
        }
        return 1;
    }
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> ans;
        for (int i = left; i <= right; i++)
        {
            if (check(i))
                ans.push_back(i);
        }
        return ans;
    }
};
// @lc code=end
