/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-25 23:55:55
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-26 00:02:41
 */
/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &num)
    {
        vector<vector<int>> res;
        std::sort(num.begin(), num.end());
        for (int i = 0; i < num.size(); i++)
        {
            int target = -num[i];
            int front = i + 1;
            int back = num.size() - 1;
            while (front < back)
            {
                int sum = num[front] + num[back];
                if (sum < target)
                    front++;
                else if (sum > target)
                    back--;
                else
                {
                    vector<int> triplet(3, 0);
                    triplet[0] = num[i];
                    triplet[1] = num[front];
                    triplet[2] = num[back];
                    res.push_back(triplet);

                    //去重，如果排序的数组有重复的元素
                    while (front < back && num[front] == triplet[1])
                        front++;
                    while (front < back && num[back] == triplet[2])
                        back--;
                }
            }
            //去重，target不能重复
            while (i + 1 < num.size() && num[i + 1] == num[i])
                i++;
        }
        return res;
    }
};
// @lc code=end
