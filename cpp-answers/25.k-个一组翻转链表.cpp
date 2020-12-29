/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-12-29 16:03:02
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-12-29 16:58:07
 */
/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    int length(ListNode *head)
    {
        int len = 0;
        while (head)
        {
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        int len = length(head);
        int times = len / k;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy;
        for (int i = 0; i < times; i++)
        {
            for (int j = 0; j < k - 1; j++)
            {
                ListNode *tmp = pre->next;     //存储断链的节点
                pre->next = head->next;        //pre的下一个节点指向原head的下一个节点
                head->next = head->next->next; //原head的下一个节点指向其下下个节点，这样pre和head断链了
                pre->next->next = tmp;         //利用tmp给连上
            }
            pre = head;
            head = head->next;
        }
        return dummy->next;
    }
};
// @lc code=end
