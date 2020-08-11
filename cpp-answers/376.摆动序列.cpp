/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int ans = 1;
        if(nums.size() < 2)
            return nums.size();
        //首先把数据一开始可能存在的重复数据去掉
        int i = 1;
        while(i < nums.size() && nums[i] == nums[i - 1])
            i++;
        if(i >= nums.size())
            return ans;
        bool flag = nums[i] > nums[i - 1];  //首先判断nums[1]和nums[0]的大小以确定方向
        while(i < nums.size())
        {
            if(flag)    //如果是上升趋势
            {
                while(i + 1 < nums.size() && nums[i + 1] >= nums[i])
                {
                    i++;
                }
            }
            else 
            {
                while(i + 1 < nums.size() && nums[i + 1] <= nums[i])
                {
                    i++;
                }
            }
            ans++;
            flag = !flag;
            i++;
        }
        return ans;
    }
};
// @lc code=end

