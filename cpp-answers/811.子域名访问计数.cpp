/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-17 09:06:44
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-17 09:10:01
 */
/*
 * @lc app=leetcode.cn id=811 lang=cpp
 *
 * [811] 子域名访问计数
 */

// @lc code=start
class Solution
{
public:
    vector<string> subdomainVisits(vector<string> &cpdomains)
    {
        unordered_map<string, int> u;
        vector<string> ans;
        for (auto s : cpdomains)
        {
            int x;
            string str;
            stringstream ss(s);
            ss >> x;
            ss >> str;
            u[str] += x;
            for (int i = str.size(); i >= 0; i--)
            {
                if (str[i] == '.')
                {
                    u[str.substr(i + 1)] += x;
                }
            }
        }
        for (auto x : u)
            ans.push_back(to_string(x.second) + " " + x.first);
        return ans;
    }
};
// @lc code=end
