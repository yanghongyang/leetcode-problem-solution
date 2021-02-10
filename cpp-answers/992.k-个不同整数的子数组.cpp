/*
 * @lc app=leetcode.cn id=992 lang=cpp
 *
 * [992] K 个不同整数的子数组
 */

// @lc code=start
class Solution
{
public:
    void find(vector<int> &tmp, vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> cnt(n + 1);
        int ans = 0;
        for (int i = 0, j = 0, sum = 0; i < n; i++)
        {
            int right = nums[i];
            if (cnt[right] == 0)
                sum++; //用来统计次数
            cnt[right]++;
            while (sum > k)
            {
                int left = nums[j++];
                cnt[left]--;
                if (cnt[left] == 0)
                    sum--;
            }
            tmp[i] = j;
        }
    }
    int subarraysWithKDistinct(vector<int> &nums, int K)
    {
        int n = nums.size();
        vector<int> lower(n), upper(n);
        find(lower, nums, k);
        find(upper, nums, k - 1);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += upper[i] - lower[i];
        }
        return ans;
    }
};
// @lc code=end
