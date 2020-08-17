<!--
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-17 10:29:46
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-17 10:40:15
-->
# [题目描述](https://leetcode-cn.com/problems/rotate-list)
给定一个链表，旋转链表，将链表每个节点向右移动 `k` 个位置，其中 `k` 是非负数。
```
示例 1:
输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
```
```
示例 2:
输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL
```
```
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

# 考点
- 链表
- 模拟

# 解题方向
- 模拟

# 题目分析
仔细观察示例，可发现整个过程分为四个部分。
- 到达第`(length - k)`个节点
- 将第`(length - k)`个节点和其下一个节点断链
- 将原第`(length - k)`个节点的`next`指向空
- 将末尾的节点指向头节点

那么，首先需要求出整个链表的长度`length`。

求出链表长度后，再来分析`k`。这里分析的原因在于，如果`k`非常大，甚至超过了`length`，那么模拟的话肯定会出现重复的情况，因此需要将`k`取余`length`，即`k = k % length`。

之后需要将此时遍历的节点`tmp`的`next`指针指向头节点。这样做的原因在于，方便原链表末尾节点在旋转之后指向头节点。这样处理之后，如果此时`k=0`，也可以在过程的第三部分重新将尾节点的下一个指针指向`NULL`。

# 代码
```cpp
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL || k == 0)
            return head;
        int length = 1;
        ListNode *tmp = head;
        while (tmp->next)
        {
            length++;
            tmp = tmp->next;
        }
        k = k % length;
        tmp->next = head;
        while (--length >= k)
        {
            tmp = tmp->next;
        }
        ListNode *first = tmp->next;
        tmp->next = NULL;
        return first;
    }
};
```

# 另附：求链表长度（代码）
```cpp
class Solution
{
public:
    int size(ListNode *head)
    {
        if (head == NULL)
            return 0;
        int length = 1;
        ListNode *tmp = head;
        while (tmp->next)
        {
            length++;
            tmp = tmp->next;
        }
        return length;
    }
};
```