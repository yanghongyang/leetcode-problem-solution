/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-11 15:41:39
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-11 15:52:27
 */
/*
 * @lc app=leetcode.cn id=748 lang=cpp
 *
 * [748] 最短完整词
 */

// @lc code=start
class Solution
{
public:
    string shortestCompletingWord(string licensePlate, vector<string> &words)
    {
        unordered_map<char, int> license_hash, current_hash;
        string word = "";
        bool flag = true;

        for (char &ch : licensePlate)
        {
            if (isalpha(ch))
            {
                ch = tolower(ch);
                license_hash[ch]++;
            }
        }

        for (string str : words)
        {
            flag = true;
            for (char ch : str)
                current_hash[ch]++;

            for (char ch : licensePlate)
            {
                if (isalpha(ch) && (current_hash[ch] < license_hash[ch] || current_hash.find(ch) == current_hash.end()))
                {
                    flag = false;
                    break;
                }
            }
            current_hash.clear();
            if (!flag)
                continue;

            if (word == "")
                word = str;
            else
            {
                word = (str.size() >= word.size()) ? word : str;
            }
        }

        return word;
    }
};
// @lc code=end
