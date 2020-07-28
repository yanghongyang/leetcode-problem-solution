/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-19 17:51:48
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-19 18:02:24
 */
/*
 * @lc app=leetcode.cn id=893 lang=cpp
 *
 * [893] 特殊等价字符串组
 */

// @lc code=start
class Solution
{
public:
    int numSpecialEquivGroups(vector<string> &A)
    {
        unordered_set<string> res;
        for (int i = 0; i < A.size(); i++)
        {
            res.insert(createhash(A[i]));
        }
        return res.size();
    }
    static string createhash(string a)
    {
        string res = "";
        vector<int> even(26, 0);
        vector<int> odd(26, 0);
        for (int i = 0; i < a.size(); i++)
        {
            if (i % 2 == 0)
            {
                even[a[i] - 'a']++;
            }
            else
            {
                odd[a[i] - 'a']++;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            while (even[i])
            {
                res += to_string(i + 'a');
                even[i]--;
            }
        }
        res += '.';
        for (int i = 0; i < 26; i++)
        {
            while (odd[i])
            {
                res += to_string(i + 'a');
                odd[i]--;
            }
        }
        return res;
    }
};
// @lc code=end
