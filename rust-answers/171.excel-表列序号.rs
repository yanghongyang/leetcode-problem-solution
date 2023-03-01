/*
 * @lc app=leetcode.cn id=171 lang=rust
 *
 * [171] Excel 表列序号
 */

// @lc code=start
impl Solution {
    pub fn title_to_number(column_title: String) -> i32 {
        column_title.chars().map(|c| c as i32 - 'A' as i32 + 1)
        .fold(0, |prev, next| prev * 26 + next)
    }
}
// @lc code=end

