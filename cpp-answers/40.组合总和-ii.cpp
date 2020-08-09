/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    //回溯算法，从组合总和I的代码直接改改就行了...
/*     void dfs(int pos, int target, int n, vector<int>& tmp, vector<vector<int>>& res, vector<int>& candidates)
    {
        if(target == 0)
        {
            res.push_back(tmp);
            return ;
        }
        int i = pos;
        while(i < n && target - candidates[i] >= 0)
        {
            if(i == pos || candidates[i] != candidates[i - 1])
            {
                tmp.push_back(candidates[i]);

                dfs(i + 1, target - candidates[i], n, tmp, res, candidates);

                tmp.pop_back();
            }
            i++;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        vector<int> tmp;
        dfs(0, target, candidates.size(), tmp, res, candidates);
        return res;
    } */

    //动态规划，准确地说是0-1背包
    //......这0-1背包能写成这个鬼模样不愧是我
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        unordered_map<int, set<vector<int>>> res;   //建立整数到集合的映射，集合中包含和为该整数的所有组合）
        for(int i = 1; i <= target; i++)    //对于i来讲，从1一直循环计算到target
        {
            for(int j = 0; j < candidates.size(); j++)   //对于candidates中的每个数
            {
                if(candidates[j] == i) //最理想的情况当然是i存在于candidates中啦，这样直接放在对应的集合里就行啦
                {
                    if(res[i].count(vector<int>{j}) == 0)
                        res[i].insert(vector<int>{j}); 
                }    
                else if(candidates[j] < i) //但是很多情况下it的值是比i小的，因此就需要看是否能在candidates中找到值为i-it的数字，将其对应的集合加到答案里
                {
                    for(auto tmp : res[i - candidates[j]])
                    {
                        vector<int> t(tmp);
                        if(find(t.begin(), t.end(), j) == t.end())
                        {
                            t.push_back(j);
                            sort(t.begin(), t.end());
                            if(res[i].count(t) == 0)
                                res[i].insert(t);
                        }
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for(auto it : res[target])
        {
            vector<int> tmp;
            for(auto itt : it)
            {
                tmp.push_back(candidates[itt]);
            }
            sort(tmp.begin(), tmp.end());
            if(find(ans.begin(), ans.end(), tmp)== ans.end())
                ans.push_back(tmp);
        }
        return ans;
    }
};
// @lc code=end

