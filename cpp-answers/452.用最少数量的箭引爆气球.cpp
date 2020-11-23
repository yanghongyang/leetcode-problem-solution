/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-23 13:18:48
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-23 13:29:14
 */
/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[1] != b[1]) //如果右边界不相同的话，那就按照右边界小的来排序
        {
            return a[1] < b[1];
        }
        return a[0] > b[0]; //如果右边界相同的话，那就按照左边界大的来排序
    }
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.size() <= 0)
            return 0;
        sort(points.begin(), points.end(), cmp);
        int n = points.size();
        int res = n;
        int rborder = points[0][1]; //rborder用来更新每一个点的右边界
        for (int i = 1; i < n; i++)
        {
            if (rborder < points[i][0])
            {
                //如果rborder小于当前点的左边界，也就说明res不要变化（因为需要新的一支箭来射气球）
                //同时更新rborder
                rborder = points[i][1];
            }
            else
            {
                //否则的话，说明当前点在rborder里面，也就是说不需要新的一支箭来射气球了
                res--;
            }
        }
        return res;
    }
};
// @lc code=end
