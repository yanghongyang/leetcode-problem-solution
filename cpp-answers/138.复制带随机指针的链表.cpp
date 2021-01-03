/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2021-01-03 17:54:14
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2021-01-03 18:47:23
 */
/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    //第一种方法：使用hash表来记录每一个节点及其random节点，每遍历一个节点，就将这个节点的值还有random复制下来。
    //使用hash表的好处在于不用考虑链表遍历时的顺序，即只要在遍历的时候出现了random节点，就可以直接将其保存在hash表中，之后等遍历到random节点时直接再处理random的random节点即可
    /*     Node *copyRandomList(Node *head)
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
    } */
    //法2：同样是用hash表，不过这一次分两步进行遍历，先遍历一遍链表，把所有节点全部存到hash表中，然后再遍历一遍链表，这次把所有链表的random节点进行保存
    //好处在于
    /*     Node *copyRandomList(Node *head)
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
    } */
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
};
// @lc code=end
