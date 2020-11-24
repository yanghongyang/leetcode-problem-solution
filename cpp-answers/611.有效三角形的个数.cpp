/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-24 21:15:00
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-24 22:16:58
 */
/*
 * @lc app=leetcode.cn id=611 lang=cpp
 *
 * [611] 有效三角形的个数
 */

// @lc code=start
class Solution
{
public:
    /* 
    最简单（无耻）的方法莫过于暴力法了，结果只打败了5%哈哈哈哈
    int triangleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (nums[i] + nums[j] <= nums[k])
                        break;
                    cnt++;
                }
            }
        }
        return cnt;
    } */
    //想道查找的话，很自然想到二分查找了，固定三角形中最短的两边，在剩下右边的元素里找到第一个大于两边之和的元素位置，返回之后加入ans即可
    /*     int triangleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                int sum = nums[i] + nums[j];
                int l = j + 1, r = n - 1;
                while (l <= r)
                {
                    int mid = l + (r - l) / 2;
                    if (nums[mid] < sum)
                    {
                        l = mid + 1;
                    }
                    else
                        r = mid - 1;
                }
                if (nums[r] < sum)
                    cnt += (r - j);
            }
        }
        return cnt;
    } */
    //这题更简单的还可以使用双指针（辣鸡！这简单到爆炸的思路为啥我没想到！）
    int triangleNumber(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
            return 0;
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for (int i = 0; i < n - 2; i++)
        {
            if (nums[i] == 0)
                continue;
            int p1 = i + 1, p2 = i + 2; //双指针
            while (p1 < n)
            {
                while (p2 < nums.size() && nums[i] + nums[p1] > nums[p2])
                {
                    p2++;
                }
                cnt += p2 - p1 - 1;
                p1++;
            }
        }
        return cnt;
    }
};
// @lc code=end
