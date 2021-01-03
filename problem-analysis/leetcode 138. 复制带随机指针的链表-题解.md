<!--
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2021-01-03 18:54:25
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2021-01-03 19:30:00
-->
#### 前言
这篇题解写的很好，画图十分清晰：[两种实现+图解 138. 复制带随机指针的链表](https://leetcode-cn.com/problems/copy-list-with-random-pointer/solution/liang-chong-shi-xian-tu-jie-138-fu-zhi-dai-sui-ji-/)

#### 考点
1. 链表的基本操作（复制、删除等）
2. 哈希表

#### 分析1 
如果只是让复制链表，那这题应该是 `easy` 难度。然而本题要求复制带随机指针的链表，因此问题转化为， **如何复制链表节点的随机指针**。

随机，难在 **不知道节点 `node` 的 `random` 指针到底会指向哪里** 。这个 `random` 指针可能存在，也可能不存在， **可能指向已经存在的节点，也可能指向的节点我们还没有来得及复制** 。

由上分析，只需要先按照没有 `random` 指针的情况，把所有的节点都给复制出来，再重新遍历一遍原链表，按照原链表的 `random` 指针情况，在新复制的链表中表示出来就行啦。

这里又来了一个问题，如果此时已经复制好了一个新链表，节点 `clonednode` 顺序和原链表 `node` 顺序一致，那么如果 `node -> random` 指向了一个其他的节点 `node1` ， `clonednode` 要如何指向相对应的节点 `clonednode1` 呢？

一种可能的方法是 暴力循环 ，每一次都从克隆链表的头节点开始遍历，直到找到和 `node1` 相同的 `clonednode1` ，但是这种做法有一个致命缺陷：如果一个链表中有相同 `val` 的节点，那么 `random` 指针很有可能会指错。因此这种方法行不通。

有什么高效又可以保证正确的方法呢？ 这里联想到了 **哈希表** 。哈希表的优势在于可以构建原节点和克隆节点之间的一一映射关系。那么如果在克隆链表时，就将原节点和克隆节点建立一一映射关系。即， `mp[node] = new node(node -> val);` ，则可以在后续确定 `random` 节点时，直接使用哈希表的映射功能找到克隆节点的位置。

既然哈希表可以记录一一映射的关系，那么就可以一边克隆节点，一边克隆节点的 `random` 指针指向的节点，只需一次遍历，即可完成复制。

**代码**
```cpp []
//第一种方法：使用hash表来记录每一个节点及其random节点，每遍历一个节点，就将这个节点的值还有random复制下来。
//使用hash表的好处在于不用考虑链表遍历时的顺序，即只要在遍历的时候出现了random节点，就可以直接将其保存在hash表中，之后等遍历到random节点时直接再处理random的random节点即可
Node *copyRandomList(Node *head)
{
    if (!head)
        return NULL;
    unordered_map<Node *, Node *> node_map;
    Node *p = head, *pre = NULL;
    while (p)
    {
        if (!node_map.count(p))
            node_map[p] = new Node(p->val);
        if (p->random)
        {
            if (!node_map.count(p->random))
                node_map[p->random] = new Node(p->random->val);
            node_map[p]->random = node_map[p->random];
        }
        if (pre)
            pre->next = node_map[p];
        pre = node_map[p];
        p = p->next;
    }
    return node_map[head];
}
```

当然也可以按照刚刚分析的思路，先建链表，然后再根据哈希表的映射关系，把 `random` 指针复制下来。

**代码**
```cpp []
//法2：同样是用hash表，不过这一次分两步进行遍历，先遍历一遍链表，把所有节点全部存到hash表中，然后再遍历一遍链表，这次确定所有链表的random指针
Node *copyRandomList(Node *head)
{
    if (!head)
        return NULL;
    unordered_map<Node *, Node *> node_map;
    Node *p = head;
    Node *dummy = new Node(0);
    Node *pre = dummy;
    //先把链表节点都保存到链表中
    while (p)
    {
        node_map[p] = new Node(p->val);
        pre->next = node_map[p];
        p = p->next;
        pre = pre->next;
    }
    //再遍历一次，保存每个节点的random节点，此时pre指向unordered_map中的第一个节点
    pre = node_map[head];
    p = head;
    while (p)
    {
        pre->random = node_map[p->random];
        p = p->next;
        pre = pre->next;
    }
    return node_map[head];
}
```

#### 分析2
分析 `1` 中的方法虽然很好，但是用到了额外的数据结构（ `unordered_map` ），有没有不用多余数据结构的方法呢？

有一种很巧妙的方法：可以先在每个节点 `node` 后克隆该节点（记为 `clonednode` ），即： `clonednode -> next = node -> next; node -> next = clonednode;` 。这样 `clonednode -> random = node -> random -> next` 。这实际上是将原链表扩大了 `2` 倍，最后只需要将这个扩大了的链表拆分，就得到了答案。

例：

| 表项             | 值                                               |
| ---------------- | ------------------------------------------------ |
| 原链表           | 1 -> 2 -> 3 -> NULL                              |
| 克隆节点后的链表 | 1 -> 1' -> 2 -> 2' -> 3 -> 3' -> NULL            |
| 拆分后的链表     | 1 -> 2 -> 3 -> NULL <br/> 1' -> 2' -> 3' -> NULL |


**代码**
```cpp []
//法3：不使用hash表，而是在每个node后紧接着复制一个相同的节点clonednode。
//这样一来，clonednode -> random = node -> random -> next
//最后再将node和clonednode拆开就行啦
Node *copyRandomList(Node *head)
{
    if (!head)
        return NULL;
    Node *p = head;
    //1. 复制每个节点，并接在相应节点后
    //原链表：1 -> 2 -> 3 -> NULL
    //现在的链表：1 -> 1(cloned) -> 2 -> 2(cloned) -> 3 -> 3(cloned) -> NULL
    while (p)
    {
        Node *tmp = new Node(p->val);
        tmp->next = p->next;
        p->next = tmp;
        p = tmp->next;
    }
    //2. 设置相应的random节点
    p = head;
    while (p)
    {
        if (p->random)
            p->next->random = p->random->next;
        p = p->next->next;
    }
    //3. 拆成两个链表
    Node *dummy = new Node(0);
    p = head;
    Node *cur = dummy;
    while (p)
    {
        cur->next = p->next;
        cur = cur->next;
        p->next = cur->next;
        p = p->next;
    }
    return dummy->next;
}
```