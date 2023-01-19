/*
 * @lc app=leetcode.cn id=26 lang=rust
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        match nums.is_empty() {
            true => 0,
            false => {
                let mut prev = 0;
                for i in 1..nums.len() {
                    if nums[prev] != nums[i] {
                        prev += 1;
                        nums[prev] = nums[i];
                    }
                }
                (prev + 1) as i32
            }
        }
    }
}
// @lc code=end

