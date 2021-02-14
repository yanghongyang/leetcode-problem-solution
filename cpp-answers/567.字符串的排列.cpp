/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution
{
public:
    /*     bool checkInclusion(string s1, string s2)
    {
        int len1 = s1.size();
        int len2 = s2.size();
        int left = 0, right = len1 - 1; //在s2中的左右指针
        unordered_map<char, int> cnt1;  //用于记录s1中字母出现的次数
        for (int i = 0; i < len1; i++)
        {
            cnt1[s1[i] - 'a']++;
        }
        while (right < len2) //开始滑动
        {
            unordered_map<char, int> tmp(cnt1); //复制构造
            for (int i = left; i <= right; i++)
            {
                tmp[s2[i] - 'a']--;
            }
            bool flag = true;
            for (auto c : tmp)
            {
                if (c.second != 0)
                {
                    flag = false;
                    break;
                }
            }
            if (flag == true)
                return true;
            left++;
            right++;
        }
        return false;
    } */
    bool checkInclusion(string s1, string s2)
    {
        int len1 = s1.size();
        int len2 = s2.size();
        int left = 0, right = len1 - 1; //在s2中的左右指针
        vector<int> cur(26), goal(26);
        for (char c : s1)
            goal[c - 'a']++;
        for (int i = 0; i < len2; i++)
        {
            cur[s2[i] - 'a']++;
            if (i >= s1.size())
                cur[s2[i - s1.size()] - 'a']--;
            if (goal == cur)
                return true;
        }
        return false;
    }
};
// @lc code=end
