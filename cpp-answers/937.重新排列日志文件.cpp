/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-22 17:18:46
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-22 17:27:56
 */
/*
 * @lc app=leetcode.cn id=937 lang=cpp
 *
 * [937] 重新排列日志文件
 */

// @lc code=start
class Solution
{
public:
    vector<string> reorderLogFiles(vector<string> &logs)
    {
        auto it = stable_partition(logs.begin(), logs.end(), [](const string &str) {
            return isalpha(str[str.find(' ') + 1]);
        });

        sort(logs.begin(), it, [](const string &str1, const string &str2) {
            auto substr1 = string(str1.begin() + str1.find(' '), str1.end());
            auto substr2 = string(str2.begin() + str2.find(' '), str2.end());
            return (substr1 == substr2) ? str1 < str2 : substr1 < substr2;
        });
        return logs;
    }
};
// @lc code=end
