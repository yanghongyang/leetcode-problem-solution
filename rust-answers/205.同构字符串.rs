/*
 * @lc app=leetcode.cn id=205 lang=rust
 *
 * [205] 同构字符串
 */

// @lc code=start
impl Solution {
    pub fn is_isomorphic(s: String, t: String) -> bool {
        let mut map1 = [0; 256];
        let mut id1 = 1;

        let mut map2 = [0; 256];
        let mut id2 = 1;

        let mut it1 = s.chars()
                    .map(|c| c as usize)
                    .map(|c| {
                        if map1[c] == 0 {
                            map1[c] = id1; 
                            id1 += 1;
                        }
                        map1[c]
                    });

        let mut it2 = t.chars()
                    .map(|c| c as usize)
                    .map(|c| { if map2[c] == 0 {
                            map2[c] = id2;
                            id2 += 1;
                        }
                        map2[c]
                    });
        
        it1.zip(it2).all(|(a, b)| a == b)
    }
}
// @lc code=end

