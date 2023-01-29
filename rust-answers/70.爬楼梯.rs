/*
 * @lc app=leetcode.cn id=70 lang=rust
 *
 * [70] 爬楼梯
 */

// @lc code=start
impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        (0..n)
            .fold((1, 0), |(res, prev), _| (res + prev, res))
            .0
    }
}
// @lc code=end

