/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-12-29 12:08:34
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-12-29 12:24:21
 */
/*
 * @lc app=leetcode.cn id=382 lang=cpp
 *
 * [382] 链表随机节点
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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode *head)
    {
        curHead = head;
    }

    /** Returns a random node's value. */
    int getRandom()
    {
        ListNode *cur = curHead;
        int cnt = 1;
        int val = 0;
        while (cur)
        {
            if (rand() % cnt == 0)
            {
                val = cur->val;
            }
            cur = cur->next;
            cnt++;
        }
        return val;
    }

private:
    ListNode *curHead;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// @lc code=end
