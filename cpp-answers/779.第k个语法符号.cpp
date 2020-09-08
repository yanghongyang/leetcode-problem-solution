/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-09-08 22:40:43
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-09-08 23:00:00
 */
/*
 * @lc app=leetcode.cn id=779 lang=cpp
 *
 * [779] 第K个语法符号
 */

// @lc code=start
class Solution
{
public:
    int kthGrammar(int N, int K)
    {
        //两种情况,若K为奇数位置，则当前位置和N-1时(K-1)/2+1的位置值相同；若K为偶数位置，则当前位置和N-1时(K-1)/2+1的位置值相反；
        int flag = 0;
        --N;
        while (N--)
        {
            if (K % 2 == 0)
                flag = !flag;
            K = (K - 1) / 2 + 1;
        }
        return flag;
    }
};
// @lc code=end
