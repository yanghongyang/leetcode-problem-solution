/*
 * @Author: your name
 * @Date: 2020-06-07 08:02:39
 * @LastEditTime: 2020-06-07 08:12:33
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode刷题\299.猜数字游戏.cpp
 */
/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 */

// @lc code=start
class Solution
{
public:
    string getHint(string secret, string guess)
    {
        unordered_map<char, int> s_map;
        unordered_map<char, int> g_map;
        int n = secret.size();
        int A = 0, B = 0;
        for (int i = 0; i < n; i++)
        {
            char s = secret[i], g = guess[i];
            if (s == g)
                A++;
            else
            {
                if (s_map[g] > 0)
                {
                    s_map[g]--;
                    B++;
                }
                else
                    g_map[g]++;
                if (g_map[s] > 0)
                {
                    g_map[s]--;
                    B++;
                }
                else
                    s_map[s]++;
            }
        }
        return to_string(A) + "A" + to_string(B) + "B";
    }
};
// @lc code=end
