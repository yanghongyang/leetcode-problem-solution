/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-10-20 08:03:58
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-10-20 08:10:46
 */
/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    /*     void reorderList(ListNode *head)
    {
        if (!head || !head->next || !head->next->next)
            return;
        ListNode *penultimate = head;
        while (penultimate->next->next)
            penultimate = penultimate->next;
        penultimate->next->next = head->next;
        head->next = penultimate->next;
        penultimate->next = NULL;
        reorderList(head->next->next);
    } */
    void reorderList(ListNode *head)
    {
        ListNode *penultimate;
        while (head && head->next && head->next->next)
        {
            penultimate = head;
            while (penultimate->next->next)
                penultimate = penultimate->next;
            penultimate->next->next = head->next;
            head->next = penultimate->next;
            penultimate->next = NULL;
            head = head->next->next;
        }
    }
};
// @lc code=end
