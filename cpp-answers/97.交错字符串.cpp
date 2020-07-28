/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-18 08:24:02
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-18 09:01:37
 */
/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        auto f = vector<vector<int>>(s1.size() + 1, vector<int>(s2.size() + 1, false));
        int n = s1.size();
        int m = s2.size();
        int t = s3.size();
        if (n + m != t)
            return false;
        f[0][0] = true;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                int p = i + j - 1;
                if (i > 0)
                {
                    f[i][j] |= (f[i - 1][j] && s1[i - 1] == s3[p]);
                }
                if (j > 0)
                {
                    f[i][j] |= (f[i][j - 1] && s2[j - 1] == s3[p]);
                }
            }
        }
        return f[n][m];
    }
};
// @lc code=end
