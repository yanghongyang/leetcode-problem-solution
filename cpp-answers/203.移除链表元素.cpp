/*
 * @Author: your name
 * @Date: 2020-06-06 22:56:16
 * @LastEditTime: 2020-06-06 22:57:44
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode刷题\203.移除链表元素.cpp
 */
/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == NULL)
            return head;
        ListNode *p = head;
        while (p->next != NULL)
        {
            if (p->next->val == val)
            {
                p->next = p->next->next;
            }
            else
            {
                p = p->next;
            }
        }
        if (head->val == val)
            head = head->next;
        return head;
    }
};
// @lc code=end
