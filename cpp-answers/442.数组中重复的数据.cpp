/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-23 23:51:15
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-24 00:11:58
 */
/*
 * @lc app=leetcode.cn id=442 lang=cpp
 *
 * [442] 数组中重复的数据
 */

// @lc code=start
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> duplicates;
        for (int i = 0; i < nums.size(); i++)
        {
            int index = abs(nums[i]) - 1; //找到当前元素值-1的位置，这里用abs防止下溢。。。（辣鸡，test的时候没注意，结果RE了）
            //然后把index这个位置上的数字取负
            nums[index] = -nums[index];
            //接下来立刻判断，是否当前元素-1位置上的数为负数（如果重新再来一个for循环的话，会因为nums中有很多重复2次的元素，导致部分位置上原本没有的元素出现，从而出错）
            if (nums[index] > 0)
            {
                duplicates.push_back(index + 1);
            }
        }
        return duplicates;
    }
};
// @lc code=end
