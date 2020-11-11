/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-12 01:09:57
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-12 01:16:14
 */
/*
 * @lc app=leetcode.cn id=398 lang=cpp
 *
 * [398] 随机数索引
 */

// @lc code=start
class Solution
{
public:
    vector<int> callCount;
    vector<int> arr;
    Solution(vector<int> &nums)
    {
        callCount.clear();
        arr.clear();
        for (int i = 0; i < nums.size(); i++)
        {
            callCount.push_back(0);
            arr.push_back(nums[i]);
        }
    }

    int pick(int target)
    {
        int minCall = INT_MAX;
        int index;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == target)
            {
                if (minCall > callCount[i])
                {
                    index = i;
                    minCall = callCount[i];
                }
            }
        }
        callCount[index]++;
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end
