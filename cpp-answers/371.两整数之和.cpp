/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-18 17:51:58
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-18 18:00:13
 */ 
/*
 * @lc app=leetcode.cn id=371 lang=cpp
 *
 * [371] 两整数之和
 */

// @lc code=start
class Solution {
public:
    int getSum(int a, int b) {
        int sum = 0;
        while(b != 0)
        {
            sum = a ^ b;    //计算不带进位的a与b的值
            //当a & b的结果是负数时，左移就会造成符号位的溢出，
            //所以此处需要转换为unsigned int来避免可能出现的左移越界行为。
            b = ((unsigned int)(a & b)) << 1;   //计算进位
            a = sum;
        }
        return sum;
    }
};
// @lc code=end

