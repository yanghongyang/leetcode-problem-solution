/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-28 18:31:35
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-28 18:44:14
 */
/*
 * @lc app=leetcode.cn id=819 lang=cpp
 *
 * [819] 最常见的单词
 */

// @lc code=start
class Solution
{
public:
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        unordered_map<string, int> maps, mapban;
        int i = 0, m = 0;
        string str;
        string ans;
        int maxtime = 0;
        for (i = 0; i < banned.size(); i++)
            mapban[banned[i]]++;
        for (i = 0; i <= paragraph.size(); i++)
        {
            while (isalnum(paragraph[i]))
                str += tolower(paragraph[i++]);
            if (mapban[str] != 1 && str != "")
            {
                if (maxtime < ++maps[str])
                {
                    maxtime = maps[str];
                    ans = str;
                }
            }
            str.clear();
        }
        return ans;
    }
};
// @lc code=end
