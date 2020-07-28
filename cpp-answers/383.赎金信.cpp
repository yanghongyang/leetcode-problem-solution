/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-18 17:01:20
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-18 17:07:05
 */ 
/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> umap;
        for(auto c : ransomNote)
        {
            if(umap.find(c) == umap.end())
                umap.insert({c, 1});
            else 
                umap[c]++;
        }
        for(auto c : magazine)
        {
            if(umap.find(c) == umap.end())
                continue;
            else 
            {
                umap[c] -- ;
                if(umap[c] == 0)
                    umap.erase(c);
            }
        }
        return umap.empty();
    }
};
// @lc code=end

