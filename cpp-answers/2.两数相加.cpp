/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL)
            return NULL;
        else if(l1 == NULL)
            return l2;
        else if(l2 == NULL)
            return l1;

        int a = l1 -> val + l2 -> val;
        ListNode *p = new ListNode(a % 10);
        p -> next = addTwoNumbers(l1 -> next, l2 -> next);
        if(a >= 10)
            p -> next = addTwoNumbers(p -> next, new ListNode(1));
        return p;
    }
};
// @lc code=end

