/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    //emmmmm这题实际上就是考察基本功吧，删除BST中的节点需要首先找到最后一个比它小的节点，然后互换位置，再把这个节点删掉就行了
    //网上的答案怎么递归一个个写的都这么难缠啊。。。
    //抄了一份好看一点的（来自万能的vscode插件）
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return root;
        TreeNode *node = root;
        TreeNode *parent = NULL;
        while (node)
        {
            if (node->val == key)
            {
                break;
            }
            if (node->val < key)
            {
                parent = node;
                node = node->right;
            }
            if (node->val > key)
            {
                parent = node;
                node = node->left;
            }
        }
        if (!node)
            return root;  //如果找不到就直接返回了
        else if (!parent) //如果找到的是值对应的是根节点
        {
            return deleteRoot(root);
        }
        else if (parent->left == node) //如果查找位置对应其父节点的左边
        {
            parent->left = deleteRoot(node);
        }
        else if (parent->right == node) //如果查找位置对应其父节点的右边
        {
            parent->right = deleteRoot(node);
        }
        return root;
    }
    //删除子树根节点的操作，包含重构子树的过程
    //参数还是用node吧，比较符合语义（是子树而不是根）
    TreeNode *deleteRoot(TreeNode *node)
    {
        if (!node)
            return NULL; //如果node不存在（额这种情况应该不用判断吧，但还是判断一下以防万一）
        else if (!node->left && !node->right)
        {
            return NULL; //这种情况对应的是叶子节点，直接删除节点就行了，不用对子树进行重构（根本就没有子树，只是个孤零零的叶子）
        }
        else if (!node->left)
        {
            return node->right; //这种情况对应的是左子树不存在，那把节点删掉之后就只剩下右子树了
        }
        else if (!node->right)
        {
            return node->left; //这种情况对应右子树不存在，情况和左子树不存在相反
        }
        else
        {
            //最麻烦的是左右子树都存在的情况，此时需要找到子树的某个叶子节点作为新子树的根
            TreeNode *parent = node;
            TreeNode *lchild = node->left;
            while (lchild->right)
            {
                parent = lchild;
                lchild = lchild->right;
            }
            //这样以后就找到了node左子树的最右孩子（对应的就是最后一个小于node的节点）
            //接下来需要互换位置
            swap(node->val, lchild->val);
            //接着需要隔离值为node->val的节点（也就是lchild），否则起不到删除的作用
            if (parent->right == lchild)
            {
                parent->right = lchild->left;
            }
            else
            {
                parent->left = lchild->left;
            }
            return node;
        }
    }
};
// @lc code=end
