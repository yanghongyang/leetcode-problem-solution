/*
 * @Author: your name
 * @Date: 2020-06-07 07:18:29
 * @LastEditTime: 2020-06-07 07:50:05
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode刷题\126.单词接龙-ii.cpp
 */
/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 */

// @lc code=start
class Solution
{
public:
    void dfs(string &beginword, string &curr, vector<string> path, unordered_map<string, vector<string>> &neighbor, vector<vector<string>> &res)
    {
        if (curr == beginword)
        {
            //如果已经到达了迭代终点
            path.push_back(curr);
            reverse(path.begin(), path.end());
            res.push_back(path);
            return;
        }
        //这里的path记录状态
        path.push_back(curr);
        for (auto word : neighbor[curr])
        {
            //对于邻接节点
            dfs(beginword, word, path, neighbor, res);
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        //建图，使用两个关键的数据结构
        unordered_map<string, int> depth;               //记录每个节点所在的高度
        unordered_map<string, vector<string>> neighbor; //记录每个节点所有的前向变化节点集（由curr -> temp，记录curr）
        //首先使用bfs建立节点集
        vector<vector<string>> res; //存储结果
        vector<string> path;
        if (std::find(wordList.begin(), wordList.end(), endWord) == wordList.end()) //如果在wordList里面找不到endword，直接结束
            return res;

        //将vector转化为哈希表，或者矩阵
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        //1. 使用BFS建图
        depth[beginWord] = 1;
        queue<string> Q;
        Q.push(beginWord);
        //从begin到end建图
        while (!Q.empty())
        {
            string curr = Q.front();
            Q.pop(); //将队列头元素弹出队列
            //针对于被弹出的队列头
            for (int i = 0; i < curr.size(); i++)
            {
                string temp = curr;
                for (char c = 'a'; c <= 'z'; c++)
                {
                    temp[i] = c;             //将temp当前的第i个字符改成c
                    if (wordSet.count(temp)) //如果wordSet里面有temp的话
                    {
                        if (depth.count(temp) == 0)
                        { //如果此时temp没有被添加到depth
                            Q.push(temp);
                            depth[temp] = depth[curr] + 1;  //更新高度表，temp的高度是当前curr的高度+1
                            neighbor[temp].push_back(curr); //将temp和curr建立反向连接
                        }
                        else if (depth[temp] == depth[curr] + 1) //如果已经更新好了高度表
                        {
                            neighbor[temp].push_back(curr);
                        }
                    }
                }
            }
        }
        //经过以上步骤，使用BFS成功建图
        //2. 使用dfs树状搜索
        dfs(beginWord, endWord, path, neighbor, res);
        return res;
    }
};
// @lc code=end
