/*
 * @lc app=leetcode.cn id=947 lang=cpp
 *
 * [947] 移除最多的同行或同列石头
 */

// @lc code=start
class Solution
{
public:
    vector<int> parent;
    int find(int n)
    {
        if (parent[n] == n)
            return n;
        else
        {
            parent[n] = find(parent[n]);
        }
        return parent[n];
    }

    void uni(int a, int b)
    {
        parent[find(a)] = find(b);
    }
    int removeStones(vector<vector<int>> &stones)
    {
        unordered_map<int, vector<int>> rowmap, colmap;
        for (int i = 0; i < stones.size(); i++)
        {
            rowmap[stones[i][0]].push_back(i);
            colmap[stones[i][1]].push_back(i);
        }

        for (int i = 0; i < stones.size(); i++)
        {
            parent.push_back(i);
        }

        for (int i = 0; i < stones.size(); i++)
        {
            for (int j : rowmap[stones[i][0]])
            {
                uni(i, j);
            }
            for (int j : colmap[stones[i][1]])
            {
                uni(i, j);
            }
        }

        unordered_set<int> unique;
        for (int n : parent)
        {
            unique.insert(find(n));
        }
        return stones.size() - unique.size();
    }
};
// @lc code=end
