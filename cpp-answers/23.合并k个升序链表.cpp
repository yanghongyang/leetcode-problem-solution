/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-10-15 08:31:14
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-10-15 08:58:25
 */
/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    //方法1：暴力模拟

    /*    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        if (l1->val <= l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
        return l1;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return nullptr;
        while (lists.size() > 1)
        {
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    } */
    //法2：优先队列（小根堆

    /*     struct cmp
    {
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, cmp> pri_queue;
        //建立以k为大小的小根堆
        for (auto elem : lists)
        {
            if (elem)
                pri_queue.push(elem);
        }
        //可以使用哑节点/哨兵节点
        ListNode dummy(-1);
        ListNode *p = &dummy;
        //开始出队
        while (!pri_queue.empty())
        {
            ListNode *top = pri_queue.top();
            pri_queue.pop();
            p->next = top;
            p = p->next;
            if (top->next)
            {
                pri_queue.push(top->next);
            }
        }
        return dummy.next;
    } */
    //法3：归并
    ListNode *merge(ListNode *p1, ListNode *p2)
    {
        if (!p1)
            return p2;
        if (!p2)
            return p1;
        if (p1->val <= p2->val)
        {
            p1->next = merge(p1->next, p2);
            return p1;
        }
        else
        {
            p2->next = merge(p1, p2->next);
            return p2;
        }
        return p1;
    }
    ListNode *merge(vector<ListNode *> &lists, int start, int end)
    {
        if (start == end)
            return lists[start];
        int mid = (start + end) / 2;
        ListNode *l1 = merge(lists, start, mid);
        ListNode *l2 = merge(lists, mid + 1, end);
        return merge(l1, l2);
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return nullptr;
        return merge(lists, 0, lists.size() - 1);
    }
};
// @lc code=end
