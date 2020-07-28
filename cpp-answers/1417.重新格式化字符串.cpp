/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-25 10:20:18
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-25 10:26:53
 */
/*
 * @lc app=leetcode.cn id=1417 lang=cpp
 *
 * [1417] 重新格式化字符串
 */

// @lc code=start
class Solution
{
public:
    string reformat(string s)
    {
        string result(s.size(), ' ');
        int ccnt = 0, dcnt = 0;
        for (char &c : s)
        {
            if (isdigit(c))
                dcnt++;
            else if (isalpha(c))
                ccnt++;
        }
        if (abs(ccnt - dcnt) > 1)
        {
            return "";
        }
        int cindex, dindex;
        if (ccnt > dcnt)
        {
            cindex = 0;
            dindex = 1;
        }
        else
        {
            cindex = 1;
            dindex = 0;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
            {
                result[dindex] = s[i];
                dindex += 2;
            }
            else
            {
                result[cindex] = s[i];
                cindex += 2;
            }
        }
        return result;
    }
};
// @lc code=end
