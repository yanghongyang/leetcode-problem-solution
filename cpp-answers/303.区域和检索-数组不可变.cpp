/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-17 18:39:32
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-17 18:43:38
 */
/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray
{
public:
    NumArray(vector<int> &nums)
    {
        accu.push_back(0);
        for (int num : nums)
            accu.push_back(accu.back() + num);
    }

    int sumRange(int i, int j)
    {
        return accu[j + 1] - accu[i];
    }

private:
    vector<int> accu;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end
