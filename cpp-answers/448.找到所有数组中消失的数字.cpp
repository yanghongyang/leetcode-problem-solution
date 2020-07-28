/*
 * @Author: your name
 * @Date: 2020-06-08 09:09:25
 * @LastEditTime: 2020-06-08 09:14:04
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode刷题\448.找到所有数组中消失的数字.cpp
 */
/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> results;
        //将所有在数组中出现的数字都*-1
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] *= -1;
        }
        //那么接下来所有剩下是正数的数字，就是未出现在数组中的数字
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                results.push_back(i + 1);
        }

        return results;
    }
};
// @lc code=end
