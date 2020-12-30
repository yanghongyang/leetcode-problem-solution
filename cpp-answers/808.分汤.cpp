/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-12-30 10:59:05
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-12-30 11:32:55
 */
/*
 * @lc app=leetcode.cn id=808 lang=cpp
 *
 * [808] 分汤
 */

// @lc code=start
//以下思路抄自官方题解：https://leetcode-cn.com/problems/soup-servings/solution/fen-tang-by-leetcode/
class Solution
{
public:
    static int absT(int x) //防止溢出
    {
        return x > 0 ? x : 0;
    }
    double soupServings(int N)
    {
        //首先发现题目中所有的分配方案都是25的倍数，因此把所有方案和N都除以25，方便计算
        //N如果不能被25整除，还需要+1
        int n = N / 25 + (N % 25 == 0 ? 0 : 1);
        //此时需要注意，题目中的4种方案总体而言都是A比B消耗的快。如果每种方案各取一次，A消耗4+3+2+1=10份，而B只消耗0+1+2+3=6份
        //因此在N非常大的时候，可以把答案近似等于1（0.99999999）
        if (N > 150 * 25)
            return 1;
        //使用dp[i][j]表示A和B分别剩下i和j份的时候，所求的概率值
        //动态规划，状态转移方程为：dp[i][j] = 0.25 * (dp[i - 4][j], dp[i - 3][j - 1], dp[i - 2][j - 2], dp[i - 1][j - 3])
        //其中边界条件为：
        //1. dp[i][j] = 0.5, if i <= 0 && j <= 0 (对应方案3)
        //2. dp[i][j] = 1,   if i <= 0 && j > 0(对应方案1和方案2)
        //3. dp[i][j] = 0.0, if i > 0 && j <= 0(对应方案4)
        vector<vector<double>> res(n + 1, vector<double>(n + 1, 0));
        //总共2n份汤，分配方案可以为：A4B0, A3B1, A2B2, A1B3
        for (int t = 0; t <= 2 * n; t++)
        {
            for (int i = 0; i <= n; i++) //A可以从0份分到n份
            {
                int j = t - i; //如果分了A汤i份，剩下分B汤只有t-i份了
                if (j < 0 || j > n)
                    continue; //如果B汤没有了，或者B汤分完了都不够
                double ans = 0.0;
                if (i == 0)
                    ans = 1.0;
                if (i == 0 && j == 0)
                    ans = 0.5;
                if (i > 0 && j > 0)
                {
                    ans = 0.25 * (res[absT(i - 4)][j] + res[absT(i - 3)][absT(j - 1)] + res[absT(i - 2)][absT(j - 2)] + res[absT(i - 1)][absT(j - 3)]);
                }
                res[i][j] = ans;
            }
        }
        return res[n][n];
    }
};
// @lc code=end
