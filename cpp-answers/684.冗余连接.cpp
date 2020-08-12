/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

// @lc code=start
class Solution {
public:
    int parent[1005];
    int find(int x)
    {
        while(parent[x] != x)
        {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    bool union_xy(int x, int y)
    {
        int root_x = find(x);
        int root_y = find(y);
        if(root_x == root_y)
            return false;
        parent[root_x] = root_y;
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        for(int i = 1; i <= 1000; i++)
        {
            parent[i] = i;
        }
        for(auto edge : edges)
        {
            if(!union_xy(edge[0], edge[1]))
            {
                return edge;
            }
        }
        return {};
    }
};
// @lc code=end

