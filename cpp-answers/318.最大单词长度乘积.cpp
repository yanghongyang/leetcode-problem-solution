/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-23 17:53:35
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-23 18:13:29
 */
/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */

// @lc code=start
class Solution
{
public:
    //需要注意的是，vector的size()方法返回的是unsigned long类型，因此使用max()方法比较大小的时候需要转换成相同的类型（比如说int）
    //朴素算法，位运算
    //O(n^2)
    /*     int maxProduct(vector<string> &words)
    {
        vector<int> mask(words.size());
        int res = 0;
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            for (char c : words[i])
            {
                mask[i] = mask[i] | (1 << (c - 'a')); //统计words[i]中出现的字母
            }
            for (int j = 0; j < i; j++) //循环比较，更新此时的最大值
            {
                if (!(mask[i] & mask[j])) //如果mask[i]和mask[j]中没有相同的字母
                {
                    res = max(res, (int)(words[i].size() * words[j].size()));
                }
            }
        }
        return res;
    } */
    //部分优化，O(n+N)，N是所有字母中字符的总数，n是words的长度
    //这种方法需要找到由相同字母构成中长度最大的那个字符串
    int maxProduct(vector<string> &words)
    {
        unordered_map<int, int> mp;
        for (string word : words)
        {
            int mask = 0;
            for (char c : word)
            {
                mask |= 1 << (c - 'a');
            }
            mp[mask] = max(mp[mask], (int)word.size());
        }
        int res = 0;
        for (auto a : mp)
        {
            for (auto b : mp)
            {
                if (!(a.first & b.first))
                {
                    res = max(res, a.second * b.second);
                }
            }
        }
        return res;
    }
};
// @lc code=end
