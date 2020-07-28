/*
 * @Author: your name
 * @Date: 2020-06-13 19:25:33
 * @LastEditTime: 2020-06-13 19:27:44
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \undefinede:\leetcode刷题\278.第一个错误的版本.cpp
 */
/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int low = 1, high = n;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (!isBadVersion(mid))
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high + 1;
    }
};
// @lc code=end
