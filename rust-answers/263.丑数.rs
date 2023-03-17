/*
 * @lc app=leetcode.cn id=263 lang=rust
 *
 * [263] 丑数
 */

// @lc code=start
impl Solution {
    pub fn is_ugly(n: i32) -> bool {
        match n {
            _ if n <= 0 => false,
            mut num => {
                for p in [2, 3, 5] {
                    while num % p == 0 {
                        num /= p;
                    }
                }
                num == 1
            }
        }
    }
}
// @lc code=end

