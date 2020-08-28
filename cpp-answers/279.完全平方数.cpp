/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-28 17:26:07
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-28 18:07:05
 */
/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution
{
public:
    //朴素动态规划
    /*     int numSquares(int n)
    {
        if (n <= 0)
            return 0;
        vector<int> res(n + 1, INT_MAX); //初始化都给最大值
        res[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
            {
                res[i] = min(res[i], res[i - j * j] + 1);
            }
        }
        return res[n];
    } */
    //static vector版动态规划，比朴素动态规划快，快很多......
    /*     int numSquares(int n)
    {
        if (n <= 0)
            return 0;
        static vector<int> res({0});
        while (res.size() <= n)
        {
            int m = res.size();
            int ans = INT_MAX;
            for (int i = 1; i * i <= m; i++)
            {
                ans = min(ans, res[m - i * i] + 1);
            }
            res.push_back(ans);
        }
        return res[n];
    } */
    //数学方法(Joseph Louis Lagrange证明了一个定理，称为四平方和定理，也称为 Bachet 猜想)
    /*     bool is_square(int n)
    {
        int sqrt_n = (int)(sqrt(n));
        return (sqrt_n * sqrt_n == n);
    }
    int numSquares(int n)
    {
        //结果是1：n为平方数
        if (is_square(n))
            return 1;
        //结果是4：n=4^k*(8*m+7)，参考Legendre的三平方定理(three-square theorem)
        while ((n & 3) == 0) //n % 4 == 0
        {
            n >>= 2;
        }
        if ((n & 7) == 7)
            return 4;
        //检查2是否是结果
        int sqrt_n = (int)(sqrt(n));
        for (int i = 1; i <= sqrt_n; i++)
        {
            if (is_square(n - i * i))
            {
                return 2;
            }
        }

        return 3;
    } */
    //广度优先搜索
    int numSquares(int n)
    {
        if (n <= 0)
            return 0;

        vector<int> perfectSquares; //包含所有小于等于n的平方数
        vector<int> ans(n);         //答案
        for (int i = 1; i * i <= n; i++)
        {
            perfectSquares.push_back(i * i);
            ans[i * i - 1] = 1;
        }
        if (perfectSquares.back() == n)
            return 1;
        //考虑一个图，其中的节点为1...n，节点i和节点j之间只有在i=j+平方数或j=i+平方数的时候才有边。
        queue<int> q;
        for (auto &i : perfectSquares)
        {
            q.push(i);
        }
        int currCntPerfectSquares = 1;
        while (!q.empty())
        {
            currCntPerfectSquares++;
            int tn = q.size();
            for (int i = 0; i < tn; i++)
            {
                int tmp = q.front();
                for (auto &j : perfectSquares)
                {
                    if (tmp + j == n)
                    {
                        return currCntPerfectSquares;
                    }
                    else if ((tmp + j < n) && (ans[tmp + j - 1] == 0))
                    {
                        ans[tmp + j - 1] = currCntPerfectSquares;
                        q.push(tmp + j);
                    }
                    else if (tmp + j > n)
                    {
                        break;
                    }
                }
                q.pop();
            }
        }
        return 0;
    }
};
// @lc code=end
