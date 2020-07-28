/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-11 17:25:37
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-11 17:31:22
 */
/*
 * @lc app=leetcode.cn id=1128 lang=cpp
 *
 * [1128] 等价多米诺骨牌对的数量
 */

// @lc code=start
class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        int c = 0, d = 0;
        for (int i = 0; i < dominoes.size(); i++)
        {
            sort(dominoes[i].begin(), dominoes[i].end());
        }
        sort(dominoes.begin(), dominoes.end());
        for (int i = 1; i < dominoes.size(); i++)
        {
            if (dominoes[i] == dominoes[i - 1])
                c++;
            else
            {
                d += (c * (c + 1) / 2);
                c = 0;
            }
        }
        d += (c * (c + 1) / 2);
        return d;
    }
};
// @lc code=end
