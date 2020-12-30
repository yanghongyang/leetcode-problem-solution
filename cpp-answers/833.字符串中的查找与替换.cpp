/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-12-30 08:29:37
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-12-30 08:56:08
 */
/*
 * @lc app=leetcode.cn id=833 lang=cpp
 *
 * [833] 字符串中的查找与替换
 */

// @lc code=start
class Solution
{
public:
    string findReplaceString(string S, vector<int> &indexes, vector<string> &sources, vector<string> &targets)
    {
        vector<pair<int, int>> cnt;
        for (int i = 0; i < indexes.size(); i++)
        {
            cnt.push_back(make_pair(indexes[i], i)); //建立index中各个数和其位置的映射，以方便后续查找sources和targets
        }
        sort(cnt.begin(), cnt.end(), greater<pair<int, int>>()); //将indexes按照从大到小的顺序排列

        for (auto i : cnt)
        {
            string source = sources[i.second];
            string target = targets[i.second];
            int index = i.first;
            if (index + source.size() <= S.size())
            {
                string tmp = S.substr(index, source.size());
                if (tmp == source)
                {
                    S.erase(S.begin() + index, S.begin() + index + source.size());
                    S.insert(index, target);
                }
            }
        }
        return S;
    }
};
// @lc code=end
