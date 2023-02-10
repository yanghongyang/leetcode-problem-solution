/*
 * @lc app=leetcode.cn id=121 lang=rust
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        prices.iter().fold((0, i32::MAX), |(mut max_profit, mut cost), price| {
            cost = i32::min(*price, cost);
            max_profit = i32::max(max_profit, price - cost);
            (max_profit, cost)
        }).0
    }
}
// @lc code=end

