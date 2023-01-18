/*
 * @lc app=leetcode.cn id=20 lang=rust
 *
 * [20] 有效的括号
 */

// @lc code=start
impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut stack = Vec::new();
        for i in s.chars() {
            match i {
                '{' => stack.push('}'),
                '(' => stack.push(')'),
                '[' => stack.push(']'),
                '}' | ']' | ')' => {
                    if Some(i) != stack.pop() {
                        return false;
                    } 
                },
                _ => (),
            }
        }
        return stack.is_empty();
    }
}
// @lc code=end

