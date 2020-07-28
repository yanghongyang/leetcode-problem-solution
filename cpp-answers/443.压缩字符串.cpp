/*
 * @Author: your name
 * @Date: 2020-06-09 11:23:33
 * @LastEditTime: 2020-06-09 11:30:20
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \undefinede:\leetcode刷题\443.压缩字符串.cpp
 */
/*
 * @lc app=leetcode.cn id=443 lang=cpp
 *
 * [443] 压缩字符串
 */

// @lc code=start
class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int i = 0;
        for (int j = 1, count = 1; j <= chars.size(); j++, count++)
        {
            if (j == chars.size() || chars[j] != chars[j - 1])
            {
                chars[i++] = chars[j - 1];
                if (count >= 2)
                {
                    for (char digit : to_string(count))
                        chars[i++] = digit;
                }
                count = 0;
            }
        }
        return i;
    }
};
// @lc code=end
