/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-07 21:48:49
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-07 21:52:18
 */
/*
 * @lc app=leetcode.cn id=1025 lang=cpp
 *
 * [1025] 除数博弈
 */

// @lc code=start
/*
博弈型动态规划
dp[i]表示面对数字i，是否先手获胜
如果面对数字i，取得一个数字j之后，使得数字dp[i-j]为fasle，则dp[i]为true
dp[i] = (dp[i-j] == false) (0< j <i and i %j == 0)
*/
class Solution
{
public:
    bool divisorGame(int N)
    {
        bool dp[N + 1];
        memset(dp, false, N + 1);
        for (int i = 2; i <= N; i++)
        {
            for (int j = 1; j * j <= i; j++)
            {
                if (i % j == 0 && !dp[i - j])
                    dp[i] = true;
            }
        }
        return dp[N];
    }
};
// @lc code=end
