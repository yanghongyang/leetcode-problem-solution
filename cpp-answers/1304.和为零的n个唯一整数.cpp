/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-25 10:42:25
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-25 10:45:05
 */
/*
 * @lc app=leetcode.cn id=1304 lang=cpp
 *
 * [1304] 和为零的N个唯一整数
 */

// @lc code=start
class Solution
{
public:
    vector<int> sumZero(int n)
    {
        vector<int> ans;
        int sum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            ans.push_back(i);
            sum += i;
        }
        ans.push_back(-sum);
        return ans;
    }
};
// @lc code=end
