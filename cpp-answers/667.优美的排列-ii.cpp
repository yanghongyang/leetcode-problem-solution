/*
 * @lc app=leetcode.cn id=667 lang=cpp
 *
 * [667] 优美的排列 II
 */

// @lc code=start
/* class Solution
{
public:
    void reverse(vector<int> &ans, int left, int right)
    {
        while (left < right)
        {
            int tmp = ans[left];
            ans[left] = ans[right];
            ans[right] = tmp;
            left++;
            right--;
        }
    }
    vector<int> constructArray(int n, int k)
    {
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            ans[i] = i + 1;
        }
        for (int i = 1; i < k; i++)
        {
            reverse(ans, i, n - 1);
        }
        return ans;
    }
}; */
class Solution
{
public:
    vector<int> constructArray(int n, int k)
    {
        vector<int> ans(n, 0);
        int tmp1 = 1, tmp2 = k + 1;
        for (int i = 0; i <= k; i++)
        {
            if (i & 1)
                ans[i] = tmp2--;
            else
                ans[i] = tmp1++;
        }
        for (int i = k + 1; i < n; i++)
        {
            ans[i] = i + 1;
        }
        return ans;
    }
};
// @lc code=end
