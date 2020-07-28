/*
 * @Author: your name
 * @Date: 2020-06-05 21:38:15
 * @LastEditTime: 2020-06-05 21:45:26
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \-Insgram-e:\leetcode刷题\160.相交链表.cpp
 */
/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *h1 = headA;
        ListNode *h2 = headB;
        while (h1 != h2)
        {
            if (!h1)
                h1 = headB;
            else
                h1 = h1->next;
            if (!h2)
                h2 = headA;
            else
                h2 = h2->next;
        }
        return h1;
    }
};
// @lc code=end
