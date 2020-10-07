/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-10-07 21:01:46
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-10-07 21:26:49
 */
/*
 * @lc app=leetcode.cn id=1110 lang=cpp
 *
 * [1110] 删点成林
 */

// @lc code=start
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
    //这题看起来实在是麻烦...
    //能理解意思但是写不出代码系列
    //主要的难点在于把节点删掉后，得找到它的孩子结点，并且存到vector中
    //......想了半天不会做，抄答案了
    //有一种答案写的挺好的，先用广度优先遍历确定要删除的点，然后再后序遍历删除节点。
    //这种方法感觉用后序遍历很精妙，准确地讲应该是先考察孩子再考察老父亲的方法
    vector<TreeNode *> nodes;
    int deleteNode(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int l = deleteNode(root->left);
        int r = deleteNode(root->right);
        if (l == 1)
        {
            //如果左孩子是要删除的点，那就舍去root的左子树
            root->left = NULL;
        }
        if (r == 1)
        {
            //同理，如果右孩子是要删除的点，则舍去root的右子树
            root->right = NULL;
        }
        //否则，如果root本身就是要删掉的结点，则左右孩子各自成树
        if (root->val == -1)
        {
            if (root->left != NULL)
                nodes.push_back(root->left);
            if (root->right != NULL)
                nodes.push_back(root->right);
            //由于当前的结点被删掉了，所以返回1
            return 1;
        }
        return 0;
    }
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        //广度遍历
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *tmp = q.front();
            //这里不能用for循环存储所有的层，会超时的
            //所以直接判断左右子树是否存在，然后入队就行
            if (tmp->left)
                q.push(tmp->left);
            if (tmp->right)
                q.push(tmp->right);
            for (int i = 0; i < to_delete.size(); i++)
            {
                if (tmp->val == to_delete[i])
                    tmp->val = -1;
            }
            q.pop();
        }
        int r = deleteNode(root); //如果当前的root被删掉了，那就返回1，否则返回0
        if (r == 0)               //root完好无损，就把整个树放进来
        {
            nodes.push_back(root);
        }
        return nodes;
    }
};
// @lc code=end
