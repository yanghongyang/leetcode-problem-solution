/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-16 06:18:46
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-16 06:36:15
 */
/*
 * @lc app=leetcode.cn id=375 lang=cpp
 *
 * [375] 猜数字大小 II
 */

// @lc code=start
//https://leetcode-cn.com/problems/guess-number-higher-or-lower-ii/solution/dong-tai-gui-hua-c-you-tu-jie-by-zhang-xiao-tong-2/
class Solution
{
public:
    int getMoneyAmount(int n)
    {
        if (n == 1)
            return 0;
        //定义矩阵
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        //初始化"\"
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                dp[i][j] = INT_MAX;
            }
        }
        //定义基础值dp[i][i]=0;
        for (int i = 0; i <= n; i++)
        {
            dp[i][i] = 0;
        }
        //按照列来，从第二列开始
        for (int j = 2; j <= n; j++)
        {
            //按照行来，从下往上
            for (int i = j - 1; i >= 1; i--)
            {
                //计算除了两端之外的每一个分割点
                for (int k = i + 1; k <= j - 1; k++)
                {
                    dp[i][j] = min(k + max(dp[i][k - 1], dp[k + 1][j]), dp[i][j]);
                }
                //算两端
                dp[i][j] = min(dp[i][j], i + dp[i + 1][j]);
                dp[i][j] = min(dp[i][j], j + dp[i][j - 1]);
            }
        }
        return dp[1][n];
    }
};
// @lc code=end
