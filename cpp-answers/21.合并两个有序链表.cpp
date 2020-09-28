/*
 * @Author: your name
 * @Date: 2020-05-28 22:37:27
 * @LastEditTime: 2020-09-24 06:50:13
 * @LastEditors: Hongyang_Yang
 * @Description: In User Settings Edit
 * @FilePath: \leetcode刷题\21.合并两个有序链表.cpp
 */
/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    /*     ListNode *mergeTwoLists(ListNode *a, ListNode *b)
    {
        if (!a || b && (a->val > b->val))
            swap(a, b);
        if (a)
            a->next = mergeTwoLists(a->next, b);
        return a;
    } */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0);
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        ListNode *cur = dummy;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return dummy->next;
    }
};
// @lc code=end
