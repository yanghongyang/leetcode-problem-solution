/*
 * @lc app=leetcode.cn id=1769 lang=rust
 *
 * [1769] 移动所有球到每个盒子所需的最小操作数
 */

// @lc code=start
impl Solution {
    pub fn min_operations(boxes: String) -> Vec<i32> {
        let boxes = boxes.as_bytes();
        let mut left = if boxes[0] == b'1' { 1 } else { 0 };
        let mut right = 0;
        let mut res: Vec<i32> = vec![0; boxes.len()];

        for i in 1..boxes.len() {
            if boxes[i] == b'1' {
                res[0] += i as i32;
                right += 1;
            }
        }

        for i in 1..boxes.len() {
            res[i] = res[i - 1] + left - right;
            if boxes[i] == b'1' {
                left += 1;
                right -= 1;
            }
        }
        res
    }
}
// @lc code=end

