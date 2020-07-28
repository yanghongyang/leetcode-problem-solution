/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-18 16:34:14
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-18 16:44:20
 */ 
/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        //二分查找
        /*
        if (num < 2)
            return true;
        int left = 2, right = num / 2;
        long mid;
        long  res = 0;
        while(left <= right)
        {
            mid = (left + right) / 2;
            res = mid * mid;
            if(res  == num)
                return true;
            else if(res < num)
            {
                left = mid + 1;
            }
            else if(res > num)
            {
                right = mid - 1;
            }
        }
        return false;
        */
        //牛顿迭代法
        if(num < 2)
            return true;
        long x = num / 2;
        while(x * x > num)
        {
            x = (x + num / x) / 2;
        }
        return x * x == num;
    }
};
// @lc code=end

