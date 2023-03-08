/*
 * @lc app=leetcode.cn id=225 lang=rust
 *
 * [225] 用队列实现栈
 */

// @lc code=start
use std::collections::VecDeque;

struct MyStack {
    q1: VecDeque<i32>,
    q2: VecDeque<i32>,
    top: i32,
}


/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyStack {

    fn new() -> Self {
        let q1: VecDeque<i32> = VecDeque::new();
        let q2: VecDeque<i32> = VecDeque::new();
        let top = 0i32;
        MyStack{q1, q2, top}
    }
    
    fn push(&mut self, x: i32) {
        self.q1.push_back(x);
        self.top = x;
    }
    
    fn pop(&mut self) -> i32 {
        let result = self.top;
        for i in 0..self.q1.len() - 1 {
            match self.q1.pop_front() {
                None => break,
                Some(v) => {
                    self.top = v;
                    self.q2.push_back(v);
                }
            }
        }
        self.q1.pop_front();

        for i in 0..self.q2.len() {
            let v = self.q2.pop_front().unwrap();
            self.q1.push_back(v);
        }
        result
    }
    
    fn top(&self) -> i32 {
        self.top
    }
    
    fn empty(&self) -> bool {
        self.q1.len() == 0
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * let obj = MyStack::new();
 * obj.push(x);
 * let ret_2: i32 = obj.pop();
 * let ret_3: i32 = obj.top();
 * let ret_4: bool = obj.empty();
 */
// @lc code=end

