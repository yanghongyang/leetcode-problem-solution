/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-25 10:46:15
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-25 10:48:15
 */
/*
 * @lc app=leetcode.cn id=1295 lang=cpp
 *
 * [1295] 统计位数为偶数的数字
 */

// @lc code=start
class Solution
{
public:
    int check(int num)
    {
        int cnt = 0;
        while (num)
        {
            cnt++;
            num /= 10;
        }
        return cnt;
    }
    int findNumbers(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (check(nums[i]) % 2 == 0)
                ans++;
        }
        return ans;
    }
};
// @lc code=end
