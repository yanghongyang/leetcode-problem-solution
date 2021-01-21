/*
 * @lc app=leetcode.cn id=1487 lang=cpp
 *
 * [1487] 保证文件名唯一
 */

// @lc code=start
class Solution
{
public:
    vector<string> getFolderNames(vector<string> &names)
    {
        int n = names.size();
        vector<string> ans;
        unordered_map<string, int> cnt;
        for (int i = 0; i < n; i++)
        {
            cnt[names[i]]++;
            if (cnt[names[i]] == 1) //初次
            {
                ans.push_back(names[i]);
            }
            else //否则
            {
                int t = cnt[names[i]] - 1;
                while (true)
                {
                    string s = names[i] + "(" + to_string(t) + ")";
                    if (cnt.find(s) != cnt.end()) //如果能找到的话，说明已经存在了，就得继续标号
                    {
                        t++;
                    }
                    else
                        break; //如果没找到，就说明是要找的那个
                }
                string s = names[i] + "(" + to_string(t) + ")";
                ans.push_back(s);
                cnt[s]++;
            }
        }
        return ans;
    }
};
// @lc code=end
