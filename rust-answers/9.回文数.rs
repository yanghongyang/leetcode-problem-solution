/*
 * @lc app=leetcode.cn id=9 lang=rust
 *
 * [9] 回文数
 */

// @lc code=start
impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        return x.to_string().chars().rev().eq(x.to_string().chars())
    }
}
// @lc code=end

