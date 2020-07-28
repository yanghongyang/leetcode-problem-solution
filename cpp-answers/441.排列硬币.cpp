/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-18 17:42:34
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-18 17:44:38
 */ 
/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 */

// @lc code=start
class Solution {
public:
    int arrangeCoins(int n) {
        int i = 1;
        while(n >= i)
        {
            n -= i;
            i++;
        }
        return i - 1;
    }
};
// @lc code=end

