/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-16 23:30:58
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-16 23:53:03
 */
/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lc code=start
class Solution
{
public:
    //注意，排过序了
    /*     char nextGreatestLetter(vector<char> &letters, char target)
    {
        auto pos = upper_bound(letters.begin(), letters.end(), target);
        if (pos != letters.end())
            return *pos;
        return *letters.begin();
    } */
    /* 对下标做二分，找到第一个大于target值的下标
target可能比letters中所有字符都小，也可能比letters中所有字符都大,因此第一个大于target值的下标的取值范围为[0, letters.size()]，因此left = 0, right = letters.size();
当left == right时退出， 因此循环条件为while(left < right>)
当letters[mid] > target时， mid是可能结果，大于mid的都可以舍弃，所有right = mid
当letters[mid] <= target时， mid不在候选集中，因此left = mid+1, 舍弃小于等于mid的下标
当循环退出时，left = right = 待选下标， 注意当targets大于letters中所有元素时， left = letters.size()，此时要返回letters[0];
 */
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int left = 0, right = letters.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (letters[mid] > target)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        if (left == letters.size())
            return letters[0];
        return letters[left];
    }
};
// @lc code=end
