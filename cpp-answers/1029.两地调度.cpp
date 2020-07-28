/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-25 12:01:02
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-25 12:08:05
 */
/*
 * @lc app=leetcode.cn id=1029 lang=cpp
 *
 * [1029] 两地调度
 */

// @lc code=start
class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return (a[0] - a[1]) < (b[0] - b[1]); //这里的原理比较绕脑子，可以理解为，如果去A花的钱远远小于去B花的钱，那么肯定是去A。
        //同理，如果那两组做对比，肯定是这a[i][0] - a[i][1]和b[i][0]-b[i][1]之间谁差的更多，越得让谁去A这个地方，不然的话因为[i][1]肯定更大所以那个人去b的地方肯定更费钱
    }
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        int n = costs.size();
        sort(costs.begin(), costs.end(), cmp);
        int cost = 0;
        for (int i = 0; i < n / 2; i++)
        {
            cost += costs[i][0];
        }
        for (int i = n / 2; i < n; i++)
        {
            cost += costs[i][1];
        }
        return cost;
    }
};
// @lc code=end
