/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-10-14 08:36:07
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-10-14 08:45:17
 */
/*
 * @lc app=leetcode.cn id=1498 lang=cpp
 *
 * [1498] 满足条件的子序列数目
 */

// @lc code=start
class Solution
{
public:
    int numSubseq(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long MOD = 1e9 + 7;
        vector<int> cnt(n); //记录第i个数为止所能构成的子集个数
        cnt[0] = 1;         //没有元素的时候，只有空集
        for (int i = 1; i < nums.size(); i++)
        {
            cnt[i] = (cnt[i - 1] << 1) % MOD;
        }
        //接下来使用双指针对nums进行遍历
        int l = 0, r = nums.size() - 1;
        int res = 0;
        while (l <= r)
        {
            int sum = nums[l] + nums[r];
            if (sum > target)
            {
                r--;
            }
            else
            {
                res = (res + cnt[r - l]) % MOD;
                l++;
            }
        }
        return res;
    }
};
// @lc code=end
