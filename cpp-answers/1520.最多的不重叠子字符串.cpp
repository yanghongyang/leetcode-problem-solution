/*
 * @lc app=leetcode.cn id=1520 lang=cpp
 *
 * [1520] 最多的不重叠子字符串
 */

// @lc code=start
class Solution
{
public:
    vector<int> getFullSub(vector<vector<int>> &subs, string &s, int left, int right)
    {
        for (int j = left + 1; j < right; j++)
        {
            int n = s[j] - 'a';
            if (left <= subs[n][1] && right >= subs[n][2])
                continue;
            left = min(left, subs[n][1]);
            right = max(right, subs[n][2]);
            j = left;
        }

        return {right - left + 1, left, right};
    }
    vector<string> maxNumOfSubstrings(string s)
    {
        vector<vector<int>> subs(26); //记录每个字母代表的子串的范围
        int n = s.size();
        for (int i = 0; i < 26; i++)
        {
            subs[i].push_back(INT_MAX);
            char c = 'a' + i;
            if (s.find(c) == string::npos)
                continue;
            subs[i].push_back(s.find_first_of(c));    //包含字母'a'+i的子串左边界
            subs[i].push_back(s.find_last_of(c));     //包含字母'a'+i的子串右边界
            subs[i][0] = subs[i][2] - subs[i][1] + 1; //包含字母'a'+i的子串长度
        }
        for (int i = 0; i < subs.size(); i++)
        {
            if (subs[i].size() == 1)
                continue; //如果子串仅仅是字符的话，是不用更新区间长度的
            subs[i] = getFullSub(subs, s, subs[i][1], subs[i][2]);
        }
        //然后按顺序从小到大排序
        sort(subs.begin(), subs.end());

        vector<string> ans;
        vector<bool> vis(s.size(), false);
        for (auto sub : subs)
        {
            if (sub.size() == 1)
                break;

            bool check = true;
            for (int j = sub[1]; j <= sub[2] && check; j++)
            {
                check = !vis[j];
            }

            if (!check)
                continue;

            for (int j = sub[1]; j <= sub[2]; j++)
            {
                vis[j] = true;
            }
            ans.push_back(s.substr(sub[1], sub[0]));
        }
        return ans;
    }
};
// @lc code=end
