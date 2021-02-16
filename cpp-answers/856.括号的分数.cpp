/*
 * @lc app=leetcode.cn id=856 lang=cpp
 *
 * [856] 括号的分数
 */

// @lc code=start
class Solution
{
public:
    int scoreOfParentheses(string S)
    {
        vector<pair<int, int>> sta;
        int ans = 0;

        for (int i = 0; i < S.size(); i++)
        {
            if (sta.empty() || S[i] == '(')
            {
                sta.push_back(make_pair(S[i], 0)); // 暂时不知道当前括号的值，所以填入0
            }
            else if (S[i] == ')')
            {
                int tmp = sta.back().second * 2; // (A) => 2*A
                if (tmp == 0)                    // () => 1
                {
                    tmp = 1;
                }
                sta.pop_back(); // 出栈，这个数已经计算完了
                if (sta.empty())
                {
                    ans += tmp;
                }
                else
                {
                    sta.back().second += tmp; // AB => A+B
                }
            }
        }
        return ans;
    }
};
// @lc code=end
