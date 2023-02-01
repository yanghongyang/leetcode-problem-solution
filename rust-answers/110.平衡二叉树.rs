/*
 * @lc app=leetcode.cn id=110 lang=rust
 *
 * [110] 平衡二叉树
 */

// @lc code=start
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn is_balanced(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        fn dfs(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
            match root {
                Some(root) => {
                    let left = dfs(root.borrow().left.clone());
                    let right = dfs(root.borrow().right.clone());
                    if (left - right).abs() > 1 || left == -1 || right == -1 {
                        return -1;
                    }
                    left.max(right) + 1
                },
                None => 0
            }
        }
        dfs(root) != -1
    }
}
// @lc code=end

