/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-03 23:20:36
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-03 23:25:59
 */
/*
 * @lc app=leetcode.cn id=717 lang=cpp
 *
 * [717] 1比特与2比特字符
 */

// @lc code=start
class Solution
{
public:
    /*
    bool isOneBitCharacter(vector<int> &bits)
    {
        if (bits.empty())
            return false;
        int i = 0;
        while (i < bits.size() - 1)
        {
            if (bits[i] == 1)
                i++;
            i++;
        }
        return i != bits.size();
    }
*/
    bool isOneBitCharacter(vector<int> &bits)
    {
        if (bits.size() == 1)
            return true;
        int index = 0;
        for (index = 0; index < bits.size() - 1;)
        {
            if (bits[index] == 0)
            {
                index++;
            }
            else
            {
                index += 2;
            }
        }
        if (index == bits.size())
            return false;
        else
            return true;
    }
};
// @lc code=end
