/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-19 21:10:39
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-19 21:16:16
 */
/*
 * @lc app=leetcode.cn id=690 lang=cpp
 *
 * [690] 员工的重要性
 */

// @lc code=start
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution
{
public:
    unordered_map<int, Employee *> mp;
    int ans = 0;
    int getImportance(vector<Employee *> employees, int id)
    {
        for (auto &e : employees)
        {
            mp[e->id] = e;
        }
        dfs(id);
        return ans;
    }
    void dfs(int id)
    {
        ans += mp[id]->importance;
        for (int i = 0; i < mp[id]->subordinates.size(); i++)
        {
            dfs(mp[id]->subordinates[i]);
        }
    }
};
// @lc code=end
