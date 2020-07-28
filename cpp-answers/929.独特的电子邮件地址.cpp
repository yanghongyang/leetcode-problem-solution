/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-25 09:03:50
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-25 09:08:16
 */
/*
 * @lc app=leetcode.cn id=929 lang=cpp
 *
 * [929] 独特的电子邮件地址
 */

// @lc code=start
class Solution
{
public:
    int numUniqueEmails(vector<string> &emails)
    {
        set<string> s;
        for (auto &email : emails)
        {
            string cleanEmail;
            for (char c : email)
            {
                if (c == '+' || c == '@')
                    break;
                if (c == '.')
                    continue;
                cleanEmail += c;
            }
            cleanEmail += email.substr(email.find('@'));
            s.insert(cleanEmail);
        }
        return s.size();
    }
};
// @lc code=end
