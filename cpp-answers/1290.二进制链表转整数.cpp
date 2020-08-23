/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-23 15:53:45
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-23 15:54:29
 */
/*
 * @lc app=leetcode.cn id=1290 lang=cpp
 *
 * [1290] 二进制链表转整数
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    int getDecimalValue(ListNode *head)
    {
        int ans = 0;
        ListNode *tmp = head;
        while (tmp)
        {
            ans = ans * 2 + tmp->val;
            tmp = tmp->next;
        }
        return ans;
    }
};
// @lc code=end
