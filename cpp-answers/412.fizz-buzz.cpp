/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-17 21:32:25
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-03 15:12:15
 */
/*
 * @lc app=leetcode.cn id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */

// @lc code=start
class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> res;
        for (int i = 1; i <= n; i++)
        {
            res.push_back(i % 5 ? (i % 3 ? to_string(i) : "Fizz") : (i % 3 ? "Buzz" : "FizzBuzz"));
        }
        return res;
    }
};
// @lc code=end
