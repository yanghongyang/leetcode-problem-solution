/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-06 23:12:28
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2021-01-07 11:13:08
 */
/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
/* class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for(int i = 0; i < s.size(); i++)
        {
            if(dict[s[i]] > start)  
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
}; */
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        if (n <= 0)
            return 0;
        int l = 0, r = 1;
        int ans = 0;
        vector<int> cnt(256, 0);
        cnt[s[l]]++;
        while (l < n)
        {
            while (cnt[s[r]] < 1 && r < n)
            {
                cnt[s[r]]++;
                r++;
            }
            ans = max(ans, r - l);
            cnt[s[l]]--;
            l++;
        }
        return ans;
    }
};
// @lc code=end
