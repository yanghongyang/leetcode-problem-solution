/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-09-14 21:12:08
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-09-14 21:26:14
 */
/*
 * @lc app=leetcode.cn id=901 lang=cpp
 *
 * [901] 股票价格跨度
 */

// @lc code=start
class StockSpanner
{
public:
    stack<pair<int, int>> st; //[price, days]
    StockSpanner()
    {
    }

    int next(int price)
    {
        int days = 1;
        while (st.size() && price >= st.top().first)
        {
            days += st.top().second;
            st.pop();
        }
        st.push({price, days});
        return days;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end
