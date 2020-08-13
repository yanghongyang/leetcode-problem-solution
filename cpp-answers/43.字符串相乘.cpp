/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution
{
public:
    string multiply(string a, string b)
    {
        if (a == "0" || b == "0")
            return "0";
        int m = a.size() - 1, n = b.size() - 1;
        int carry = 0;
        string product;
        for (int i = 0; i <= m + n || carry; i++)
        {
            for (int j = max(0, i - n); j <= min(i, m); j++)
            {
                carry += (a[m - j] - '0') * (b[n - i + j] - '0');
            }
            product += carry % 10 + '0';
            carry /= 10;
        }
        reverse(product.begin(), product.end());
        return product;
    }
};
// @lc code=end
