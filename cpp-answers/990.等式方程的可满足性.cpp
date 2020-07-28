/*
 * @Author: your name
 * @Date: 2020-06-08 08:52:52
 * @LastEditTime: 2020-06-08 08:57:47
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode刷题\990.等式方程的可满足性.cpp
 */
/*
 * @lc app=leetcode.cn id=990 lang=cpp
 *
 * [990] 等式方程的可满足性
 */

// @lc code=start
class UnionFind
{
private:
    vector<int> parent;

public:
    UnionFind()
    {
        parent.resize(26);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int index)
    {
        if (index == parent[index])
        {
            return index;
        }
        parent[index] = find(parent[index]);
        return parent[index];
    }

    void unite(int index1, int index2)
    {
        parent[find(index1)] = find(index2);
    }
};

class Solution
{
public:
    bool equationsPossible(vector<string> &equations)
    {
        UnionFind uf;
        for (const string &str : equations)
        {
            if (str[1] == '=')
            {
                int index1 = str[0] - 'a';
                int index2 = str[3] - 'a';
                uf.unite(index1, index2);
            }
        }
        for (const string &str : equations)
        {
            if (str[1] == '!')
            {
                int index1 = str[0] - 'a';
                int index2 = str[3] - 'a';
                if (uf.find(index1) == uf.find(index2))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
