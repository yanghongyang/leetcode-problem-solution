/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-22 17:38:21
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-22 17:40:15
 */
/*
 * @lc app=leetcode.cn id=657 lang=cpp
 *
 * [657] 机器人能否返回原点
 */

// @lc code=start
class Solution
{
public:
    bool judgeCircle(string moves)
    {
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 0; i < moves.size(); i++)
        {
            if (moves[i] == 'R')
                cnt1++;
            if (moves[i] == 'L')
                cnt1--;
            if (moves[i] == 'U')
                cnt2++;
            if (moves[i] == 'D')
                cnt2--;
        }
        return cnt1 == 0 && cnt2 == 0;
    }
};
// @lc code=end
