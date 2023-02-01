/*
 * @lc app=leetcode.cn id=104 lang=rust
 *
 * [104] 二叉树的最大深度
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
    pub fn max_depth(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut max_depth = 0;
        let mut stack = vec![(root, 0)];

        while let Some((node, mut depth)) = stack.pop() {
            if let Some(node) = node {
                let node = node.borrow();
                depth += 1;
                max_depth = max_depth.max(depth);

                stack.push((node.left.clone(), depth));
                stack.push((node.right.clone(), depth));
            }
        }
        max_depth
    }
}
// @lc code=end

