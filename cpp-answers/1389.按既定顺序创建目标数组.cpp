/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-19 10:39:32
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-19 10:44:07
 */
/*
 * @lc app=leetcode.cn id=1389 lang=cpp
 *
 * [1389] 按既定顺序创建目标数组
 */

// @lc code=start
class Solution
{
public:
    vector<int> createTargetArray(vector<int> &nums, vector<int> &index)
    {
        vector<int> result;
        for (int i = 0; i < index.size(); i++)
        {
            result.insert(result.begin() + index[i], nums[i]);
        }
        return result;
    }
};
// @lc code=end
