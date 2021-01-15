/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */

// @lc code=start
class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        if (dungeon.size() <= 0 || dungeon[0].size() <= 0)
            return 1;
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<int> row(n + 1, INT_MAX);
        row[n - 1] = 1; //右下角的值肯定为0
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                int tmp = min(row[j], row[j + 1]) - dungeon[i][j];
                row[j] = max(tmp, 1);
            }
        }
        return row[0];
    }
};
// @lc code=end
