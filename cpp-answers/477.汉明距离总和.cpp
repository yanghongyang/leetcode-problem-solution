/*
 * @lc app=leetcode.cn id=477 lang=cpp
 *
 * [477] 汉明距离总和
 */

// @lc code=start
class Solution
{
public:
    int totalHammingDistance(vector<int> &nums)
    {
        int res = 0;
        int n = nums.size();

        for (int i = 0; i < 32; i++)
        {
            int cnt_1 = 0;
            for (int j = 0; j < n; j++)
            {
                cnt_1 += (nums[j] >> i) & 1;
            }
            res += (n - cnt_1) * cnt_1;
        }

        return res;
    }
};
// @lc code=end
