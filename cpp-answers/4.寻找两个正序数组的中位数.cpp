/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-25 23:45:23
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-09 22:48:33
 */
/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution
{
public:
    int kth(vector<int> &a, int m, vector<int> &b, int n, int k)
    {
        if (m < n)
            return kth(b, n, a, m, k);
        if (n == 0)
            return a[k - 1];
        if (k == 1)
            return min(a[0], b[0]);

        int j = min(n, k / 2);
        int i = k - j;
        if (a[i - 1] > b[j - 1])
            return kth(a, i, b + j, n - j, k - j);
        return kth(a + i, m - i, b, j, k - i);
    }
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        int k = (m + n) / 2;
        int m1 = kth(nums1, m, nums2, n, k + 1);
        if ((m + n) % 2 == 0)
        {
            int m2 = kth(nums1, m, nums2, n, k);
            return ((double)(m1 + m2)) / 2.0;
        }
        return m1;
    }
};
// @lc code=end
