/*
 * @lc app=leetcode.cn id=66 lang=rust
 *
 * [66] 加一
 */

// @lc code=start
impl Solution {
    pub fn plus_one(mut digits: Vec<i32>) -> Vec<i32> {
        for x in digits.iter_mut().rev() {
            match *x == 9 {
                true => *x = 0,
                false => {
                    *x += 1;
                    return digits;
                }
            }
        }
        digits.insert(0, 1);
        digits
    }
}
// @lc code=end

