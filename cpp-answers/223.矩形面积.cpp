/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-10 08:24:49
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-10 08:34:07
 */
/*
 * @lc app=leetcode.cn id=223 lang=cpp
 *
 * [223] 矩形面积
 */

// @lc code=start
class Solution
{
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
    {
        long squrea = (C - A) * (D - B);
        long squreb = (G - E) * (H - F);
        long long total = squrea + squreb;
        if (C <= E || A >= G || B >= H || D <= F)
        {
            return total;
        }
        else
        {
            vector<int> h;
            h.push_back(A);
            h.push_back(C);
            h.push_back(E);
            h.push_back(G);

            vector<int> v;
            v.push_back(B);
            v.push_back(D);
            v.push_back(F);
            v.push_back(H);

            sort(h.begin(), h.end());
            sort(v.begin(), v.end());

            total = total - (h[2] - h[1]) * (v[2] - v[1]);
            return total;
        }
    }
};
// @lc code=end
