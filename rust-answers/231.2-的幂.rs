/*
 * @lc app=leetcode.cn id=231 lang=rust
 *
 * [231] 2 的幂
 */

// @lc code=start
impl Solution {
    pub fn is_power_of_two(n: i32) -> bool {
        // n > 0 && n.count_ones() == 1
        n > 0 && (n & (n - 1)) == 0
    }
}
// @lc code=end

