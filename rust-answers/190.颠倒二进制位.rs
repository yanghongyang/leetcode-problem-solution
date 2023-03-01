/*
 * @lc app=leetcode.cn id=190 lang=rust
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
impl Solution {
    pub fn reverse_bits(x: u32) -> u32 {
        let (mut res, mut x) = (0u32, x);
        for _ in 0..32 {
            res = (res << 1) | (x & 1);
            x >>= 1;
        }
        res
    }
}
// @lc code=end

