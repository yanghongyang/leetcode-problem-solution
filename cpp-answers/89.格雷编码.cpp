/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-10-15 08:07:01
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-10-15 08:14:55
 */
/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

// @lc code=start
class Solution
{
public:
    void utils(bitset<32> &bits, vector<int> &result, int k)
    {
        if (k == 0)
        {
            result.push_back(bits.to_ulong());
        }
        else
        {
            utils(bits, result, k - 1);
            bits.flip(k - 1);
            utils(bits, result, k - 1);
        }
    }
    vector<int> grayCode(int n)
    {
        bitset<32> bits;
        vector<int> result;
        utils(bits, result, n);
        return result;
    }
};
// @lc code=end
