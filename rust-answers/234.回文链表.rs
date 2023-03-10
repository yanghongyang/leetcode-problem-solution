/*
 * @lc app=leetcode.cn id=234 lang=rust
 *
 * [234] 回文链表
 */

// @lc code=start
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    // pub fn is_palindrome(mut head: Option<Box<ListNode>>) -> bool {
    //     let mut res = vec![];
    //     while let Some(node) = head {
    //         res.push(node.val);
    //         head = node.next;
    //     }
    //     let mut tmp = res.clone();
    //     tmp.reverse();
    //     tmp == res
    // }

    // Copy from: https://leetcode.cn/problems/palindrome-linked-list/solutions/1410029/rust-by-flamboyant-hofstadter-ucjq/
    // I find this solution meaningful
    pub fn is_palindrome(head: Option<Box<ListNode>>) -> bool {
        if head.is_none() || head.as_ref().unwrap().next.is_none() {
            return true;
        }

        let (mut fast, mut slow) = (&head, &head);
        while fast.is_some() {
            fast = fast.as_ref().unwrap().next.as_ref().map(|x| &x.next).unwrap_or(&None);
            slow = slow.as_ref().map(|x| &x.next).unwrap();
        }

        let s = slow as *const Option<Box<ListNode>> as * mut Option<Box<ListNode>>;
        let slow = unsafe{ (*s).take() };

        let new_head = revert_link(None, slow);

        is_palindrome_helper(head, new_head)
    }

}

pub fn revert_link(pre: Option<Box<ListNode>>, mut curr: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
    if curr.is_none() {
        return pre;
    }

    use std::borrow::BorrowMut;
    // std::mem::replace(dest: &mut T, src: T) -> T : Moves src into the referenced dest, returning the previous dest value
    let next = std::mem::replace(curr.as_mut().unwrap().next.borrow_mut(), pre);
    revert_link(curr, next)
}

pub fn is_palindrome_helper(old_head: Option<Box<ListNode>>, new_head: Option<Box<ListNode>>) -> bool {
    match (old_head, new_head) {
        (None, None) | (None, Some(_)) | (Some(_), None) => true,
        (Some(h1), Some(h2)) => {
            if h1.val == h2.val {
                is_palindrome_helper(h1.next, h2.next)
            } else {
                false
            }
        }
    }
}
// @lc code=end

