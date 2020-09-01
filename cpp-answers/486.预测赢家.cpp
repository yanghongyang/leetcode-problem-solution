/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-09-01 16:37:13
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-09-01 17:09:58
 */
/*
 * @lc app=leetcode.cn id=486 lang=cpp
 *
 * [486] 预测赢家
 */

// @lc code=start
class Solution
{
public:
    //讲解来自[笨猪爆破组](https://leetcode-cn.com/problems/predict-the-winner/solution/shou-hua-tu-jie-san-chong-xie-fa-di-gui-ji-yi-hua-/)大佬
    //朴素递归
    /*     int helper(int i, int j, vector<int> &nums)
    {
        if (i == j) //递归的出口，此时只有一个选择，即没有剩余的数字可以选了
            return nums[i];
        int pickI = nums[i] - helper(i + 1, j, nums); //选择左端的话，需要先得到当前的数字，然后再减去右边部分别人选的数
        int pickJ = nums[j] - helper(i, j - 1, nums); //选择右端的话，同理
        return max(pickI, pickJ);                     //肯定是返回两者的最大值，因为要娶最优解
    }
    bool PredictTheWinner(vector<int> &nums)
    {
        return helper(0, nums.size() - 1, nums) >= 0;
    } */
    //朴素递归法存在冗余运算
    /*     int helper(int i, int j, vector<int> &nums, vector<vector<int>> &memo)
    {
        if (memo[i][j] != 0)
            return memo[i][j];
        if (i == j)
        {
            memo[i][j] = nums[i];
            return nums[i];
        }
        int pickI = nums[i] - helper(i + 1, j, nums, memo);
        int pickJ = nums[j] - helper(i, j - 1, nums, memo);
        memo[i][j] = max(pickI, pickJ);
        return memo[i][j];
    }
    bool PredictTheWinner(vector<int> &nums)
    {
        vector<vector<int>> memo(nums.size(), vector<int>());
        for (int i = 0; i < nums.size(); i++)
        {
            memo[i].resize(nums.size());
        }
        return helper(0, nums.size() - 1, nums, memo) >= 0;
    } */
    //动态规划解法源自递归解法
    bool PredictTheWinner(vector<int> &nums)
    {
        vector<vector<int>> dp(nums.size(), vector<int>());
        for (int i = 0; i < nums.size(); i++)
        {
            dp[i].resize(nums.size());
        }
        for (int i = 0; i < nums.size(); i++)
        {
            dp[i][i] = nums[i];
        }
        //动态规划
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                int pickI = nums[i] - dp[i + 1][j];
                int pickJ = nums[j] - dp[i][j - 1];
                dp[i][j] = max(pickI, pickJ);
            }
        }
        return dp[0][nums.size() - 1] >= 0;
    }
};
// @lc code=end
