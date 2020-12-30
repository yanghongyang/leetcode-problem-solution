/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-12-30 11:46:54
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-12-30 12:12:12
 */
/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
//代码抄自algsCG的某个评论：https://leetcode-cn.com/problems/longest-consecutive-sequence/solution/tao-lu-jie-jue-zui-chang-zi-xu-lie-deng-yi-lei-wen/
class Solution
{
public:
    //方法一：朴素的dp，先排好了序，排序时间需要O(nlogn)，所以总体时间复杂度为O(nlogn)
    /*     int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() < 2)
            return nums.size();
        sort(nums.begin(), nums.end());
        //删除重复元素
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int res = 1;
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] + 1 == nums[i])
            {
                dp[i] = dp[i - 1] + 1;
            }
            res = max(res, dp[i]);
        }
        return res;
    } */
    //方法2：使用基于红黑树的set进行去重，set的插入和查找时间复杂度为O(logn)，空间复杂度为O(1)
    //set中的元素都是排好序的，并且在set集合中没有重复的元素（默认情况下从小到大排）
    /*     int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() < 2)
            return nums.size();
        set<int> s(nums.begin(), nums.end());
        int res = 1;
        for (int num : s)
        {
            //在这里进行剪枝，如果num-1存在，那么num一定被计算过了
            if (s.count(num - 1) != 0)
                continue;
            int len = 1;
            while (s.count(num + 1) != 0)
            {
                len++;
                num++;
            }
            res = max(res, len);
        }
        return res;
    } */
    //方法3：利用hashset进行去重，hashset的插入和查找时间复杂度为O(1)，遍历的时间杂度为O(n)，空间复杂度为O(1)
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() < 2)
            return nums.size();
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 1;
        for (int num : s)
        {
            //在这里进行剪枝，如果num-1存在，那么num一定被计算过了
            if (s.count(num - 1) != 0)
                continue;
            int len = 1;
            while (s.count(num + 1) != 0)
            {
                len++;
                num++;
            }
            res = max(res, len);
        }
        return res;
    }
};
// @lc code=end
