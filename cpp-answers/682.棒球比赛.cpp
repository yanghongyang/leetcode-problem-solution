/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-22 20:29:38
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-22 20:35:21
 */
/*
 * @lc app=leetcode.cn id=682 lang=cpp
 *
 * [682] 棒球比赛
 */

// @lc code=start
class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        stack<int> points;
        int res = 0;
        int lastscr = 0;
        int addscr = 0;
        for (auto itm : ops)
        {
            if (itm == "+")
            {
                lastscr = points.top();
                points.pop();
                addscr = lastscr + points.top();
                points.push(lastscr);
                points.push(addscr);
            }
            else if (itm == "D")
            {
                points.push(points.top() * 2);
            }
            else if (itm == "C")
            {
                points.pop();
            }
            else
            {
                points.push(atoi(itm.c_str()));
            }
        }
        while (!points.empty())
        {
            res += points.top();
            points.pop();
        }
        return res;
    }
};
// @lc code=end
