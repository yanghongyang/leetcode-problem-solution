/*
 * @lc app=leetcode.cn id=119 lang=rust
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
impl Solution {
    pub fn get_row(row_index: i32) -> Vec<i32> {
        let row_index = row_index as usize;
        let mut res = vec![];
        res.push(1);

        for i in 1..row_index + 1 {
            let tmp = res[i - 1] as usize * (row_index + 1 - i) / i;
            res.push(tmp as i32);
        }

        res
    }
}
// @lc code=end

