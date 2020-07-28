/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-18 17:37:43
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-18 17:39:43
 */ 
/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 */

// @lc code=start
class Solution {
public:
    string convertToBase7(int num) {
        string s = "";
        int ng = 0;
        if(num == 0)
            return "0";
        if(num < 0)
            ng = 1;
        num = abs(num);
        while(num)
        {
            s = char(num % 7 + 48) + s;
            num /= 7;
        }
        if(ng)
            s = '-' + s;
        return s;
    }
};
// @lc code=end

