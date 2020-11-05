/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-05 09:05:23
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-05 09:10:56
 */
/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        ListNode *dummy = new ListNode(0), *pre = dummy, *cur;
        dummy->next = head;
        for (int i = 0; i < m - 1; i++)
        {
            pre = pre->next;
        }
        cur = pre->next;
        for (int i = 0; i < n - m; i++)
        {
            ListNode *tmp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = tmp;
        }
        return dummy->next;
    }
};
// @lc code=end
