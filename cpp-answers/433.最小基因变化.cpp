/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-17 20:01:46
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-17 20:10:50
 */
/*
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
 */

// @lc code=start
class Solution
{
public:
    int minMutation(string start, string end, vector<string> &bank)
    {
        //记录所有可以访问的节点
        unordered_set<string> candidate(bank.begin(), bank.end());
        //记录基因和step
        queue<pair<string, int>> q;

        q.push({start, 0});

        string gene;
        int step;
        while (!q.empty())
        {
            //终止条件，当队列当前的string和end相等时，就可以返回了
            if (q.front().first == end)
            {
                return q.front().second;
            }
            gene = q.front().first;
            step = q.front().second;
            q.pop();
            for (int i = 0; i < gene.size(); i++)
            {
                char tmp = gene[i]; //记录原来的状态
                for (char base : "ATCG")
                {
                    if (gene[i] == base) //如果当前gene的当前字母=base，则直接跳过，不用变
                        continue;
                    gene[i] = base;                              //修改碱基
                    if (candidate.find(gene) != candidate.end()) //如果在candidate中找到了
                    {
                        q.push({gene, step + 1});
                        //与此同时，candidate要删掉相对应的gene
                        candidate.erase(gene);
                    }
                }
                gene[i] = tmp; //恢复状态，因为一次只能更改一个位置
            }
        }
        return -1;
    }
};
// @lc code=end
