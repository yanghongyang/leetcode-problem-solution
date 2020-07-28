/*
 * @Author: your name
 * @Date: 2020-05-28 22:37:27
 * @LastEditTime: 2020-05-28 22:39:31
 * @LastEditors: Please set LastEditors
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
    ListNode *mergeTwoLists(ListNode *a, ListNode *b)
    {
        if (!a || b && (a->val > b->val))
            swap(a, b);
        if (a)
            a->next = mergeTwoLists(a->next, b);
        return a;
    }
};
// @lc code=end
