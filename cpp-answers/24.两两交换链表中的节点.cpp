/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-17 09:26:28
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-17 09:50:51
 */
/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    /*
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pos = dummy;
        while ((head) && (head->next))
        {
            ListNode *first = head;
            ListNode *second = head->next;
            pos->next = second;
            first->next = second->next;
            second->next = first;
            pos = first;
            head = first->next;
        }
        return dummy->next;
    }*/
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *first = head;
        ListNode *second = head->next;
        first->next = swapPairs(second->next); //first的下一个指向的是second下一个已经交换好的节点
        second->next = first;                  //接着交换first和second就行了
        return second;                         //交换完之后，second是头节点了
    }
};
// @lc code=end
