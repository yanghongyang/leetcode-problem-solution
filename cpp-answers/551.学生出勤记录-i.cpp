/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-03 17:23:57
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-03 17:34:01
 */
/*
 * @lc app=leetcode.cn id=551 lang=cpp
 *
 * [551] 学生出勤记录 I
 */

// @lc code=start
class Solution
{
public:
    bool checkRecord(string s)
    {
        if (s.size() == 0 || s.size() == 1)
            return true;
        bool a = false;
        bool l = false;
        int anum = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'A')
                anum++;
        }
        if (anum > 1)
            a = true;
        for (int i = 0; i < s.size() - 2; i++)
        {
            if (s[i] == 'L' && s[i + 1] == 'L' && s[i + 2] == 'L')
                l = true;
        }
        if (!a && !l)
            return true;
        return false;
    }
};
// @lc code=end
