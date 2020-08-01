/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-05-30 01:28:47
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-01 18:46:14
 */
/*
 * @lc app=leetcode.cn id=1441 lang=cpp
 *
 * [1441] 用栈操作构建数组
 */

// @lc code=start
class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        vector<string> a;
        int b = 0;
        for (int x : target)
            b = max(b, x);

        unordered_set<int> s(target.begin(), target.end());
        for (int i = 1; i <= b; i++)
        {
            if (s.count(i) != 0)
                a.push_back("Push");
            else
            {
                a.push_back("Push");
                a.push_back("Pop");
            }
        }
        return a;
    }
};
// @lc code=end
