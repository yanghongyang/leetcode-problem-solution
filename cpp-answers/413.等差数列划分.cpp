/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2021-01-06 10:39:24
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2021-01-06 12:11:15
 */
/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 */

// @lc code=start
class Solution
{
public:
    //法一：暴力法永远滴神
    /*     int numberOfArithmeticSlices(vector<int> &A)
    {
        int cnt = 0;
        if (A.size() <= 2)
            return 0;
        for (int i = 0; i < A.size() - 2; i++)
        {
            int d = A[i + 1] - A[i];
            for (int j = i + 2; j < A.size(); j++)
            {
                if (A[j] - A[j - 1] == d)
                    cnt++;
                else
                    break;
            }
        }
        return cnt;
    } */
    //法二：动态规划（朴素）
    /*     int numberOfArithmeticSlices(vector<int> &A)
    {
        int cnt = 0;
        if (A.size() <= 2)
            return 0;
        vector<int> dp(A.size(), 0); //dp[i]表示，如果在前i-1个数之后加上A[i]，能够构成等差子数组的增量。很明显，如果A[i-2]、A[i-1]、A[i]构成了等差数列，那么A[0...i]构成的等差子数列的增量应该为dp[i-1]（因为以第i-1个元素为结尾构成的等差子数组，增加了A[i]之后肯定也必为以第i个元素为结尾的等差子数组）+1（A[i-2] A[i-1] A[i]）。
        for (int i = 2; i < A.size(); i++)
        {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
            {
                dp[i] = dp[i - 1] + 1;
                cnt += dp[i]; //每次更新总次数
            }
        }
        return cnt;
    } */
    //法三：动态规划（常数空间）
    /*     int numberOfArithmeticSlices(vector<int> &A)
    {
        int cnt = 0;
        if (A.size() <= 2)
            return 0;
        int dp = 0;
        for (int i = 2; i < A.size(); i++)
        {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
            {
                dp = dp + 1;
                cnt += dp; //每次更新总次数
            }
            else
            {
                dp = 0;
            }
        }
        return cnt;
    } */
    //法四：双指针
    int numberOfArithmeticSlices(vector<int> &A)
    {
        int ans = 0;
        int left = 0, right = 2;
        if (A.size() < 2)
            return ans;
        while (right < A.size())
        {
            if (A[right] - A[right - 1] == A[right - 1] - A[right - 2])
            {
                ans += (right - left - 1);
                right++;
            }
            else
            {
                left = right - 1;
                right++;
            }
        }
        return ans;
    }
};
// @lc code=end
