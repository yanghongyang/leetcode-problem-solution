/*
 * @lc app=leetcode.cn id=118 lang=rust
 *
 * [118] 杨辉三角
 */

// @lc code=start
impl Solution {
    pub fn generate(num_rows: i32) -> Vec<Vec<i32>> {
        let mut vec = vec![vec![1]];

        for n in 1..num_rows {
            let mut sub_vec = vec![1];
            let mut prev_row = (n - 1) as usize;
            let mut prev_row_len = vec[prev_row].len();

            for i in 0..prev_row_len {
                if i == 0 {
                    sub_vec.push(vec[prev_row][i]);
                } else {
                    sub_vec.push(vec[prev_row][i]);
                    sub_vec[i] += vec[prev_row][i];
                }
            }
            vec.push(sub_vec);
        }
        vec
    }
}
// @lc code=end

