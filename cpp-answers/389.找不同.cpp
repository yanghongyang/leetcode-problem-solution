/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-14 18:46:13
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-17 21:31:23
 */ 
/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        char v = 0;
        for(char c : s)
            v ^= c;
        for(char c : t)
            v ^= c;
        return v;
    }
};
// @lc code=end

