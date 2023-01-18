/*
 * @lc app=leetcode.cn id=14 lang=rust
 *
 * [14] 最长公共前缀
 */

// @lc code=start
impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        // Grab from: https://leetcode.cn/problems/longest-common-prefix/solutions/1177899/rust-zui-chang-gong-gong-qian-zhui-ti-ji-dwuj/
        // Tql
        strs.iter()
            .max()
            .unwrap()
            .chars()
            .zip(strs.iter().min().unwrap().chars())
            .take_while(|x| x.0 == x.1)
            .map(|x| x.0)
            .collect()
    }
}
// @lc code=end

