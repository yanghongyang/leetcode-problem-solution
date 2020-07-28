/*
 * @Author: your name
 * @Date: 2020-06-09 09:10:11
 * @LastEditTime: 2020-06-13 18:58:46
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \undefinede:\leetcode刷题\234.回文链表.cpp
 */
/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode *head)
    {
        ListNode *slowp = head;
        ListNode *fastp = head;
        ListNode *revp = NULL;
        while (fastp && fastp->next)
        {
            fastp = fastp->next->next;
            ListNode *tmp = slowp->next;
            slowp->next = revp;
            revp = slowp;
            slowp = tmp;
        }
        if (fastp)
            slowp = slowp->next;
        while (slowp && revp)
        {
            if (slowp->val != revp->val)
                return false;
            slowp = slowp->next;
            revp = revp->next;
        }
        return true;
    }
};
// @lc code=end
