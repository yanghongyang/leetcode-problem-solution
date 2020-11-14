/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-14 09:34:19
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-14 09:44:33
 */
/*
 * @lc app=leetcode.cn id=396 lang=cpp
 *
 * [396] 旋转函数
 */

// @lc code=start
class Solution
{
public:
    int maxRotateFunction(vector<int> &A)
    {
        long long sum1 = 0, sum2 = 0; //sum1用来记录f(0), sum2用来记录从A[0]到A[n]的和
        for (int i = 0; i < A.size(); i++)
        {
            sum1 += i * A[i];
            sum2 += A[i];
        }
        //每一遍循环都是加上一个sum2，再减掉A的最后一个元素
        int res = sum1;
        for (int i = A.size() - 1; i >= 1; i--)
        {
            int tmp = sum2 - A.size() * A[i];
            sum1 = sum1 + tmp;
            res = max(res, (int)sum1);
        }
        return res;
    }
};
// @lc code=end
