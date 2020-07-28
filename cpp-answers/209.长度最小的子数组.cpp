/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-28 17:48:47
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-28 18:20:27
 */
/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution
{
public:
    //暴力法
    /*
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                if (sum >= s)
                {
                    ans = min(ans, j - i + 1);
                    break;
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }*/
    //前缀和+二分查找
    /*
        在确定每个子数组的开始下标后，找到长度最小的子数组需要O(n)的时间。如果使用二分查找，可以将时间优化到O(logn)。
        为了使用二分查找，需要额外创建一个数组sums用于存储数组nums的前缀和，其中sums[i]表示从numms[0]到nums[i - 1]的元素和。
        得到前缀和之后，对于每个开始下标i，可以通过二分查找得到大于或等于i的最小下标bound，
        使得sums[bound] - sums[i - 1] >= s，并更新子数组的最小长度（此时子数组的长度是bound-(i-1))。
        因为这道题保证了数组中每个元素都为正，所以前缀和一定是递增的，这一点保证了二分的正确性。
        **如果题目没有说明数组中每个元素都为正，则不能使用二分查找。**
    */
    /*
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        int ans = INT_MAX;
        vector<int> sums(n + 1, 0);
        //为了方便计算，零size = n + 1
        //sums[0] = 0意味着前0个元素的前缀和为0
        //sum[1] = A[0]表示前1个元素的前缀和为A[0]
        for (int i = 1; i <= n; i++)
        {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        for (int i = 1; i <= n; i++)
        {
            int target = s + sums[i - 1];
            auto bound = lower_bound(sums.begin(), sums.end(), target);
            if (bound != sums.end())
            {
                ans = min(ans, static_cast<int>((bound - sums.begin()) - (i - 1)));
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }*/
    //双指针
    /*
        定义两个指针start和end分别表示子数组的开始位置和结束位置，维护变量sum存储子数组中的元素和
        （即从nums[start]到nums[end]的元素和）。
        初始状态下，start和end都指向下标0，sum的值为0
        每一次迭代，将nums[end]加到sum，如果sum>=s，则更新子数组的最小长度（此时子数组的长度是end - start + 1）
        然后将nums[start]从sum中减去并将start右移，直到sum<s，在此过程中同样更新子数组的最小长度。
        每一轮迭代的最后，将end右移。
    */
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        int ans = INT_MAX;
        int start = 0, end = 0;
        int sum = 0;
        while (end < n)
        {
            sum += nums[end];
            while (sum >= s)
            {
                ans = min(ans, end - start + 1);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
// @lc code=end
