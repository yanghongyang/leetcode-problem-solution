/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-25 09:47:13
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-28 11:29:41
 */
/*
 * @lc app=leetcode.cn id=970 lang=cpp
 *
 * [970] 强整数
 */

// @lc code=start
class Solution
{
public:
    vector<int> powerfulIntegers(int x, int y, int bound)
    {
        vector<int> ans;
        unordered_set<int> hashtable;
        for (int i = 0;; i++)
        {
            int newx = (int)pow(x, i);
            if (newx >= bound)
                break;
            for (int j = 0;; j++)
            {
                int newy = (int)pow(y, j);
                if (newx + newy > bound)
                    break;
                else
                    hashtable.insert(newx + newy);
                if (y == 1)
                    break;
            }
            if (x == 1)
                break;
        }
        return vector<int>(hashtable.begin(), hashtable.end());

        return ans;
    }
};
// @lc code=end
