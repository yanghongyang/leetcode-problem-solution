/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-10-10 22:38:39
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-10-10 22:44:26
 */
/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        int flag = false;
        while (fast != nullptr)
        {
            slow = slow->next;
            if (fast->next == nullptr)
                return nullptr;
            fast = fast->next->next;
            if (fast == slow)
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            ListNode *res = head;
            while (res != slow)
            {
                res = res->next;
                slow = slow->next;
            }
            return res;
        }
        return nullptr;
    }
};
// @lc code=end
