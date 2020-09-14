/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-09-14 20:45:09
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-09-14 20:47:23
 */
/*
 * @lc app=leetcode.cn id=735 lang=cpp
 *
 * [735] 行星碰撞
 */

// @lc code=start
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> res;
        for (int a : asteroids)
        {
            bool destroyed = false;
            while (res.size() && res.back() > 0 && a < 0 && !destroyed)
            {
                if (res.back() >= -a)
                    destroyed = true;
                if (res.back() <= -a)
                    res.pop_back();
            }
            if (!destroyed)
                res.push_back(a);
        }
        return res;
    }
};
// @lc code=end
