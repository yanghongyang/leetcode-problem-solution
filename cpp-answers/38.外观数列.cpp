/*
 * @Author: your name
 * @Date: 2020-05-30 00:22:39
 * @LastEditTime: 2020-05-30 00:30:40
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode刷题\38.外观数列.cpp
 */
/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution
{
public:
    string countAndSay(int n)
    {
        string curr_str;
        //一开始的时候初始化为1
        curr_str += '1';

        //当n=2时，进行迭代
        for (int i = 0; i < n - 1; i++)
        {
            string buffer;

            //处理当前的字符串
            int index = 0;
            for (index = 0; index < curr_str.size(); index++)
            {
                //记录下每个数字出现的次数
                int cnt = 1;
                while (index + 1 < curr_str.size() && curr_str[index + 1] == curr_str[index])
                {
                    index++;
                    cnt++;
                }

                buffer.push_back(cnt + '0');
                buffer.push_back(curr_str[index]);
            }

            curr_str = buffer;
        }
        return curr_str;
    }
};
// @lc code=end
