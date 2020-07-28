/*
 * @Author: your name
 * @Date: 2020-06-05 20:35:37
 * @LastEditTime: 2020-06-05 20:45:17
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \-Insgram-e:\leetcode刷题\119.杨辉三角-ii.cpp
 */
/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
class Solution
{
public:
    //参照118题的解法
    /*
    vector<int> getRow(int rowIndex)
    {
        vector<int> result;
        for (int i = 0; i <= rowIndex; i++)
        {
            result.push_back(1);
            for (int j = i - 1; j > 0; j--)
            {
                result[j] = result[j] + result[j - 1];
            }
        }
        return result;
    }*/
    //利用组合数公式
    vector<int> getRow(int rowIndex)
    {
        vector<int> result;
        result.push_back(1);
        long pre = 1;
        for (int k = 1; k <= rowIndex; k++)
        {
            long cur = pre * (rowIndex - k + 1) / k;
            result.push_back(cur);
            pre = cur;
        }
        return result;
    }
};
// @lc code=end
