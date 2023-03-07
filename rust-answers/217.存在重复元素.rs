/*
 * @lc app=leetcode.cn id=217 lang=rust
 *
 * [217] 存在重复元素
 */

// @lc code=start
use std::collections::HashSet;

impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        let mut exists = HashSet::new();
        !nums.into_iter().all(|n| exists.insert(n))
    }
}
// @lc code=end

