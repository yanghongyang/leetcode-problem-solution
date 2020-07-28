/*
 * @Author: your name
 * @Date: 2020-06-05 22:32:27
 * @LastEditTime: 2020-06-05 22:43:32
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode刷题\189.旋转数组.cpp
 */
/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        /*暴力解法超时了。。。
        int temp, previous;
        for (int i = 0; i < k; i++)
        {
            previous = nums[nums.size() - 1];
            for (int j = 0; j < nums.size(); j++)
            {
                temp = nums[j];
                nums[j] = previous;
                previous = temp;
            }
        }*/
        /*使用额外的数组
        vector<int> temp(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            temp[(i + k) % nums.size()] = nums[i];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = temp[i];
        }
        */
    }
};
// @lc code=end
