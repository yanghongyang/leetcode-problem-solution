/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-12-30 09:43:05
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-12-30 10:25:21
 */
/*
 * @lc app=leetcode.cn id=834 lang=cpp
 *
 * [834] 树中距离之和
 */

// @lc code=start
//树型DP
//题目思路抄自：https://leetcode-cn.com/problems/sum-of-distances-in-tree/solution/shou-hua-tu-jie-shu-zhong-ju-chi-zhi-he-shu-xing-d/
//笨猪爆破组永远滴神
//代码抄自题解下方评论区老哥的C++版本
class Solution
{
public:
    vector<vector<int>> graph; //图
    vector<int> distSum;       //距离和
    vector<int> nodeNum;       //子树节点个数（包括自己）
    //计算每个节点的子树节点个数和子树节点距离和，自底向上
    void childDistCount(int root, int parent)
    {
        for (auto &neighbor : graph[root]) //找到当前节点相连的邻居
        {
            if (neighbor == parent) //若当前节点的邻居为之前的父节点，则说明为叶子节点
                continue;
            childDistCount(neighbor, root); //统计邻居的子树结点个数
            nodeNum[root] += nodeNum[neighbor];
            //到neighbor点的子数组距离和+（因为root比neighbor多一步，所以到达root的距离还要再加上neighbor）
            distSum[root] += distSum[neighbor] + nodeNum[neighbor];
        }
    }
    //自上而下递推计算ret值，父节点的答案-子树节点个数+除子树节点外的其他节点个数
    void addOutDist(int root, int parent)
    {
        for (auto &neighbor : graph[root]) //找当前节点相连的邻居
        {
            if (neighbor == parent)
                continue;
            distSum[neighbor] = distSum[root] - nodeNum[neighbor] + (graph.size() - nodeNum[neighbor]);
            addOutDist(neighbor, root); //自上而下，接着更新root的邻居
        }
    }
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>> &edges)
    {
        if (N == 1)
            return {0};
        distSum.assign(N, 0);
        nodeNum.assign(N, 1);
        graph.assign(N, vector<int>{});
        for (auto &e : edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        childDistCount(0, -1);
        addOutDist(0, -1);
        return distSum;
    }
};
// @lc code=end
