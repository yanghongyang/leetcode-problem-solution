/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-22 17:33:17
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-22 17:35:20
 */
/*
 * @lc app=leetcode.cn id=942 lang=cpp
 *
 * [942] 增减字符串匹配
 */

// @lc code=start
class Solution
{
public:
    vector<int> diStringMatch(string S)
    {
        int start = 0, end = S.size();
        vector<int> res;
        for (auto i : S)
        {
            if (i == 'I')
                res.push_back(start++);
            else
                res.push_back(end--);
        }
        res.push_back(start);
        return res;
    }
};
// @lc code=end
