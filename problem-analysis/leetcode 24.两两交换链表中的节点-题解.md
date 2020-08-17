<!--
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-17 09:52:22
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-17 10:10:02
-->
# [题目描述](https://leetcode-cn.com/problems/swap-nodes-in-pairs)
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

 
```
示例:
给定 1->2->3->4, 你应该返回 2->1->4->3.
```
```
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/swap-nodes-in-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

# 考点
- 链表

# 解题方向
- 迭代
- 递归

# 题目分析（迭代）
迭代法解决链表问题，归根到底是 **模拟** 的思想。

对于本题来讲，可以以 **示例** 为例，进行模拟。

很容易可以发现交换部分的代码如下：

```first -> next = second -> next; second -> next = first;```

迭代法的一个关键点，也是易错点在于：对于 **极端情况** 的处理。具体而言，极端情况为只有两个节点/三个节点。（空链表或1个节点的链表暂时不考虑，因为可以通过一开始判断出来）。

为此需要添加一个 ```dummy``` 节点，其 ```next``` 指针指向 ```head``` ，在返回时返回 ```dummy -> next``` 即可。

# 代码（迭代）
```cpp
ListNode *swapPairs(ListNode *head)
{
    if (!head || !head->next)
        return head;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *pos = dummy;
    while ((head) && (head->next))
    {
        ListNode *first = head;
        ListNode *second = head->next;
        pos->next = second;
        first->next = second->next;
        second->next = first;
        pos = first;
        head = first->next;
    }
    return dummy->next;
}
```

# 题目分析（递归）
递归法也可以用来解决链表问题，但大部分情况下递归解法都十分抽象。

可以想象一下已经实现了 ```swapPairs``` 方法，即对链表的两个相邻节点进行交换。

那么 ```first``` 的 ```next``` 指针指向的便是 ```swapPairs(second -> next)``` ，这是因为假定经过处理后只剩下 ```first``` 和 ```second``` 两个节点未处理，```second -> next``` 及其之后的节点已经交换处理过了。

那么接下来 ```second -> next``` 就指向的是 ```first```。

最后返回 ```second``` 节点，也就是处理后的头节点，即可。

# 代码（递归）
```cpp
ListNode *swapPairs(ListNode *head)
{
    if (!head || !head->next)
        return head;
    ListNode *first = head;
    ListNode *second = head->next;
    first->next = swapPairs(second->next); //first的下一个指向的是second下一个已经交换好的节点
    second->next = first;                  //接着交换first和second就行了
    return second;                         //交换完之后，second是头节点了
}
```