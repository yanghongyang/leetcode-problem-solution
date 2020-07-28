/*
 * @Author: your name
 * @Date: 2020-05-28 23:11:22
 * @LastEditTime: 2020-05-28 23:20:34
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode刷题\394.字符串解码.cpp
 */
/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution
{
public:
    string decodeString(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ']')
            {
                st.push(s[i]);
            }
            else
            {
                string curr_str = "";

                while (st.top() != '[')
                {
                    curr_str = st.top() + curr_str;
                    st.pop();
                }
                st.pop(); //for '['
                string number = "";

                //for calculating number

                while (!st.empty() && isdigit(st.top()))
                {
                    number = st.top() + number;
                    st.pop();
                }
                int k_time = stoi(number); //convert string to number

                while (k_time--)
                {
                    for (int p = 0; p < curr_str.size(); p++)
                    {
                        st.push(curr_str[p]);
                    }
                }
            }
        }

        s = "";
        while (!st.empty())
        {
            s = st.top() + s;
            st.pop();
        }
        return s;
    }
};
// @lc code=end
