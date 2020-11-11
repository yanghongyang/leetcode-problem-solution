/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-11 18:00:53
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-11 18:10:15
 */
/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

// @lc code=start
class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        int p1 = 0, p2 = 0;
        int end = max(version1.size(), version2.size());
        while (p1 < end || p2 < end)
        {
            int v1 = 0, v2 = 0;
            while (p1 < version1.size() && version1[p1] != '.')
            {
                v1 = v1 * 10 + version1[p1] - '0';
                p1++;
            }
            while (p2 < version2.size() && version2[p2] != '.')
            {
                v2 = v2 * 10 + version2[p2] - '0';
                p2++;
            }
            if (v1 > v2)
                return 1;
            else if (v1 < v2)
                return -1;
            p1++;
            p2++;
        }
        return 0;
    }
};
// @lc code=end
