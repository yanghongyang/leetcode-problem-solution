/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-10-24 09:31:40
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-10-24 09:39:41
 */
/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */

// @lc code=start
class Solution
{
public:
    Solution(const vector<int> &nums) : nums(nums), arr(nums), seed(random_device{}())
    {
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        arr = nums;
        return arr;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        for (int i = size(arr) - 1; i > 0; --i)
        {
            auto idx = uniform_int_distribution<int>(0, i)(seed);
            swap(arr[i], arr[idx]);
        }
        return arr;
    }

private:
    vector<int> arr, nums;
    default_random_engine seed;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end
