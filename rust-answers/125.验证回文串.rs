/*
 * @lc app=leetcode.cn id=125 lang=rust
 *
 * [125] 验证回文串
 */

// @lc code=start
impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        let mut iter = s.chars().filter(|c| c.is_alphanumeric())
        .map(|c| c.to_ascii_lowercase());

        iter.clone().eq(iter.rev())
    }
}
// @lc code=end

