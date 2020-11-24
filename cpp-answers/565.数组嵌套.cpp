/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-24 20:34:48
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-24 20:42:18
 */
/*
 * @lc app=leetcode.cn id=565 lang=cpp
 *
 * [565] 数组嵌套
 */

// @lc code=start
class Solution
{
public:
    int arrayNesting(vector<int> &nums)
    {
        int slow;
        int res = 0;
        int n = nums.size();
        if (n <= 0)
            return 0;
        for (int i = 0; i < n; i++)
        {
            slow = i;
            int cnt = 0;
            while (nums[slow] >= 0)
            {
                cnt++;
                int tmp = nums[slow];
                nums[slow] = -1;
                slow = tmp;
            }
            res = max(res, cnt);
        }
        return res;
    }
};
// @lc code=end
