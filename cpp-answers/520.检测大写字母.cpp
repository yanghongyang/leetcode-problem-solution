/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-19 22:04:43
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-20 11:18:13
 */
/*
 * @lc app=leetcode.cn id=520 lang=cpp
 *
 * [520] 检测大写字母
 */

// @lc code=start
class Solution
{
public:
    /*
    bool detectCapitalUse(string word)
    {
        if (word.size() == 1)
            return true;
        string high, low, other;
        for (int i = 0; i < word.size(); i++)
        {
            high += toupper(word[i]);
            low += tolower(word[i]);
            if (i == 0)
                other += toupper(word[i]);
            else
                other += tolower(word[i]);
        }
        return word == high || word == low || word == other;
    }*/
    bool detectCapitalUse(string word)
    {
        int cnt = 0;
        int len = (int)word.length();
        for (int i = 0; i < len; i++)
        {
            if (word[i] >= 'A' && word[i] <= 'Z')
                cnt++;
        }
        if (cnt == 0 || (cnt == 1 && word[0] <= 'Z') || cnt == len)
            return true;
        else
            return false;
    }
};
// @lc code=end
