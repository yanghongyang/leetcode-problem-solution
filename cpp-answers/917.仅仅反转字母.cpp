/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-05 17:30:14
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-05 17:32:01
 */
/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */

// @lc code=start
class Solution
{
public:
    string reverseOnlyLetters(string S)
    {
        int left = 0, right = S.size();
        while (left <= right)
        {
            if (!isalpha(S[left]))
            {
                left++;
                continue;
            }
            if (!isalpha(S[right]))
            {
                right--;
                continue;
            }
            swap(S[left++], S[right--]);
        }
        return S;
    }
};
// @lc code=end
