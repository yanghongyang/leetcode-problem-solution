/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution {
public:
    static bool cmp(string& a, string& b)
    {
        return a + b > b + a;
    }
    string largestNumber(vector<int>& nums) {
        int size = nums.size();
        string s;
        sort(nums.begin(), nums.end(), cmp);
        for(int i = 0; i < size; i++)
        {
            s += to_string(nums[i]);
        }
        if(s[0] == '0')
            return "0";
        return s;
    }
};
// @lc code=end

