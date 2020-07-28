/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-23 08:29:42
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-17 07:40:13
 */
/*
 * @lc app=leetcode.cn id=401 lang=cpp
 *
 * [401] 二进制手表
 */

// @lc code=start
class Solution
{
public:
    static std::unordered_map<int, std::vector<int>> bits;
    vector<string> readBinaryWatch(int n)
    {
        std::vector<string> res;
        for (int i = 0; i <= n; i++)
        {
            for (auto h : bits[i])
            {
                if (h > 11)
                    continue;
                for (auto m : bits[n - i])
                {
                    res.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
                }
            }
        }
        return res;
    }
};
std::unordered_map<int, std::vector<int>> Solution::bits = {{0, {0}}, {1, {1, 2, 4, 8, 16, 32}}, {2, {3, 5, 6, 9, 10, 12, 17, 18, 20, 24, 33, 34, 36, 40, 48}}, {3, {7, 11, 13, 14, 19, 21, 22, 25, 26, 28, 35, 37, 38, 41, 42, 44, 49, 50, 52, 56}}, {4, {15, 23, 27, 29, 30, 39, 43, 45, 46, 51, 53, 54, 57, 58}}, {5, {31, 47, 55, 59}}};

// @lc code=end
