/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-06 17:21:03
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-06 17:47:25
 */
/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
//dp[i][j] = max(dp[i-1][j-1] + triangle[i][j], dp[i-1][j] + triangle[i][j])
//分类讨论，如果为第一个数字的，则没有i-1
//如果为最后一个数字的话，则没有i
/*
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        //构造二维dp表，自顶向下动态规划
        //表达式为：dp[i][j] = max(dp[i-1][j-1]+tri[i][j], dp[i-1][j]+tri[i][j])
        int len = triangle.size();
        if (len == 1)
            return triangle[0][0];
        vector<vector<int>> dp(len, vector<int>(len, 0x3f3f3f3f));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < len; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == 0) //左边界
                {
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                }
                else if (j == i) //右边界
                {
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j - 1] + triangle[i][j], dp[i - 1][j] + triangle[i][j]);
                }
            }
        }
        sort(dp[len - 1].begin(), dp[len - 1].end());
        return dp[len - 1][0];
    }
};*/
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int len = triangle.size();
        vector<int> ans(len, 0); //定义一个数组
        for (int i = 0; i < triangle.size(); i++)
        { //遍历二维数组
            for (int j = i; j >= 0; j--)
            { //从右向左遍历，不然迭代回更新前面的数组，导致下一个数据是上一个数据相加后的结果。
                if (j == 0)
                    ans[j] = ans[j] + triangle[i][j]; //如果是第一个数据，直接与数组相加
                else if (i == j)
                    ans[i] = ans[i - 1] + triangle[i][j]; //如果是最后一个，直接与上一行的最后一个有效数据进行相加
                else
                    ans[j] = min(ans[j] + triangle[i][j], ans[j - 1] + triangle[i][j]); //更新数组取相加和最小的数进行更新
            }
        }
        sort(ans.begin(), ans.end()); //将数组进行排序，输出最小值
        return ans[0];
    }
};
// @lc code=end
