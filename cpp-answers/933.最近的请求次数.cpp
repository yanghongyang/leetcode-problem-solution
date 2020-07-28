/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-25 08:43:28
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-25 08:50:22
 */
/*
 * @lc app=leetcode.cn id=933 lang=cpp
 *
 * [933] 最近的请求次数
 */

// @lc code=start
class RecentCounter
{
public:
    queue<int> q;
    RecentCounter()
    {
    }

    int ping(int t)
    {
        q.push(t);
        while (q.front() < (t - 3000))
        {
            q.pop();
        }
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end
