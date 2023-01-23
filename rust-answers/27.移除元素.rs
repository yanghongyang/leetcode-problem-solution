/*
 * @lc app=leetcode.cn id=27 lang=rust
 *
 * [27] 移除元素
 */

// @lc code=start
impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        nums.retain(|&x| x != val);
        return nums.len() as i32;
    }
}
// @lc code=end

