/*
 * @lc app=leetcode.cn id=257 lang=rust
 *
 * [257] 二叉树的所有路径
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
type OptNode = Option<Rc<RefCell<TreeNode>>>;

impl Solution {
    pub fn binary_tree_paths(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<String> {
        let mut ans = Vec::new();
        Self::dfs(&root, &mut Vec::new(), &mut ans);
        ans
    }

    fn dfs(node: &OptNode, curr: &mut Vec<String>, ans: &mut Vec<String>) {
        if let Some(n) = node.as_ref() {
            let b = n.borrow();
            curr.push(b.val.to_string());
            if b.left.is_none() && b.right.is_none() {
                ans.push(curr.join("->"));
            } else {
                Self::dfs(&b.left, curr, ans);
                Self::dfs(&b.right, curr, ans);
            }
            curr.pop();
        }
    }
}
// @lc code=end

