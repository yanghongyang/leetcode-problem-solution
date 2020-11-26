/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-26 19:53:35
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-26 20:53:40
 */
/*
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距
 */

// @lc code=start
class Solution
{
public:
    //emmmm......暴力大法好.jpg

    /*    
    int maximumGap(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return 0;
        sort(nums.begin(), nums.end());
        int ans = INT_MIN;
        for (int i = n - 1; i >= 1; i--)
        {
            ans = max(ans, abs(nums[i] - nums[i - 1]));
        }
        return ans;
    } 
    */
    //基数排序，可以达到O(N)，也就是题目的要求
    /*     int maximumGap(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return 0;
        int exp = 1;
        vector<int> buf(n);
        int maxVal = *max_element(nums.begin(), nums.end());

        while (maxVal >= exp)
        {
            vector<int> cnt(10);
            for (int i = 0; i < n; i++)
            {
                int digit = (nums[i] / exp) % 10;
                cnt[digit]++;
            }
            for (int i = 1; i < 10; i++)
            {
                cnt[i] += cnt[i - 1];
            }
            for (int i = n - 1; i >= 0; i--)
            {
                int digit = (nums[i] / exp) % 10;
                buf[cnt[digit] - 1] = nums[i];
                cnt[digit]--;
            }
            copy(buf.begin(), buf.end(), nums.begin());
            exp *= 10;
        }
        int ret = 0;
        for (int i = 1; i < n; i++)
        {
            ret = max(ret, nums[i] - nums[i - 1]);
        }
        return ret;
    } */
    //当然还可以用桶排序，也是O(N)
    int maximumGap(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return 0;
        auto lu = minmax_element(nums.begin(), nums.end());
        int l = *lu.first, u = *lu.second;
        int gap = max((u - l) / (n - 1), 1);
        int m = (u - l) / gap + 1;
        vector<int> bucketsMin(m, INT_MAX);
        vector<int> bucketsMax(m, INT_MIN);
        for (int num : nums)
        {
            int k = (num - l) / gap;
            if (num < bucketsMin[k])
                bucketsMin[k] = num;
            if (num > bucketsMax[k])
                bucketsMax[k] = num;
        }
        int i = 0, j;
        gap = bucketsMax[0] - bucketsMin[0];
        while (i < m)
        {
            j = i + 1;
            while (j < m && bucketsMin[j] == INT_MAX && bucketsMax[j] == INT_MIN)
                j++;
            if (j == m)
                break;
            gap = max(gap, bucketsMin[j] - bucketsMax[i]);
            i = j;
        }
        return gap;
    }
};
// @lc code=end
