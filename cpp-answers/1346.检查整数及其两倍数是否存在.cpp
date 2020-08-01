/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-01 19:00:37
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-01 19:13:00
 */
/*
 * @lc app=leetcode.cn id=1346 lang=cpp
 *
 * [1346] 检查整数及其两倍数是否存在
 */

// @lc code=start
class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        //暴力方法，简单粗暴（学一下for循环的使用）
        for (auto i = arr.begin(); i != arr.end(); i++)
        {
            for (auto j = arr.begin(); j != arr.end(); j++)
            {
                if (i != j && *i == 2 * *j)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
