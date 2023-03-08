/*
 * @lc app=leetcode.cn id=228 lang=rust
 *
 * [228] 汇总区间
 */

// @lc code=start
impl Solution {
    pub fn summary_ranges(nums: Vec<i32>) -> Vec<String> {
        let mut answer = Vec::new();
        let mut i = 0;
        while i < nums.len() {
            let n = nums[i];
            while i < nums.len() - 1 && nums[i + 1] == nums[i] + 1 {
                i += 1;
            }
            let mut s = n.to_string();
            if n != nums[i] {
                s += "->";
                s += &nums[i].to_string();
            }
            answer.push(s);
            i += 1;
        }
        answer
    }
}
// @lc code=end

