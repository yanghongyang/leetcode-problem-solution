/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */

// @lc code=start
class Solution
{
public:
    //这一题的官解写的出人意料的好呢
    //https://leetcode-cn.com/problems/h-index/solution/hzhi-shu-by-leetcode/
    //排序模拟——基于sort函数
    /*     int hIndex(vector<int> &citations)
    {
        sort(citations.begin(), citations.end());
        int i = 0;
        while (i < citations.size() && citations[citations.size() - 1 - i] > i)
        {
            i++;
        }
        return i;
    } */
    //排序的另一种方法——计数排序
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        vector<int> papers(n + 1, 0);
        for (int c : citations)
        {
            papers[min(n, c)]++;
        }
        int k = n;
        for (int s = papers[n]; k > s; s += papers[k])
        {
            k--;
        }
        return k;
    }
};
// @lc code=end
