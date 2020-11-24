/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-24 22:21:00
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-24 22:30:18
 */
/*
 * @lc app=leetcode.cn id=1338 lang=cpp
 *
 * [1338] 数组大小减半
 */

// @lc code=start
class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        unordered_map<int, int> cnt;
        if (arr.size() <= 0)
            return 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            cnt[arr[i]]++;
        }

        vector<int> cntv;
        for (auto &[k, v] : cnt)
        {
            cntv.push_back(v);
        }
        sort(cntv.begin(), cntv.end(), greater<int>());
        int sum = 0;
        int ans = 0;
        for (auto c : cntv)
        {
            sum += c;
            ans++;
            if (sum >= n / 2)
                break;
        }
        return ans;
    }
};
// @lc code=end
