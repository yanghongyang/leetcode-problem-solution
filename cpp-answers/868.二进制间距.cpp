/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-07 21:53:23
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-07 21:56:35
 */
/*
 * @lc app=leetcode.cn id=868 lang=cpp
 *
 * [868] 二进制间距
 */

// @lc code=start
class Solution
{
public:
    int binaryGap(int N)
    {
        string s = ""; //将数字转换成字符串二进制表示
        while (N)
        {
            int p = N % 2;
            if (p)
                s = '1' + s;
            else
                s = '0' + s;
            N /= 2;
        }
        int i = 0, k = 0;
        while (s[i] != '1') //找到字符串中第一个1
            i++;
        for (int j = i + 1; j < s.size(); j++)
        {
            while (s[j] == '0')
                j++;
            if (j >= s.size())
                break;
            k = max(k, j - i);
            i = j;
        }
        return k;
    }
};
// @lc code=end
