/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-29 20:22:52
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-29 20:28:34
 */
/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找常用字符
 */

// @lc code=start
class Solution
{
public:
    vector<string> commonChars(vector<string> &A)
    {
        vector<int> cnt1(26, 0);
        vector<int> cnt2(26, 0);
        for (auto ch : A[0])
        {
            cnt1[ch - 'a']++;
        }
        for (int i = 1; i < A.size(); i++)
        {
            for (auto ch : A[i])
            {
                cnt2[ch - 'a']++;
            }
            for (int i = 0; i < 26; i++)
            {
                cnt1[i] = min(cnt1[i], cnt2[i]);
                cnt2[i] = 0;
            }
        }
        vector<string> ans;
        for (int i = 0; i < 26; i++)
        {
            if (cnt1[i] > 0)
            {
                while (cnt1[i] > 0)
                {
                    char t = i + 'a';
                    string s;
                    s = t;
                    ans.push_back(s);
                    cnt1[i]--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
