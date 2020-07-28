/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-03 22:35:14
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-03 22:40:36
 */
/*
 * @lc app=leetcode.cn id=925 lang=cpp
 *
 * [925] 长按键入
 */

// @lc code=start
class Solution
{
public:
    bool isLongPressedName(string name, string typed)
    {
        if (name.size() > typed.size())
            return false;
        if (name[0] != typed[0])
            return false;

        int i = 1, j = 1;
        while (i < name.size() && j < typed.size())
        {
            if (name[i] == typed[j])
            {
                i++;
                j++;
            }
            else if (typed[j] == typed[j - 1])
            {
                j++;
            }
            else
                return false;
        }
        while (j < typed.size())
        {
            if (typed[j] != typed[j - 1])
                return false;
            j++;
        }
        if (i == name.size())
            return true;
        else
            return false;
    }
};
// @lc code=end
