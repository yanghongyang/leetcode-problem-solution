/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-14 10:02:54
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-14 10:24:31
 */
/*
 * @lc app=leetcode.cn id=423 lang=cpp
 *
 * [423] 从英文中重建数字
 */

// @lc code=start
class Solution
{
public:
    /* 以下内容摘自官方题解
    注意到，所有的偶数都包含一个独特的字母：

    “z” 只在 “zero” 中出现。
    “w” 只在 “two” 中出现。
    “u” 只在 “four” 中出现。
    “x” 只在 “six” 中出现。
    “g” 只在 “eight” 中出现。

    这也是计算 3，5 和 7 的关键，因为有些单词只在一个奇数和一个偶数中出现（而且偶数已经被计算过了）：

    “h” 只在 “three” 和 “eight” 中出现。
    “f” 只在 “five” 和 “four” 中出现。
    “s” 只在 “seven” 和 “six” 中出现。

    接下来只需要处理 9和 0，思路依然相同。

    “i” 在 “nine”，“five”，“six” 和 “eight” 中出现。
    “n” 在 “one”，“seven” 和 “nine” 中出现。

    */
    string originalDigits(string s)
    {
        int char_counts[26] = {0};
        for (auto c : s)
            char_counts[c - 'a']++;
        int digits_counts[10] = {0};
        digits_counts[0] = char_counts['z' - 'a'];
        digits_counts[2] = char_counts['w' - 'a'];
        digits_counts[4] = char_counts['u' - 'a'];
        digits_counts[6] = char_counts['x' - 'a'];
        digits_counts[8] = char_counts['g' - 'a'];
        digits_counts[1] = char_counts['o' - 'a'] - digits_counts[0] - digits_counts[2] - digits_counts[4];
        digits_counts[3] = char_counts['r' - 'a'] - digits_counts[0] - digits_counts[4];
        digits_counts[5] = char_counts['f' - 'a'] - digits_counts[4];
        digits_counts[7] = char_counts['s' - 'a'] - digits_counts[6];
        digits_counts[9] = char_counts['i' - 'a'] - digits_counts[5] - digits_counts[6] - digits_counts[8];
        string result;
        for (int i = 0; i < 10; i++)
        {
            result.append(digits_counts[i], '0' + i);
        }
        return result;
    }
};
// @lc code=end
