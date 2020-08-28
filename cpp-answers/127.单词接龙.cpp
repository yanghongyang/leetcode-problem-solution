/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-28 16:32:26
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-28 17:01:09
 */
/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> s;
        for (auto &i : wordList)
            s.insert(i);

        queue<pair<string, int>> q;
        //加入beginWord
        q.push({beginWord, 1});

        string tmp; //每个节点的字符
        int step;   //抵达该节点的step

        while (!q.empty())
        {
            if (q.front().first == endWord)
            {
                return (q.front().second);
            }
            tmp = q.front().first;
            step = q.front().second;
            q.pop();

            //寻找下一个单词
            char ch;
            for (int i = 0; i < tmp.size(); i++)
            {
                ch = tmp[i];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    if (ch == c)
                        continue;
                    tmp[i] = c;
                    //如果在set中找到了该单词
                    if (s.find(tmp) != s.end())
                    {
                        q.push({tmp, step + 1});
                        s.erase(tmp); //删除该节点
                    }
                    tmp[i] = ch; //复原
                }
            }
        }
        return 0;
    }
};
// @lc code=end
