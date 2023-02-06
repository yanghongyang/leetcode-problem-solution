/*
 * @lc app=leetcode.cn id=111 lang=rust
 *
 * [111] 二叉树的最小深度
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
    pub fn min_depth(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        match root {
            Some(node) => {
                let left = Self::min_depth(node.borrow().left.clone());
                let right = Self::min_depth(node.borrow().right.clone());

                if left == 0 || right == 0 {
                    return left.max(right) + 1
                }

                left.min(right) + 1
            },
            None => 0,
        }
    }
}
// @lc code=end

