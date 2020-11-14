/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-14 08:10:55
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-14 08:41:44
 */
/*
 * @lc app=leetcode.cn id=1122 lang=cpp
 *
 * [1122] 数组的相对排序
 */

// @lc code=start
class Solution
{
public:
    /*     vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        unordered_map<int, int> cnt;
        for (int i = 0; i < arr2.size(); i++)
        {
            cnt[arr2[i]] = i;
        }

        sort(arr1.begin(), arr1.end(), [&](int x, int y) {
            if (cnt.count(x))
            {
                return cnt.count(y) ? cnt[x] < cnt[y] : true;
            }
            else
            {
                return cnt.count(y) ? false : x < y;
            }
        });

        return arr1;
    } */
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        vector<int> cnt(1005, 0);
        for (int x : arr1)
        {
            cnt[x]++;
        }
        vector<int> ans;
        for (int x : arr2)
        {
            while (cnt[x] > 0)
            {
                ans.push_back(x);
                cnt[x]--;
            }
        }
        //处理剩下的
        for (int i = 0; i <= 1000; i++)
        {
            for (int j = 0; j < cnt[i]; j++)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
// @lc code=end
