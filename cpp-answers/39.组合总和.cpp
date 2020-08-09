/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    //回溯，多么明显的套路题！呵！（辉夜姬的嘲笑）
    /*
    void dfs(int pos, int target, vector<int>& tmp, vector<vector<int>>& res, vector<int>& candidates)
    {
        if(target == 0)
        {
            res.push_back(tmp);
            return ;
        }
        if(pos == candidates.size() || (target - candidates[pos]) < 0)
            return ;

        tmp.push_back(candidates[pos]);

        dfs(pos, target - candidates[pos], tmp, res, candidates);

        tmp.pop_back();

        dfs(pos + 1, target, tmp, res, candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        vector<int> tmp;
        dfs(0, target, tmp, res, candidates);
        return res;
    }*/

    //这道题其实还有迭代解法，对应的是动态规划（持怀疑态度，感觉最优子结构什么的不是很明晰）
    //万分感谢C++强大的STL
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        unordered_map<int, set<vector<int>>> res;   //建立整数到集合的映射，集合中包含和为该整数的所有组合）
        for(int i = 1; i <= target; i++)    //对于i来讲，从1一直循环计算到target
        {
            for(auto it : candidates)   //对于candidates中的每个数
            {
                if(it == i) //最理想的情况当然是i存在于candidates中啦，这样直接放在对应的集合里就行啦
                    res[i].insert(vector<int>{it});
                else if(it < i) //但是很多情况下it的值是比i小的，因此就需要看是否能在candidates中找到值为i-it的数字，将其对应的集合加到答案里
                {
                    for(auto tmp : res[i - it])
                    {
                        tmp.push_back(it);  //这里选择加it是因为tmp每一次都更新，但是it是固定的。方便。
                        sort(tmp.begin(), tmp.end());   //啊这...这里必须进行排序，防止出现[2,2,3]和[2,3,2]的情况（实际上两者的和都是7）
                        if(res[i].count(tmp) == 0)  //看有没有重复的
                            res[i].insert(tmp);
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for(auto it : res[target])
            ans.push_back(it);
        return ans;
    }
};
// @lc code=end

