/*
 * @Description:
 * @Author: Hongyang_Yang
 * @Date: 2020-08-06 23:30:08
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-06 23:32:51
 */
 /*
  * @lc app=leetcode.cn id=6 lang=cpp
  *
  * [6] Z 字形变换
 */

//   @lc                 code=start                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        code=startzzzzzz
class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string ret;
        for (string row : rows) ret += row;
        return ret;
    }
};
// @lc code=end

