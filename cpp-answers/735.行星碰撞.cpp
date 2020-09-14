/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-09-14 20:45:09
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-09-14 21:08:29
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
    /*     vector<int> asteroidCollision(vector<int> &asteroids)
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
    } */
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> res;
        stack<int> s;
        s.push(INT_MIN); //这里压入INT_MIN有个好处：当asteroids的首元素为负值时不用担心碰撞，直接压栈即可；当首元素为正值时，也不用担心碰撞，直接压栈就行。
        for (int a : asteroids)
        {
            if (a < 0)
            {
                while (s.top() > 0 && s.top() < -a)
                {
                    s.pop(); //如果栈顶大于零并且符合碰撞规则，出栈。
                }
                if (s.top() < 0)
                {
                    s.push(a);
                }
                else if (s.top() == -a)
                {
                    s.pop(); //如果栈顶元素和当前元素相等，还是碰撞了，出栈。
                }
            }
            else
            {
                s.push(a);
            }
        }
        while (s.size() != 1)
        {
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
