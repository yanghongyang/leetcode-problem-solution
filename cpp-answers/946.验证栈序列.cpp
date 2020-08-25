/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-25 11:49:42
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-25 11:51:15
 */
/*
 * @lc app=leetcode.cn id=946 lang=cpp
 *
 * [946] 验证栈序列
 */

// @lc code=start
class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> s;
        int j = 0; //用来标记栈混洗数组中的元素
        for (int i = 0; i < pushed.size(); i++)
        {
            s.push(pushed[i]);
            while (!s.empty() && s.top() == popped[j])
            {
                s.pop();
                j++;
            }
        }
        return s.empty();
    }
};
// @lc code=end
