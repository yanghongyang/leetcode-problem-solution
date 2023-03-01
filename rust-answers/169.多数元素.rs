/*
 * @lc app=leetcode.cn id=169 lang=rust
 *
 * [169] 多数元素
 */

// @lc code=start
use std::collections::HashMap;

impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        let mut res = 0;
        let mut count = 1;

        for i in 1..nums.len() {
            if nums[res] == nums[i] {
                count += 1;
            } else {
                count -= 1;
            }
            if count == 0 {
                res = i;
                count = 1;
            }
        }

        count = 0;

        for i in 0..nums.len() {
            if nums[i] == nums[res] {
                count += 1;
            }
        }

        if count > (nums.len() / 2) {
            return nums[res];
        }
        return -1;
    }
}
// @lc code=end

