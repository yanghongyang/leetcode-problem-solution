/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-22 20:57:44
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-19 10:25:28
 */
/*
 * @lc app=leetcode.cn id=859 lang=cpp
 *
 * [859] 亲密字符串
 */

// @lc code=start
class Solution
{
public:
    bool buddyStrings(string A, string B)
    {
        vector<int> noteq;
        int sa = A.size(), sb = B.size();
        if (sa != sb)
            return false;
        bool repeats = false;
        char repeat[26] = {0};
        for (int i = 0; i < sa; i++)
        {
            if (A[i] != B[i])
            {
                noteq.push_back(i);
                if (noteq.size() > 2)
                    return false;
            }
            else if (!repeats)
            {
                if (repeat[A[i] - 'a'])
                    repeats = true;
                else
                    repeat[A[i] - 'a']++;
            }
        }
        if (noteq.size() == 2 && A[noteq[0]] == B[noteq[1]] && A[noteq[1]] == B[noteq[0]])
            return true;
        if (noteq.size() == 0 && repeats)
            return true;
        return false;
    }
};
// @lc code=end
