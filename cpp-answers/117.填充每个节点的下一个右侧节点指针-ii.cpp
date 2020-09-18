/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    //额这种方法虽然可以，但是不符合题目要求的常数级额外空间
    /*     Node *connect(Node *root)
    {
        if (!root)
            return NULL;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                Node *t = q.front();
                q.pop();
                if (i != n - 1)
                {
                    Node *curfront = q.front();
                    t->next = curfront;
                }
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
        }
        return root;
    } */
    //思路和代码源自：https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/solution/117tian-chong-jie-dian-de-xia-yi-ge-jie-dian-you-c/
    //主要思路：把每一层看成一个单链表，在每一层开始创建dummy节点
    Node *connect(Node *root)
    {
        if (!root)
            return NULL;
        Node *cur = root;
        while (cur)
        {
            Node *dummy = new Node(); //创建dummy结点
            Node *tail = dummy;       //维护一个尾节点指针
            while (cur)
            {
                if (cur->left)
                {
                    tail->next = cur->left;
                    tail = tail->next;
                }
                if (cur->right)
                {
                    tail->next = cur->right;
                    tail = tail->next;
                }
                cur = cur->next; //cur同层移动到下一个位置
            }
            cur = dummy->next;
        }
        return root;
    }
};
// @lc code=end
