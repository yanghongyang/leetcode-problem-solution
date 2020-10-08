<!--
 * @Description:
 * @Author: Hongyang_Yang
 * @Date: 2020-10-09 07:08:04
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-10-09 07:08:15
-->

### 解题思路

解题关键在：所给的二叉树为一个 **二叉搜索树**。

**二叉搜索树** 意味着： **其中序遍历是一个单调递增的序列。**

这和题目所求的变平衡有何关系呢？

变平衡从某种程度上意味着，根节点是左右孩子的中位数。（个人理解）

那么可以确定的一种思路为：

1. 中序遍历原二叉搜索树，将遍历结果保存到 `ans` 向量中
2. 在 `ans` 中，每次选取其中位数作为根节点，中位数左半部分的中位数作为其左孩子，中位数右半部分的中位数作为其右孩子
3. 步骤 2 中的选取和操作，使用递归来实现

### 代码

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
    vector<TreeNode *> ans;
    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        inorder(root->left);
        ans.push_back(root);
        inorder(root->right);
    }
    TreeNode *build(int l, int r)
    {
        if (l > r)
            return NULL;
        int mid = (l + r) / 2;
        ans[mid]->left = build(l, mid - 1);
        ans[mid]->right = build(mid + 1, r);
        return ans[mid];
    }
    TreeNode *balanceBST(TreeNode *root)
    {
        inorder(root);
        return build(0, ans.size() - 1);
    }
};
```
