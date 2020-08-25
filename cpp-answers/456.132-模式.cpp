/*
 * @lc app=leetcode.cn id=456 lang=cpp
 *
 * [456] 132模式
 */

// @lc code=start
class Solution
{
public:
    //脑筋急转弯似的思路
    //给发明者点了个赞赞
    /*     bool find132pattern(vector<int> &nums)
    {
        if (nums.size() < 3)
            return false;
        int i = 0; //1模式
        int j = 0; //3模式
        int k = 0; //2模式
        int n = nums.size();
        while (i < n)
        {
            while (i < n - 2 && nums[i] >= nums[i + 1])
                i++;
            j = i + 1;
            while (j < n - 1 && nums[j] <= nums[j + 1])
                j++;
            k = j + 1;
            while (k < n)
            {
                if (nums[k] < nums[j] && nums[k] > nums[i])
                    return true;
                else
                    k++;
            }
            i = j + 1;
        }
        return false;
    } */
    bool find132pattern(vector<int> &nums)
    {
        if (nums.size() < 3)
            return false;
        stack<int> max;
        int n = nums.size();
        int third = INT_MIN;
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] < third)
                return true;
            while (!max.empty() && nums[i] > max.top())
            {
                third = max.top();
                max.pop();
            }
            max.push(nums[i]);
        }
        return false;
    }
};
// @lc code=end
