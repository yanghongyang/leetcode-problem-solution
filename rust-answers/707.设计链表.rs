/*
 * @lc app=leetcode.cn id=707 lang=rust
 *
 * [707] 设计链表
 */

// @lc code=start
struct MyLinkedList {
    head: Option<Box<ListNode>>,
    len: i32,
}

struct ListNode {
    val: i32,
    next: Option<Box<ListNode>>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyLinkedList {

    fn new() -> Self {
        Self {
            head: Some(Box::new(ListNode { val: 0, next: None })),
            len: 0,
        }
    }
    
    fn get(&mut self, index: i32) -> i32 {
        if let Some(ref cur) = self.get_node_at_index(index) {
            cur.val
        } else {
            -1
        }
    }
    
    fn add_at_head(&mut self, val: i32) {
        self.add_at_index(0, val);
    }
    
    fn add_at_tail(&mut self, val: i32) {
        self.add_at_index(self.len, val);
    }
    
    fn add_at_index(&mut self, index: i32, val: i32) {
        let cur = self.get_node_at_index(index - 1);
        if let Some(ref mut cur) = cur {
            let new_node = Some(Box::new(ListNode {
                val, 
                next: cur.next.take(),
            }));
            cur.next = new_node;
            self.len += 1;
        }
    }
    
    fn get_node_at_index(&mut self, index: i32) -> &mut Option<Box<ListNode>> {
        let mut cur = &mut self.head;
        for _ in 0..=index {
            if cur.is_none() {
                return cur;
            }
            cur = &mut cur.as_mut().unwrap().next;
        }
        cur
    }
    fn delete_at_index(&mut self, index: i32) {
        let cur = self.get_node_at_index(index - 1);
        if let Some(node) = cur {
            let to_delete = node.next.take();
            if let Some(mut to_delete) = to_delete {
                node.next = to_delete.next.take();
                self.len -= 1;
            }
        }
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * let obj = MyLinkedList::new();
 * let ret_1: i32 = obj.get(index);
 * obj.add_at_head(val);
 * obj.add_at_tail(val);
 * obj.add_at_index(index, val);
 * obj.delete_at_index(index);
 */
// @lc code=end

