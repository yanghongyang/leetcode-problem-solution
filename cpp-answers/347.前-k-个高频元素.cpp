/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-20 10:51:33
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-20 11:11:50
 */
/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution
{
public:
    /* vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]]++;
        }
        vector<int> res;
        priority_queue<pair<int, int>> pq;
        //使用优先队列来对map的频次进行排序
        for (auto it = map.begin(); it != map.end(); it++)
        {
            //将map中元素的频次和元素值进行make_pair
            pq.push(make_pair(it->second, it->first));
            //如果当前优先队列中的pair个数超过了map.size()-k个（可以理解为，取最大的前k个意味着有剩下的额map.size()-k个不能取了，容斥原理）
            if (pq.size() > map.size() - k)
            {
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    } */
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]]++;
        }
        vector<int> res;
        priority_queue<pair<int, int>> pq;
        //使用优先队列来对map的频次进行排序
        for (auto it = map.begin(); it != map.end(); it++)
        {
            //将map中元素的频次和元素值进行make_pair
            pq.push(make_pair(it->second, it->first));
        }
        for (int i = 0; i < k; i++)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
// @lc code=end
