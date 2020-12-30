/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-12-30 08:21:36
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-12-30 08:24:31
 */
/*
 * @lc app=leetcode.cn id=1046 lang=cpp
 *
 * [1046] 最后一块石头的重量
 */

// @lc code=start
class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq;
        for (int i = 0; i < stones.size(); i++)
        {
            pq.push(stones[i]);
        }
        int m1, m2;
        while (pq.size() > 1)
        {
            m1 = pq.top(); //最重的石头
            pq.pop();
            m2 = pq.top();
            pq.pop();
            if (m1 != m2)
            {
                pq.push(abs(m1 - m2));
            }
        }
        if (pq.empty())
            return 0;
        return pq.top();
    }
};
// @lc code=end
