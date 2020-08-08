# [题目描述](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/)

给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

```
示例：
给定一个链表: 1->2->3->4->5, 和 n = 2.
当删除了倒数第二个节点后，链表变为 1->2->3->5.
```

**说明：**

给定的 n 保证是有效的。

**进阶：**

你能尝试使用一趟扫描实现吗？

# 考点（解题方向）

- 双指针
- 模拟

# 代码（模拟）

讲道理这道题，第一眼就是暴力模拟法了。

只需要求出链表的长度`length`，则倒数第`n`个节点就是正数第`length+1-n`个节点。

在实现的时候需要注意，由于存在链表长度为 1 的情况，在这种情况下如果删除节点，则会执行出错。

因此需要先设置一个临时节点`dummy`在头节点前。

代码如下：

```
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
        return dummy->next;
    }
};
```

# 代码（双指针）

虽然第一思路是模拟，但是想了想，在计算正数第几个节点和倒数第几个节点的时候实在是太容易出错了，好麻烦......

于是想出了第二种方法，就先实现了。这就是**快慢指针法**。

**快慢指针法**被广泛应用于链表相关的题目中，尤其是在删除节点类的题。所以必须掌握哦！！！（卖卖萌）

和暴力模拟相同，为了防止节点长度为 1 的情况下出现执行错误，需要设置`dummy`节点。

代码如下：

```
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
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
    }
};
```
