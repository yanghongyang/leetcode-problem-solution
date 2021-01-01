/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2021-01-01 18:15:31
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2021-01-01 19:49:50
 */
/*
 * @lc app=leetcode.cn id=1418 lang=cpp
 *
 * [1418] 点菜展示表
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> displayTable(vector<vector<string>> &orders)
    {
        int n = orders.size();
        int m = orders[0].size();
        vector<vector<string>> ans;
        if (!n || !m)
            return ans;
        map<int, unordered_map<string, int>> mp; //按照餐桌桌号升序排列，所以用map，同时要建立菜品和被点次数的映射关系，所以map里再套一个unordered_map（哈希）
        set<string> dishes;                      //用来不重复地、从小到大地统计菜名
        for (auto order : orders)
        {
            dishes.insert(order[2]);
            mp[stoi(order[1])][order[2]]++;
        }
        vector<string> heading(dishes.begin(), dishes.end());
        heading.insert(heading.begin(), "Table");
        ans.push_back(heading);
        for (auto p : mp)
        {
            vector<string> row;
            row.push_back(to_string(p.first));
            for (string s : dishes)
            {
                row.push_back(to_string(p.second[s]));
            }
            ans.push_back(row);
        }
        return ans;
    }
};
// @lc code=end
