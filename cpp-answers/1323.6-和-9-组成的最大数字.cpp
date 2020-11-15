/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-16 06:52:22
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-16 06:55:08
 */
/*
 * @lc app=leetcode.cn id=1323 lang=cpp
 *
 * [1323] 6 和 9 组成的最大数字
 */

// @lc code=start
class Solution
{
public:
    int maximum69Number(int num)
    {
        /*
        int n = num, i = 0, j = -1;
        while (n)
        {
            if (n % 10 == 6)
                j = i;
            i++;
            n /= 10;
        }
        if (j == -1)
            return num;
        return num + pow(10, j) * 3;
        */
        string s = to_string(num);
        for (char &ch : s)
        {
            if (ch == '6')
            {
                ch = '9';
                break;
            }
        }
        return stoi(s);
    }
};
// @lc code=end
