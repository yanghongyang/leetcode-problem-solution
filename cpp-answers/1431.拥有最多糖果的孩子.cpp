/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-03 15:59:38
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-03 22:56:58
 */
/*
 * @lc app=leetcode.cn id=1431 lang=cpp
 *
 * [1431] 拥有最多糖果的孩子
 */

// @lc code=start
class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        vector<bool> res;
        int most = 0;
        for (int i = 0; i < candies.size(); i++)
        {
            if (most < candies[i])
                most = candies[i];
        }
        for (int i = 0; i < candies.size(); i++)
        {
            if (candies[i] + extraCandies >= most)
            {
                res.push_back(true);
            }
            else
                res.push_back(false);
        }
        return res;
    }
};
// @lc code=end
