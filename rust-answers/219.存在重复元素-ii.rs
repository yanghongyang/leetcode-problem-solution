/*
 * @lc app=leetcode.cn id=219 lang=rust
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
use std::collections::HashMap;

impl Solution {
    pub fn contains_nearby_duplicate(nums: Vec<i32>, k: i32) -> bool {
        let mut seen = HashMap::with_capacity(nums.len());

        for (i, n) in nums.into_iter().enumerate() {
            let j = seen.entry(n).or_insert(i);
            if *j != i && i - *j <= k as usize {
                return true;
            } else {
                *j = i;
            }
        }
        return false;
    }
}
// @lc code=end

