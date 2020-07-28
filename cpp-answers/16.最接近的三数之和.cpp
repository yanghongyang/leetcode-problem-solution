/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-26 00:07:49
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-26 00:13:21
 */
/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution
{
public:
    int threeSumClosest(vector<int> &num, int target)
    {
        sort(num.begin(), num.end());

        unsigned int n = num.size();
        unsigned int distance(INT_MAX);
        int result;

        for (int i = 0; i < n - 2; i++)
        {
            if (i > 0 && num[i - 1] == num[i])
                continue;
            int a = num[i];
            int low = i + 1;
            int high = n - 1;

            while (low < high)
            {
                int b = num[low];
                int c = num[high];
                int sum = a + b + c;
                if (sum - target == 0)
                    return target;
                else
                {
                    if (abs(sum - target) < distance)
                    {
                        distance = abs(sum - target);
                        result = sum;
                    }
                    if (sum - target > 0)
                    {
                        while (high > 1 && num[high] == num[high - 1])
                            high--;
                        high--;
                    }
                    else
                    {
                        while (low < n - 1 && num[low] == num[low + 1])
                            low++;
                        low++;
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end
