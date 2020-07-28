/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-28 11:49:46
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-28 12:05:34
 */
/*
 * @lc app=leetcode.cn id=985 lang=cpp
 *
 * [985] 查询后的偶数和
 */

// @lc code=start
class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &A, vector<vector<int>> &queries)
    {
        vector<int> ans;
        int sum = 0;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] % 2 == 0)
                sum += A[i];
        }
        for (int i = 0; i < queries.size(); i++)
        {
            int a = A[queries[i][1]]; //第i次查询对应位置的值
            int tmp = queries[i][0];  //第i次查询需要加的值
            A[queries[i][1]] += tmp;  //更新了A[queries[i][1]]
            if (a % 2 == 0)           //先减掉之前加上这个位置的值
            {
                sum -= a;
            }
            if (A[queries[i][1]] % 2 == 0) //判断是否是偶数，如果是，再加上
            {
                sum += A[queries[i][1]];
            }
            ans.push_back(sum);
        }
        return ans;
    }
};
// @lc code=end
