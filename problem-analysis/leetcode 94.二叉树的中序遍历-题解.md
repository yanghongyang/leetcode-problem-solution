# [题目描述](https://leetcode-cn.com/problems/binary-tree-inorder-traversal)
给定一个二叉树，返回它的中序遍历。

```
示例:
输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
```
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

```
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

# 考点（解题方向）
- 递归
- 栈
- **Morris遍历**

# 代码（递归）
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode *root, vector<int> &nodes)
    {
        if(!root)
            return ;
        inorder(root -> left, nodes);
        nodes.push_back(root -> val);
        inorder(root -> right, nodes);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        inorder(root, nodes);
        return nodes;
    }
};
```

# 代码（栈）
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //迭代方法，使用栈
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        stack<TreeNode *> todo;
        while(root || !todo.empty())
        {
            while(root)
            {
                todo.push(root);
                root = root -> left;
            }
            root = todo.top();
            todo.pop();
            nodes.push_back(root -> val);
            root = root -> right;
        }
        return nodes;
    }
};
```

# 代码（Morris遍历）
Morris遍历是在刷题（尤其是二叉树遍历）时非常常见的一种方法。其基于的思想是 **线索树**。通过保存当前结点 **cur** 和之前的节点 **pre** 来将一个二叉树转化成线索树。

参考题解见：[动画演示+三种实现 94. 二叉树的中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/solution/dong-hua-yan-shi-94-er-cha-shu-de-zhong-xu-bian-li/)。

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //Morris遍历
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> nodes;
        while(root)
        {
            //如果左节点不为空，将当前结点连带右子树全部挂到左节点的最右子树下面
            if(root -> left)
            {
                TreeNode* pre = root -> left;
                while(pre -> right && pre -> right != root)
                {
                    pre = pre -> right;
                }
                if(!pre -> right)
                {
                    //到达最右子树后，将最右子树的最右子节点和根节点连接，而根节点更新到原来根节点的左孩子处
                    pre -> right = root;
                    root = root -> left;
                }//下面这个else判断可以不要
                else 
                {
                    pre -> right = NULL;
                    nodes.push_back(root -> val);
                    root = root -> right;
                }
            }
            else 
            {
                nodes.push_back(root -> val);
                root = root -> right;
            }
        }
        return nodes;
    }
};
```
