/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-11 20:15:08
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-11 20:32:35
 */
/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */

// @lc code=start
class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        vector<int> ret, clone = nums;
        int len = (int)nums.size();
        unordered_map<int, int> reflect;
        array.resize(len + 1);
        sort(clone.begin(), clone.end());
        for (int i = 0; i < len; i++)
            reflect[clone[i]] = i + 1;

        for (int i = len - 1; i >= 0; i--)
        {
            clone[i] = query(reflect[nums[i]] - 1);
            add(reflect[nums[i]], 1);
        }
        return clone;
    }

private:
    vector<int> array;
    inline int lowbit(int pos)
    {
        return pos & -pos;
    }

    void add(int pos, int val)
    {
        long len = array.size();
        while (pos < len)
        {
            array[pos] += val;
            pos += lowbit(pos);
        }
    }

    int query(int pos)
    {
        int ret = 0;
        while (pos > 0)
        {
            ret += array[pos];
            pos -= lowbit(pos);
        }
        return ret;
    }
};
// @lc code=end
