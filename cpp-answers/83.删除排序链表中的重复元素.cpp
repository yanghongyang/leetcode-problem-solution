/*
 * @Author: your name
 * @Date: 2020-05-30 23:59:54
 * @LastEditTime: 2020-05-31 00:04:57
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \-Insgram-e:\leetcode刷题\83.删除排序链表中的重复元素.cpp
 */
/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        auto cur = head;
        while (cur && cur->next)
        {
            if (cur->next->val == cur->val)
            {
                cur->next = cur->next->next;
            }
            else
                cur = cur->next;
        }
        return head;
    }
};
// @lc code=end
