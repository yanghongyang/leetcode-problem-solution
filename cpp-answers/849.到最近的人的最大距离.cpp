/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-24 14:46:21
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-24 19:10:59
 */
/*
 * @lc app=leetcode.cn id=849 lang=cpp
 *
 * [849] 到最近的人的最大距离
 */

// @lc code=start
class Solution
{
public:
    int maxDistToClosest(vector<int> &seats)
    {
        vector<int> seat;
        int ret, cha;
        //存入有人坐的位置
        for (auto i = 0; i < seats.size(); i++)
        {
            if (seats[i] == 1)
            {
                seat.push_back(i);
            }
        }
        //考虑两端
        ret = seat[0];
        cha = seats.size() - 1 - seat[seat.size() - 1];
        ret = ret > cha ? ret : cha;
        //统一考虑中间
        for (auto j = 0; j < seat.size() - 1; j++)
        {
            cha = (seat[j + 1] - seat[j]) / 2;
            ret = (ret > cha) ? ret : cha;
        }
        return ret;
    }
};
// @lc code=end
