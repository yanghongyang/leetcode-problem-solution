/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-11 17:12:51
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-11 17:22:49
 */
/*
 * @lc app=leetcode.cn id=1108 lang=cpp
 *
 * [1108] IP 地址无效化
 */

// @lc code=start
// class Solution
// {
// public:
//     string defangIPaddr(string a)
//     {
//         for (int i = 0; i < a.length(); i++)
//         {
//             if (a[i] == '.')
//             {
//                 a.replace(i, 1, "[.]");
//                 i += 2;
//             }
//         }
//         return a;
//     }
// };
class Solution
{
public:
    string defangIPaddr(string a)
    {
        string res;
        for (char c : a)
        {
            if (c == '.')
                res += "[.]";
            else
                res += c;
        }
        return res;
    }
};
// @lc code=end
