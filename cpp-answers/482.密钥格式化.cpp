/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-27 23:27:44
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-27 23:31:37
 */
/*
 * @lc app=leetcode.cn id=482 lang=cpp
 *
 * [482] 密钥格式化
 */

// @lc code=start
class Solution
{
public:
    string licenseKeyFormatting(string S, int K)
    {
        string res;
        for (auto i = S.rbegin(); i < S.rend(); i++)
        {
            if (*i != '-')
            {
                if (res.size() % (K + 1) == K)
                    res += '-';
                res += toupper(*i);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
