/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-02 16:37:46
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-02 16:52:25
 */
/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> total;

        int n = nums.size();
        if (n < 4)
            return total;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                break; //之后的数字肯定不符合

            if (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target)
                continue; //如果当前数字和最大的3个数字的和都小于target，那这之间肯定不存在3个数使得4数之和=target

            for (int j = i + 1; j < n - 2; j++)
            { //找剩下的三个数
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue; //去除掉可能存在的重复
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                    break; //同理，这之后的数字肯定也不符合
                if (nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target)
                    continue; //同理，当前的两个数字和最大的2个数字的和都小于target，那也肯定不存在2个数使得4数之和=target
                int left = j + 1, right = n - 1;
                while (left < right)
                {
                    int sum = nums[left] + nums[right] + nums[i] + nums[j];
                    if (sum < target)
                        left++;
                    else if (sum > target)
                        right--;
                    else
                    {
                        total.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        do
                        {
                            left++;
                        } while (nums[left] == nums[left - 1] && left < right); //考虑重复的情况（左边界）
                        do
                        {
                            right--;
                        } while (nums[right] == nums[right + 1] && left < right); //考虑重复的情况（右边界）
                    }
                }
            }
        }

        return total;
    }
};
// @lc code=end
