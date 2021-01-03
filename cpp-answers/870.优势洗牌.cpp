/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2021-01-03 19:38:08
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2021-01-03 20:52:50
 */
/*
 * @lc app=leetcode.cn id=870 lang=cpp
 *
 * [870] 优势洗牌
 */

// @lc code=start
class Solution
{
public:
    //用了非常不优雅的数据结构，其实不用这么麻烦的
    /*     vector<int> advantageCount(vector<int> &A, vector<int> &B)
    {
        vector<int> ans;
        if (A.size() != B.size() || A.size() <= 0 || B.size() <= 0)
            return ans;
        vector<int> tA(A.begin(), A.end());
        sort(tA.begin(), tA.end());
        queue<pair<int, int>> mp;
        for (int i = 0; i < B.size(); i++)
        {
            int j = upper_bound(tA.begin(), tA.end(), B[i]) - tA.begin();
            if (upper_bound(tA.begin(), tA.end(), B[i]) != tA.end())
            {
                mp.push(make_pair(B[i], tA[j]));
                tA.erase(tA.begin() + j);
            }
            else //如果没找到优势对，则只能将tA中最小的数进行匹配
            {
                mp.push(make_pair(B[i], tA[0]));
                tA.erase(tA.begin());
            }
        }
        while (!mp.empty())
        {
            pair<int, int> tmp = mp.front();
            mp.pop();
            ans.push_back(tmp.second);
        }
        return ans;
    } */
    /*     vector<int> advantageCount(vector<int> &A, vector<int> &B)
    {
        vector<int> ans;
        if (A.size() != B.size() || A.size() <= 0 || B.size() <= 0)
            return ans;
        sort(A.begin(), A.end());
        for (int i = 0; i < B.size(); i++)
        {
            auto iter = upper_bound(A.begin(), A.end(), B[i]);
            if (iter != A.end())
            {
                ans.push_back(*iter);
                A.erase(iter);
            }
            else //如果没找到优势对，则只能将tA中最小的数进行匹配
            {
                ans.push_back(A[0]);
                A.erase(A.begin());
            }
        }
        return ans;
    } */
    vector<int> advantageCount(vector<int> &A, vector<int> &B)
    {
        vector<int> ans;
        if (A.size() != B.size() || A.size() <= 0 || B.size() <= 0)
            return ans;
        multiset<int> mA(A.begin(), A.end());
        for (int i = 0; i < B.size(); i++)
        {
            auto iter = mA.upper_bound(B[i]);
            if (iter != mA.end())
            {
                ans.push_back(*iter);
                mA.erase(iter);
            }
            else //如果没找到优势对，则只能将tA中最小的数进行匹配
            {
                ans.push_back(*mA.begin());
                mA.erase(mA.begin());
            }
        }
        return ans;
    }
};
// @lc code=end
