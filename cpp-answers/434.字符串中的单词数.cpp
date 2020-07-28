/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-18 18:01:11
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-18 18:03:45
 */ 
/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 */

// @lc code=start
class Solution {
public:
    int countSegments(string s) {
        stringstream ss(s);
        string word;
        int count = 0;
        while(ss >> word)
            count++;
        return count;
    }
};
// @lc code=end

