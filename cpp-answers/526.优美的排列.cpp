/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-17 19:45:31
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-17 19:50:26
 */
/*
 * @lc app=leetcode.cn id=526 lang=cpp
 *
 * [526] 优美的排列
 */

// @lc code=start
class Solution
{
public:
    vector<int> arr;
    int count = 0;

    int countArrangement(int N)
    {
        for (int i = 0; i < N; i++)
            arr.push_back(i + 1);
        countnumber(0);
        return count;
    }
    void countnumber(int pos)
    {
        if (pos >= arr.size())
        {
            count++;
            return;
        }
        for (int i = pos; i < arr.size(); i++)
        {
            if (arr[i] % (pos + 1) && (pos + 1) % arr[i])
                continue;
            swap(arr[pos], arr[i]);
            countnumber(pos + 1);
            swap(arr[pos], arr[i]);
        }
    }
};
// @lc code=end
