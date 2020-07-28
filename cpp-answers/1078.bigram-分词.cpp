/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-03 16:00:44
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-03 16:07:07
 */
/*
 * @lc app=leetcode.cn id=1078 lang=cpp
 *
 * [1078] Bigram 分词
 */

// @lc code=start
class Solution
{
public:
    vector<string> findOcurrences(string text, string first, string second)
    {
        vector<string> res;
        vector<string> words;
        string word = "";
        //words中存储text中的所有单词
        for (int i = 0; i < text.size(); i++)
        {
            if (text[i] == ' ')
            {
                words.push_back(word);
                word = "";
            }
            else
                word += text[i];
        }
        words.push_back(word);
        for (int i = 0; i < words.size() - 2; i++)
        {
            if (words[i] == first && words[i + 1] == second)
                res.push_back(words[i + 2]);
        }
        return res;
    }
};
// @lc code=end
