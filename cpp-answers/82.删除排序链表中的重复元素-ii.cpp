/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-17 10:47:07
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-17 10:55:55
 */
/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
        if (!head || !head->next)
            return head;
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        int flag = true;
        while (head)
        {
            while (head && head->next && head->val == head->next->val)
            {
                flag = false;
                head = head->next;
            }
            if (flag == true)
            {
                cur->next = head;
                cur = head;
            }
            head = head->next;
            flag = true;
        }
        cur->next = NULL;
        return dummy->next;
    }
};
// @lc code=end
