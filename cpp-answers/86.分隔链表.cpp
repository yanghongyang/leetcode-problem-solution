/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-05 08:39:11
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-05 08:47:59
 */
/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *dummy1 = new ListNode(0), *dummy2 = new ListNode(0);
        ListNode *node1, *node2;
        node1 = dummy1;
        node2 = dummy2;
        while (head)
        {
            if (head->val < x)
            {
                node1->next = head;
                node1 = node1->next;
            }
            else
            {
                node2->next = head;
                node2 = node2->next;
            }
            head = head->next;
        }
        node2->next = NULL;
        node1->next = dummy2->next;
        return dummy1->next;
    }
};
// @lc code=end
