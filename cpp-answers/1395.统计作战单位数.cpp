/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-10-29 19:34:37
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-10-29 19:43:17
 */
/*
 * @lc app=leetcode.cn id=1395 lang=cpp
 *
 * [1395] 统计作战单位数
 */

// @lc code=start
class Solution
{
public:
    int count(vector<int> &rating) //辅助函数
    {
        int sum = 0;
        int n = rating.size();
        vector<int> greater(n); //greater[i]存储比rating[i]大，且在i右边的个数
        vector<int> smaller(n); //smaller[i]存储比rating[i]小，且在i左边的个数
        for (int i = 0; i < n; i++)
        {
            int target = rating[i];
            int c = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (rating[j] > target)
                {
                    c++;
                }
            }
            greater[i] = c;
            c = 0;
            for (int j = 0; j < i; j++)
            {
                if (rating[j] < target)
                {
                    c++;
                }
            }
            smaller[i] = c;
            sum += greater[i] * smaller[i];
        }
        return sum;
    }
    int numTeams(vector<int> &rating)
    {
        int n = rating.size();
        int k = count(rating); //先统计从小到大
        reverse(rating.begin(), rating.end());
        k += count(rating); //再统计从大到小
        return k;
    }
};
// @lc code=end
