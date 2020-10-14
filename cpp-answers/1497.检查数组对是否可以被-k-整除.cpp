/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-10-14 08:10:54
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-10-14 08:25:49
 */
/*
 * @lc app=leetcode.cn id=1497 lang=cpp
 *
 * [1497] 检查数组对是否可以被 k 整除
 */

// @lc code=start
class Solution
{
public:
    bool canArrange(vector<int> &arr, int k)
    {
        vector<int> cnt(k);
        //统计余数出现的次数
        for (int num : arr)
        {
            cnt[(num % k + k) % k]++;
        }
        for (int i = 1; i + i < k; i++)
        {
            if (cnt[i] != cnt[k - i])
                return false;
        }
        return cnt[0] % 2 == 0;
    }
};
// @lc code=end
