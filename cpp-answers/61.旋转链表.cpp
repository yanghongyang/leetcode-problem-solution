/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-17 10:11:51
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-17 10:20:22
 */
/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL || k == 0)
            return head;
        int length = 1;
        ListNode *tmp = head;
        while (tmp->next)
        {
            length++;
            tmp = tmp->next;
        }
        k = k % length;
        tmp->next = head;
        while (--length >= k)
        {
            tmp = tmp->next;
        }
        ListNode *first = tmp->next;
        tmp->next = NULL;
        return first;
    }
};
// @lc code=end
