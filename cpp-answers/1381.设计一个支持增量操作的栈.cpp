/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-25 17:51:44
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-25 17:54:32
 */
/*
 * @lc app=leetcode.cn id=1381 lang=cpp
 *
 * [1381] 设计一个支持增量操作的栈
 */

// @lc code=start
class CustomStack
{
public:
    vector<int> v;
    int size = 0;
    CustomStack(int maxSize)
    {
        size = maxSize;
    }

    void push(int x)
    {
        if (v.size() < size)
        {
            v.push_back(x);
        }
    }

    int pop()
    {
        int tmp;
        if (v.size() == 0)
            return -1;
        else
        {
            tmp = v[v.size() - 1];
            v.pop_back();
        }
        return tmp;
    }

    void increment(int k, int val)
    {
        for (int i = 0; i < v.size() && k-- > 0; i++)
        {
            v[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
// @lc code=end
