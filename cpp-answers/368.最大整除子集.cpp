/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-12-29 10:40:02
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-12-29 12:05:36
 */
/*
 * @lc app=leetcode.cn id=368 lang=cpp
 *
 * [368] 最大整除子集
 */

// @lc code=start
class Solution
{
public:
    /*     vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1); //dp数组用来记录nums[i]的最长整除子集的长度，初始情况下nums[i]的整除子集肯定有一个，即为其本身，所以初始化长度为1
        int maxLen = 0;                 //maxLen用来记录最大整除子集的长度
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0) //如果nums[i]能够被nums[j]整除
                {
                    dp[i] = max(dp[i], dp[j] + 1); //则说明第i个数的最大整除子集长度为其原先的dp[i]和dp[j]+1（+1是因为算上了dp[i]本身）之间的最大值
                }
            }
            maxLen = max(maxLen, dp[i]);
        }

        //确定了maxLen之后，就从后向前寻找可能的最大整除子集
        //寻找思路为：从后向前遍历，并使用prev记录当前num之前一个数，如果prev%nums[i] == 0，也就说明满足整除条件，而如果此时的dp[i]恰好等于maxLen这个长度，则说明是ans中的元素
        //prev的初始值为-1
        vector<int> ans;
        int prev = -1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (maxLen == dp[i] && (prev == -1 || prev % nums[i] == 0))
            {
                ans.emplace_back(nums[i]);
                maxLen--;
                prev = nums[i];
            }
        }

        return ans;
    } */

    //也可以用并查集来做，抄自：https://leetcode-cn.com/problems/largest-divisible-subset/solution/cbing-cha-ji-qing-xi-tu-jie-by-monologue-s/
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 0)
            return {};
        sort(nums.begin(), nums.end());
        vector<int> father(n), level(n);
        for (int i = 0; i < nums.size(); i++)
        {
            father[i] = i; //初始化
        }
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[i] % nums[j] == 0 && level[i] < level[j] + 1)
                {
                    father[i] = j;
                    level[i] = level[j] + 1;
                }
            }
        }
        //取得最深元素的下标
        int x = max_element(level.begin(), level.end()) - level.begin();
        vector<int> ans;
        while (x != father[x])
        {
            ans.push_back(nums[x]);
            x = father[x];
        }
        ans.push_back(nums[x]);
        return ans;
    }
};
// @lc code=end
