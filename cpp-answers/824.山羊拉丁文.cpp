/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-22 20:41:33
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-22 20:52:52
 */
/*
 * @lc app=leetcode.cn id=824 lang=cpp
 *
 * [824] 山羊拉丁文
 */

// @lc code=start
class Solution
{
public:
    string toGoatLatin(string s)
    {
        int l = s.size();
        stringstream ss(s);
        string res = "";
        string word;
        string vowel = "aeiouAEIOU";
        int count = 0;
        while (ss >> word)
        {
            count++;
            if (vowel.find(word[0]) != string::npos)
            {
                word = word + "ma";
                int index = count;
                while (index != 0)
                {
                    word = word + "a";
                    index--;
                }
                res = res + word + " ";
            }
            else
            {
                char cnst = word[0];
                word.erase(word.begin() + 0);
                word = word + cnst + "ma";
                int index = count;
                while (index != 0)
                {
                    word = word + "a";
                    index--;
                }
                res = res + word + " ";
            }
        }
        res.erase(res.begin() + res.length() - 1);
        return res;
    }
};
// @lc code=end
