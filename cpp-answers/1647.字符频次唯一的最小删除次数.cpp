/*
 * @lc app=leetcode.cn id=1647 lang=cpp
 *
 * [1647] 字符频次唯一的最小删除次数
 */

// @lc code=start
class Solution
{
public:
    int minDeletions(string s)
    {
        unordered_map<int, int> cnt;
        for (auto c : s)
        {
            cnt[c - 'a']++;
        }
        int ans = 0;
        set<int> cn; //用来记录字符频次唯一时的字符频次
        for (auto t : cnt)
        {
            int cnum = t.second;
            while (cn.find(cnum) != cn.end() && cnum != 0)
            {
                ans++;
                cnum--;
            }
            if (cnum != 0)
                cn.insert(cnum);
        }
        return ans;
    }
};
// @lc code=end
