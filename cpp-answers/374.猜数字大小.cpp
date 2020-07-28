/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-20 11:20:45
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-20 11:25:33
 */
/*
 * @lc app=leetcode.cn id=374 lang=cpp
 *
 * [374] 猜数字大小
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
public:
    int guessNumber(int n)
    {
        int left = 1, right = n;
        int mid;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (guess(mid) == 0)
                return mid;
            else if (guess(mid) < 0)
                right = mid - 1;
            else if (guess(mid) > 0)
                left = mid + 1;
        }
        return left - 1;
    }
};
// @lc code=end
