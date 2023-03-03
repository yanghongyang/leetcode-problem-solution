/*
 * @lc app=leetcode.cn id=203 lang=rust
 *
 * [203] 移除链表元素
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
    // pub fn remove_elements(mut head: Option<Box<ListNode>>, val: i32) -> Option<Box<ListNode>> {
    //     let mut dummy = None;
    //     let mut tail = &mut dummy;

    //     while let Some(mut node) = head.take() {
    //         head = node.next.take();

    //         if node.val != val {
    //             *tail = Some(node);
    //             tail = &mut tail.as_mut().unwrap().next;
    //         }
    //     }

    //     dummy
    // }

    pub fn remove_elements(mut head: Option<Box<ListNode>>, val: i32) -> Option<Box<ListNode>> {
        let mut head = head;
        let mut ptr = &mut head;

        loop {
            match ptr {
                None => break,
                Some(node) if node.val == val => *ptr = node.next.take(),
                Some(node) => ptr = &mut node.next,
            }
        }
        
        head
    }
}
// @lc code=end

