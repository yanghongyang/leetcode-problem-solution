<!--
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-15 09:34:01
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-15 09:50:42
-->
# [题目描述](https://leetcode-cn.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/)
给你两棵二叉树，原始树 `original` 和克隆树 `cloned`，以及一个位于原始树 `original` 中的目标节点 `target`。

其中，克隆树 `cloned` 是原始树 `original` 的一个 副本 。

请找出在树 `cloned` 中，与 `target` 相同 的节点，并返回对该节点的引用（在 `C/C++` 等有指针的语言中返回 节点指针，其他语言返回节点本身）。

**注意**

你**不能**对两棵二叉树，以及 `target` 节点进行更改。
**只能**返回对克隆树 `cloned` 中已有的节点的引用。

**进阶**

如果树中允许出现值相同的节点，你将如何解答？

**提示**

树中节点的数量范围为 `[1, 10^4]` 。
同一棵树中，没有值相同的节点。
`target` 节点是树 `original` 中的一个节点，并且不会是 `null` 。

```
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

# 考点（解题方向）
- DFS
- BFS

# 题目分析
拿到这题，首先联想到的是克隆二叉树（hhhh和解题没有任何关系）。

言归正传，既然克隆树`original`是原始树`cloned`的副本，也就意味着其各个节点之间的相对位置和节点值是不变的。那么题目可以转换为，**找到二叉树中的某一结点**。在寻找的时候，只需要保持克隆树和原始树的节点一致即可。

当找到原始树中的那个目标节点`target`时，只需要返回克隆树中对应的那个节点即可。

# 代码（DFS）
**版本一（也许更确切地说是递归）**
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

class Solution
{
public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        if (original == nullptr)
            return nullptr;
        else if (original == target)
            return cloned;
        return getTargetCopy(original->left, cloned->left, target) ?: getTargetCopy(original->right, cloned->right, target);
    }
};
```

**版本二**
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

class Solution
{
public:
    void dfs(TreeNode *original, TreeNode *cloned, TreeNode *target, TreeNode *&resultNode)
    {
        if (!original || resultNode)
            return;
        if (original == target)
            resultNode = cloned;
        if (original->left)
            dfs(original->left, cloned->left, target, resultNode);
        if (original->right)
            dfs(original->right, cloned->right, target, resultNode);
    }
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        TreeNode *resultNode(nullptr);
        dfs(original, cloned, target, resultNode);
        return resultNode;
    }
};
```

# 代码（BFS）
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

class Solution
{
public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        if (!original)
            return nullptr;
        queue<TreeNode *> todo1, todo2;
        todo1.push(original);
        todo2.push(cloned);
        while (!todo1.empty())
        {
            if (todo1.front() == target)
                return todo2.front();
            if (todo1.front()->left)
            {
                todo1.push(todo1.front()->left);
                todo2.push(todo2.front()->left);
            }
            if (todo1.front()->right)
            {
                todo1.push(todo1.front()->right);
                todo2.push(todo2.front()->right);
            }
            todo1.pop();
            todo2.pop();
        }
        return nullptr;
    }
};
```