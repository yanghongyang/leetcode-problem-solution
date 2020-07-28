/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-19 09:39:07
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-19 10:09:52
 */
/*
 * @lc app=leetcode.cn id=747 lang=cpp
 *
 * [747] 至少是其他数字两倍的最大数
 */

// @lc code=start
/* class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        int j = *max_element(nums.begin(), nums.end());
        int ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == j)
            {
                ans = i;
                continue;
            }
            if (nums[i] * 2 > j)
                return -1;
        }
        return ans;
    }
}; */
class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        int n = nums.size();
        int tindex = 0;
        int tmpmax = -1;
        int tmpsecondmax = -1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > tmpsecondmax)
            {
                if (nums[i] > tmpmax)
                {
                    tmpsecondmax = tmpmax;
                    tmpmax = nums[i];
                    tindex = i;
                }
                else
                {
                    tmpsecondmax = nums[i];
                }
            }
        }
        if (tmpsecondmax * 2 <= tmpmax)
        {
            return tindex;
        }
        return -1;
    }
};
// @lc code=end
