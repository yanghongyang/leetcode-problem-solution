/*
 * @Author: your name
 * @Date: 2020-06-13 22:13:26
 * @LastEditTime: 2020-08-23 12:19:26
 * @LastEditors: Hongyang_Yang
 * @Description: In User Settings Edit
 * @FilePath: \undefinede:\leetcode刷题\461.汉明距离.cpp
 */
/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution
{
public:
    //模拟
    /*     int hammingDistance(int x, int y)
    {
        int count = 0;
        while (x || y)
        {
            count += ((x & 1) ^ (y & 1));
            x = x >> 1;
            y = y >> 1;
        }
        return count;
    } */
    //Brian Kernighan算法
    int hammingDistance(int x, int y)
    {
        int tmp = x ^ y;
        int count = 0;
        while (tmp)
        {
            count++;
            tmp = tmp & (tmp - 1);
        }
        return count;
    }
};
// @lc code=end
