/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-14 21:33:08
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-14 21:55:05
 */
/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 求众数 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        //由于题目要求得票数>=x/3（下限），所以最多有两个候选者得票超过1/3（下限）
        int n = nums.size();
        vector<int> res;
        if (n == 0)
            return res;
        int a = 0, b = 0, cnt1 = 0, cnt2 = 0; //两个候选数为a, b
        for (int num : nums)
        {
            if (num == a) //如果当前投的是a，则a的得票数++
                cnt1++;
            else if (num == b) //如果当前投的是b，则b的得票数++
                cnt2++;
            else if (cnt1 == 0) //如果a的得票数被battle成了0，则当前的num会替换a，成为第一个候选者
            {
                a = num;
                cnt1++;
            }
            else if (cnt2 == 0) //否则，如果b的得票数被battle成了0，当前的数会替换b，成为第二个候选者
            {
                b = num;
                cnt2++;
            }
            else //出现了第三个数，并且此时a和b的总次数都不为0，则第三个数会battle a和b 这两个数，因此cnt1和cnt2被battle掉了1个
            {
                cnt1--;
                cnt2--;
            }
        }
        //经过上一轮循环之后，确定了整个数组中得票最多的两个候选者
        cnt1 = 0;
        cnt2 = 0;
        for (int num : nums)
        {
            if (num == a)
                cnt1++;
            else if (num == b)
                cnt2++;
        }
        if (cnt1 > n / 3)
            res.push_back(a);
        if (cnt2 > n / 3)
            res.push_back(b);
        return res;
    }
};
// @lc code=end
