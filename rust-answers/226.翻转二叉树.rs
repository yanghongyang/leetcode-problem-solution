/*
 * @lc app=leetcode.cn id=226 lang=rust
 *
 * [226] 翻转二叉树
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
use std::mem;
use std::collections::VecDeque;

type TreeLink = Option<Rc<RefCell<TreeNode>>>;

impl Solution {
    pub fn invert_tree(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        let mut queue: VecDeque<TreeLink> = VecDeque::new();
        queue.push_front(root.clone());
        while let Some(ele) = queue.pop_back() {
            if let Some(n) = ele {
                let mut borrowed_node = n.borrow_mut();
                let borrowed_node = &mut *borrowed_node;
                mem::swap(&mut borrowed_node.right, &mut borrowed_node.left);
                queue.push_back(borrowed_node.left.clone());
                queue.push_back(borrowed_node.right.clone());
            }
        }
        root
    }
}
// @lc code=end

