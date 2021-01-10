/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2021-01-10 11:00:28
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2021-01-10 16:09:56
 */
/*
 * @lc app=leetcode.cn id=593 lang=cpp
 *
 * [593] 有效的正方形
 */

// @lc code=start
class Solution
{
public:
    double edge(vector<int> p1, vector<int> p2)
    {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
    //默认情况下，p1p2 p3p4 p2p3 p4p1为正方形边， p1p3 p2p4 为斜边
    bool check(vector<int> p1, vector<int> p2, vector<int> p3, vector<int> p4)
    {
        double p1p2 = edge(p1, p2);
        double p1p3 = edge(p1, p3);
        double p2p4 = edge(p2, p4);
        double p3p4 = edge(p3, p4);
        double p2p3 = edge(p2, p3);
        double p1p4 = edge(p1, p4);
        bool equal = (p1[0] == p2[0] && p1[1] == p2[1]) || (p1[0] == p3[0] && p1[1] == p3[1]) || (p1[0] == p4[0] && p1[1] == p4[1]);
        return !equal && (p1p2 != p1p3) && (p1p2 == p3p4) && (p1p2 == p2p3) && (p1p2 == p1p4) && (p1p3 == p2p4);
    }
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        //对于p1p2，如果是边的话肯定p3p4也是边，如果是斜边的话p3p4也肯定是斜边
        return check(p1, p2, p3, p4) ||
               check(p1, p2, p4, p3) ||
               check(p1, p3, p2, p4) ||
               check(p1, p3, p4, p2) ||
               check(p1, p4, p3, p2) ||
               check(p1, p4, p2, p3);
    }
};
// @lc code=end
