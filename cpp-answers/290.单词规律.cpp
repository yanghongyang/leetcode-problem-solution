/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-13 19:38:15
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-17 18:28:22
 */
/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start
class Solution
{
public:
    bool wordPattern(string pattern, string str)
    {
        map<char, int> p2i;
        map<string, int> w2i;
        istringstream in(str); //istringstrem是C++的输入输出控制流
        int i = 0;
        int n = pattern.size();
        for (string word; in >> word; i++)
        {
            if (i == n || p2i[pattern[i]] != w2i[word])
                return false;
            w2i[word] = i + 1;
            p2i[pattern[i]] = i + 1;
        }
        return i == n;
    }
};
// @lc code=end
