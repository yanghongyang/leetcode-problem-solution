/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-06 16:26:56
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-06 17:06:43
 */
/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */

// @lc code=start
//动态规划
//dp[i]为考虑前i个元素，以第i个数字解为的最长上升子序列的长度，nums[i]必须被选取
//从小到大计算dp[]数组的值，在计算dp[i]之前，已经计算出了dp[0...i-1]的值，则状态转移方程为：
//dp[i] = max(dp[j]) + 1, 其中0<=j<i且num[j]<num[i]
//整个数组的最长上升子序列为所有dp[i]中的最大值
/*
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        int maxans = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            int maxval = 0;
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    maxval = max(maxval, dp[j]);
                }
            }
            dp[i] = maxval + 1;
            maxans = max(maxans, dp[i]);
        }
        return maxans;
    }
};
*/
//贪心，如果我们要使上升子序列尽可能长，则需要让序列上升尽可能慢，因此每次在上升子序列最后加上的数尽可能小
//维护一个数组d[i]，表示长度为i的最长上升子序列的末尾元素的最小值，用len记录目前最长上升子序列的长度，起始时len=1，d[1] = nums[0]
//同时注意到d[i]是关于i单调递增的，如果d[j]>=d[i]且j<i，考虑从长度为i的最长上升子序列的末尾删除i-j个元素，那么这个序列长度变为j，且第j个元素x(末尾元素)必然小于d[i]，也就小于d[j]
//那么我们就找到了一个长度为j的最长上升子序列，并且末尾元素比d[j]小，从而产生了矛盾。
//根据d数组的单调性，使用二分查找寻找下标i，优化时间复杂度。
//设当前已求出的最长上升子序列的长度为 len（初始时为 11），从前往后遍历数组 nums，在遍历到 nums[i] 时：
//如果 nums[i]>d[len] ，则直接加入到 d 数组末尾，并更新len=len+1；
//否则，在 dd 数组中二分查找，找到第一个比nums[i] 小的数 d[k] ，并更新d[k+1]=nums[i]。
//时间复杂度：O(nlogn)
//空间复杂度：O(n)
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int len = 1;
        int n = (int)nums.size();
        if (n == 0)
            return 0;
        vector<int> d(n + 1, 0);
        d[len] = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > d[len])
                d[++len] = nums[i];
            else
            {
                int l = 1, r = len, pos = 0; //如果找不到说明所有的数都比nums[i]大，此时要更新d[1]，所以这里将pos设为0
                while (l <= r)
                {
                    int mid = (l + r) >> 1;
                    if (d[mid] < nums[i])
                    {
                        pos = mid;
                        l = mid + 1;
                    }
                    else
                        r = mid - 1;
                }
                d[pos + 1] = nums[i];
            }
        }
        return len;
    }
};
// @lc code=end
