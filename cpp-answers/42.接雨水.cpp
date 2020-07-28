/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-27 20:35:45
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-27 20:56:15
 */
/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution
{
public:
    //方法1：暴力
    /*
        对于数组钟的每个元素，找出下雨后水能到达的最高位置，等于两边最大高度的较小值减去当前高度的值
        初始化ans = 0
        从左向右扫描数组：
            初始化max_left = 0和max_right = 0
            从当前元素向左扫描并更新：
                max_left = max(max_left, height[j])
            从当前元素向右扫描并更新：
                max_right = max(max_right, height[j])
        将min(max_left, max_right)-height[i]累加到ans
   */
    //这种方法会tle
    /*
    int trap(vector<int> &height)
    {
        int ans = 0;
        int size = height.size();
        for (int i = 1; i < size - 1; i++)
        {
            int max_left = 0, max_right = 0;
            for (int j = i; j >= 0; j--)
            {
                max_left = max(max_left, height[j]);
            }
            for (int j = i; j < size; j++)
            {
                max_right = max(max_right, height[j]);
            }
            ans += min(max_left, max_right) - height[i];
        }
        return ans;
    }*/
    //动态编程
    /*
        找到数组中从下标i到最左端最高的条形块高度left_max
        找到数组中从下表i到最右端最高的条形块高度right_max
        扫描数组height并更新答案：
            累加min(max_left[i], max_right[i]) - height[i]到ans上
    */
    int trap(vector<int> &height)
    {
        if (height.size() == 0)
            return 0;
        int ans = 0;
        int size = height.size();
        vector<int> left_max(size), right_max(size);
        left_max[0] = height[0];
        for (int i = 1; i < size; i++)
        {
            left_max[i] = max(height[i], left_max[i - 1]);
        }
        right_max[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--)
        {
            right_max[i] = max(height[i], right_max[i + 1]);
        }
        for (int i = 1; i < size - 1; i++)
        {
            ans += min(left_max[i], right_max[i]) - height[i];
        }
        return ans;
    }
};
// @lc code=end
