/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution {
public:
    //模拟
    //建表，枚举个、十、百、千可能出现的字母组合，根据给定数字各个位的值从表中直接取字母
    /* string intToRoman(int num) {
        string table[4][10] = {{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}, 
                                {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}, 
                                {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}, 
                                {"", "M", "MM", "MMM"}
                                };
        string result;
        int cnt = 0;  //统计数位
        while(num > 0)
        {
            int tmp = num % 10;
            result = table[cnt][tmp] + result;
            num /= 10;
            cnt++;
        }
        return result;
    } */
    //贪心
    string intToRoman(int num)
    {
        vector<int> nums = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> str = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string res;
        int index = 0;
        while(index < 13)
        {
            while(num >= nums[index])
            {
                res += str[index];
                num -= nums[index];
            }
            index++;
        }
        return res;
    }
};
// @lc code=end

