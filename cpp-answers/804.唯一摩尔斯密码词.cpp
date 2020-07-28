/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-24 10:40:54
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-24 10:46:33
 */
/*
 * @lc app=leetcode.cn id=804 lang=cpp
 *
 * [804] 唯一摩尔斯密码词
 */

// @lc code=start
class Solution
{
public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        vector<string> alpha = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        set<string> r;
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            int m = words[i].size();
            string res = "";
            for (int j = 0; j < m; j++)
            {
                res += alpha[words[i][j] - 'a'];
            }
            r.insert(res);
        }
        return r.size();
    }
};
// @lc code=end
