/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-14 22:33:31
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-14 22:35:08
 */
/*
 * @lc app=leetcode.cn id=1502 lang=cpp
 *
 * [1502] 判断能否形成等差数列
 */

// @lc code=start
class Solution
{
public:
    bool canMakeArithmeticProgression(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        if (arr.size() < 2)
            return true;
        int diff = arr[1] - arr[0];
        for (int i = 2; i < arr.size(); i++)
        {
            int tmp = arr[i] - arr[i - 1];
            if (diff != tmp)
                return false;
        }
        return true;
    }
};
// @lc code=end
