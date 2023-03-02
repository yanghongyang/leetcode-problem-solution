/*
 * @lc app=leetcode.cn id=191 lang=rust
 *
 * [191] 位1的个数
 */

// @lc code=start
impl Solution {
    pub fn hammingWeight (mut n: u32) -> i32 {
        // n.count_ones() as i32
        let mut ret = 0;
        while n != 0 {
            n = n & (n - 1);
            ret += 1;
        }
        ret
    }
}
// @lc code=end

