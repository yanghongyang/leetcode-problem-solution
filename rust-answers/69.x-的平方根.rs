/*
 * @lc app=leetcode.cn id=69 lang=rust
 *
 * [69] x 的平方根 
 */

// @lc code=start
// Integer_max: 2147483647, and sqrt(Integer_max) ~= 46340
use std::cmp::Ordering;
impl Solution {
    // pub fn my_sqrt(x: i32) -> i32 {
    //     if x == 0 {
    //         return 0;
    //     }

    //     let mut lower = 2;
    //     let mut higher = 46340.min(x >> 1);

    //     if x <= 3 {
    //         return 1;
    //     }

    //     if x >= higher * higher {
    //         return higher;
    //     }

    //     while higher - lower > 1 {
    //         let mid = (higher + lower) >> 1;
    //         let pow = mid * mid;
    //         match pow.cmp(&x) {
    //             Ordering::Less => {
    //                 lower = mid;
    //             }
    //             Ordering::Greater => {
    //                 higher = mid;
    //             }
    //             _ => {
    //                 return mid;
    //             }
    //         }
    //     }

    //     lower
    // }
    pub fn my_sqrt(x: i32) -> i32 {
        let mut left = 0 as i64;
        let mut right = x as i64;
        let xx: i64 = x as i64;
    
        while left < right {
            let mid = (left + right + 1) >> 1 as i64;
    
            let mut target: i64 = mid as i64 * mid as i64;
            match target.cmp(&xx) {
                Ordering::Less => {
                    left = mid;
                }
                Ordering::Greater => {
                    right = mid - 1;
                }
                _ => {
                    return mid as i32;
                }
            }
        }
        return left as i32;
    }
}
// @lc code=end

