/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;  //0对应的指针
        int j = 0;  //1对应的指针
        int k = nums.size() - 1;    //2对应的指针
        while(j <= k)
        {
            if(nums[j] == 0)
            {
                swap(nums[i++], nums[j++]); //1对应的应该是1，而不是0，因此和0对换
            }
            else if(nums[j] == 1)
            {
                j++;
            }
            else if(nums[j] == 2)
            {
                swap(nums[k--], nums[j]);   //1对应的不能是2，因此和2指针对应的数字对换，这样的话2指向的一定是2，但此时1不一定是1，因此j不变，k--
            }
        }
    }
};
// @lc code=end

