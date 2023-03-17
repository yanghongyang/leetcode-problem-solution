/*
 * @lc app=leetcode.cn id=258 lang=rust
 *
 * [258] 各位相加
 */

// @lc code=start
impl Solution {
    pub fn add_digits(mut num: i32) -> i32 {
        match num {
            0 => return 0,
            _ => {
                num = num % 9;
                if num == 0 {
                    return 9
                } else {
                    return num
                }
            }
        }

    }
}
// @lc code=end

