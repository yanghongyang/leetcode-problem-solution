/*
 * @Author: your name
 * @Date: 2020-05-31 00:05:55
 * @LastEditTime: 2020-05-31 00:07:54
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \-Insgram-e:\leetcode刷题\88.合并两个有序数组.cpp
 */
/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1, j = n - 1;
        int tar = m + n - 1;
        while (j >= 0)
        {
            nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
    }
};
// @lc code=end
