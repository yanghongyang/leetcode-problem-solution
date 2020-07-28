/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-03 22:53:04
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-03 22:55:29
 */
/*
 * @lc app=leetcode.cn id=1491 lang=cpp
 *
 * [1491] 去掉最低工资和最高工资后的工资平均值
 */

// @lc code=start
class Solution
{
public:
    double average(vector<int> &salary)
    {
        return (accumulate(salary.begin(), salary.end(), 0.0) - *max_element(salary.begin(), salary.end()) - *min_element(salary.begin(), salary.end())) / (salary.size() - 2);
    }
};
// @lc code=end
