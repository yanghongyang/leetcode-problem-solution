/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-20 11:44:43
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-20 11:51:40
 */
/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution
{
public:
    bool lemonadeChange(vector<int> &a)
    {
        if (a.size() <= 0)
            return false;
        int s5 = 0, s10 = 0, s20 = 0;
        for (int i = 0; i < a.size(); i++)
        {
            switch (a[i])
            {
            case 20:
                if (s10 > 0 && s5 > 0)
                {
                    s20++;
                    s10--;
                    s5--;
                    continue;
                }
                else if (s5 > 3)
                {
                    s5 -= 3;
                    continue;
                }
                return false;
            case 10:
                if (s5 > 0)
                {
                    s10++;
                    s5--;
                    continue;
                }
                return false;
            case 5:
                s5++;
                continue;
            default:
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
