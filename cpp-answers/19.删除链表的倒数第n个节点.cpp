/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    //快慢指针一遍扫描
    /* ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)   
            return nullptr;
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;   //之所以有dummy，是为了对应链表节点数为1等的极端情况
        ListNode *fast = dummy;
        ListNode *slow = dummy;

        for(int i = 0; i < n; i++)
            fast = fast -> next;
        while(fast -> next)
        {
            fast = fast -> next;
            slow = slow -> next;
        }
        ListNode *tmp = slow -> next;   //要删除的节点
        
        slow -> next = tmp -> next;

        delete tmp;
        return dummy -> next;
    } */
    //暴力模拟（当然叫得好听一点就是两次遍历了）
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if(head == NULL)
            return nullptr;
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        int length = 0;
        ListNode* first = dummy;
        while(first != NULL)
        {
            first = first -> next;
            length++;
        }
        length -= n;
        length -= 1;
        first = dummy;  //重新开始遍历一遍
        while(length > 0)   //这样遍历可以到达倒数第n+1个节点
        {
            length--;
            first = first -> next;
        }
        first -> next = first -> next -> next;
        return dummy -> next;
    }

};
// @lc code=end

