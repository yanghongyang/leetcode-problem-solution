/*
 * @lc app=leetcode.cn id=232 lang=rust
 *
 * [232] 用栈实现队列
 */

// @lc code=start
#[derive(Default)]
struct MyQueue {
    stack_back: Vec<i32>,
    stack_front: Vec<i32>,
}


/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyQueue {

    fn new() -> Self {
        Default::default()
    }
    
    fn push(&mut self, x: i32) {
        self.stack_back.push(x);
    }
    
    fn pop(&mut self) -> i32 {
        self.move_back_to_front();
        self.stack_front.pop().unwrap()
    }
    
    fn peek(&mut self) -> i32 {
        self.move_back_to_front();
        *self.stack_front.last().unwrap()
    }
    
    fn empty(&self) -> bool {
        self.stack_front.is_empty() && self.stack_back.is_empty()
    }

    fn move_back_to_front(&mut self) {
        if self.stack_front.is_empty() {
            while let Some(x) = self.stack_back.pop() {
                self.stack_front.push(x)
            }
        }
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * let obj = MyQueue::new();
 * obj.push(x);
 * let ret_2: i32 = obj.pop();
 * let ret_3: i32 = obj.peek();
 * let ret_4: bool = obj.empty();
 */
// @lc code=end

