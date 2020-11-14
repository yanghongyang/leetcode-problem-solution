/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-14 22:08:56
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-14 22:28:12
 */
/*
 * @lc app=leetcode.cn id=464 lang=cpp
 *
 * [464] 我能赢吗
 */

// @lc code=start
//本题代码抄自胡小旭的b站视频：https://www.bilibili.com/video/av80794394
class Solution
{
public:
    bool helper(vector<int> &vis, int &mvalue, int num, int total)
    {
        if (~vis[num])
            return vis[num]; //-1取反是0，正数取反不为0
        vis[num] = 0;
        for (int i = 1; i <= mvalue; i++)
        {
            if (num & (1 << (i - 1)))
                continue;
            if (i >= total)
            {
                vis[num] = 1;
                break;
            }
            bool next = helper(vis, mvalue, num | (1 << (i - 1)), total - i);
            if (next == false)
            {
                vis[num] = 1;
                break;
            }
        }
        return vis[num];
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal)
    {
        if ((maxChoosableInteger * (maxChoosableInteger + 1) / 2) < desiredTotal)
            return false;
        vector<int> vis((1 << maxChoosableInteger) - 1, -1); //初始化visit数组
        int num = 0;
        return helper(vis, maxChoosableInteger, num, desiredTotal);
    }
};
// @lc code=end
