/*
 * @Author: your name
 * @Date: 2020-06-13 22:31:26
 * @LastEditTime: 2020-06-13 22:35:42
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \undefinede:\leetcode刷题\605.种花问题.cpp
 */
/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

// @lc code=start
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        //首先为了避免首位和尾位的特殊情况，可在首位和尾位都填上一个0，这样就可以一视同仁了，只需寻找到有多少个 0 的左右两边都是0即可，该个数即为可插花朵的最大值
        int count = 0;
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.insert(flowerbed.end(), 0);
        for (int i = 1; i < flowerbed.size() - 1; i++)
        {
            if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
            {
                flowerbed[i] = 1;
                count++;
            }
        }
        return n <= count;
    }
};
// @lc code=end
