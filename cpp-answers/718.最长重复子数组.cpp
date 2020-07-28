/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-01 17:13:53
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-01 17:40:46
 */
/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start
class Solution
{
public:
    int findLength(vector<int> &A, vector<int> &B)
    {
        //dp[i][j] ： 长度为 i ，以 A[i-1] 为末尾的序列，和长度为 j，以 B[j-1] 为末尾的序列，二者的最大公共后缀序列长度（该公共序列以A[i-1]（B[j-1]）为末尾项）
        //如果 A[i-1] != B[j-1] ， dp[i][j] = 0
        //如果 A[i-1] == B[j-1] ， dp[i][j] = dp[i-1][j-1] + 1
        int m = A.size();
        int n = B.size();
        int res = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (A[i - 1] == B[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                res = max(dp[i][j], res);
            }
        }
        return res;
    }
};
// @lc code=end
