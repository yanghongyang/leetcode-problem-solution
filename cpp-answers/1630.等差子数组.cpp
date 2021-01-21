/*
 * @lc app=leetcode.cn id=1630 lang=cpp
 *
 * [1630] 等差子数组
 */

// @lc code=start
class Solution
{
public:
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {
        vector<bool> ans;
        if (l.size() != r.size())
            return ans;
        int n = nums.size();
        int m = l.size();
        for (int i = 0; i < m; i++)
        {
            vector<int> tmp;
            for (int j = l[i]; j <= r[i]; j++)
            {
                tmp.push_back(nums[j]);
            }
            sort(tmp.begin(), tmp.end());
            int flag = 0;
            for (int j = 1; j < tmp.size() - 1; j++)
            {
                if (tmp[j] - tmp[j - 1] != tmp[j + 1] - tmp[j])
                {
                    flag = 1;
                    ans.push_back(false);
                    break;
                }
            }
            if (flag == 0)
            {
                ans.push_back(true);
            }
        }
        return ans;
    }
};
// @lc code=end
