/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-07 17:56:44
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-07 18:31:57
 */
/*
 * @lc app=leetcode.cn id=1089 lang=cpp
 *
 * [1089] 复写零
 */

// @lc code=start
class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        int i, j, n = arr.size();
        for (i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                arr.insert(arr.begin() + i, 0);
                arr.pop_back();
                i++;
            }
        }
        return;
    }
};
// @lc code=end
