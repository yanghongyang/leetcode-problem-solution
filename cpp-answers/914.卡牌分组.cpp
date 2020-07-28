/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-22 15:02:19
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-22 15:09:45
 */
/*
 * @lc app=leetcode.cn id=914 lang=cpp
 *
 * [914] 卡牌分组
 */

// @lc code=start
class Solution
{
public:
    bool hasGroupsSizeX(vector<int> &deck)
    {
        if (deck.size() < 2)
            return false;
        unordered_map<int, int> m;
        for (int i = 0; i < deck.size(); i++)
        {
            m[deck[i]]++;
        }
        int noOfGroups = m.begin()->second;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (it->second < 2)
                return false;
            noOfGroups = gcd(noOfGroups, it->second);
        }
        return noOfGroups >= 2;
    }

    int gcd(int a, int b)
    {
        if (a == 0)
            return b;
        else
            return gcd(b % a, a);
    }
};
// @lc code=end
