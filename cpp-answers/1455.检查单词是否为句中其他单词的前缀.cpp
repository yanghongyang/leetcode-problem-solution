/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-08 11:26:03
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-08 11:27:14
 */
/*
 * @lc app=leetcode.cn id=1455 lang=cpp
 *
 * [1455] 检查单词是否为句中其他单词的前缀
 */

// @lc code=start
class Solution
{
public:
    int isPrefixOfWord(string sentence, string searchWord)
    {
        stringstream ss(sentence);
        string word;
        int i = 1;
        int len = searchWord.size();
        while (ss >> word)
        {
            string sub = word.substr(0, len);
            if (sub == searchWord)
                return i;
            i++;
        }
        return -1;
    }
};
// @lc code=end
