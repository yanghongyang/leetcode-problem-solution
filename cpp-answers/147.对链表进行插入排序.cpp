/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* pre = dummy;
        ListNode* cur = head;
        while(cur)
        {
            if((cur -> next) && (cur -> next -> val < cur -> val))
            {
                while((pre -> next) && (pre -> next -> val < cur -> next -> val))
                {
                    pre = pre -> next;
                }
                ListNode* tmp = pre -> next;
                pre -> next = cur -> next;
                cur -> next = cur -> next -> next;
                pre -> next -> next = tmp;
                pre = dummy;
            }
            else 
            {
                cur = cur -> next;
            }
        }
        return dummy -> next;
    }
};
// @lc code=end

