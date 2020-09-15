/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-09-15 19:15:11
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-09-15 19:23:54
 */
/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        //按照身高从高到低，相同身高k从小到大的顺序进行排序
        //注意sort函数的写法
        sort(
            people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b) {
                if (a[0] > b[0])
                    return true;
                if (a[0] == b[0] && a[1] < b[1])
                    return true;
                return false;
            });

        vector<vector<int>> res;
        for (auto &e : people)
        {
            res.insert(res.begin() + e[1], e);
        }
        return res;
    }
};
// @lc code=end
