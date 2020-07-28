/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-18 16:45:47
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-18 16:59:46
 */ 
/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 */

// @lc code=start
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        /*
        //利用set中元素的有序性和唯一性，将元素放入set中，若set的size不小于3，输出倒数第三个元素；若set的size小于3，输出最后一个元素
        set<int> s(nums.begin(), nums.end());
        auto it = s.end();
        it --;
        if(s.size() >= 3)
        {
            it --;
            it --;
        }
        return *it;
        */
        long big, mid, small;   //最大，第二大，第三大
        big = mid = small = 1l << 63;
        for(int i : nums)
        {
            if(i > big)
            {
                small = mid;
                mid = big;
                big = i;
            }
            else if(i > mid && i != big)
            {
                small = mid;
                mid = i;
            }
            else if(i > small && i != mid && i != big)
            {
                small = i;
            }
        }
        return (small == 1l << 63) ? (int) big : (int) small;
    }
};
// @lc code=end

