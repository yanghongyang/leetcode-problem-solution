/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-08 10:49:12
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-16 23:38:09
 */
/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] 数据流中的第K大元素
 */

// @lc code=start
struct CustomNode
{
    int val;
    int cnt; //记录下子树的节点
    CustomNode *left, *right;
    CustomNode(int x) : val(x), cnt(1), left(NULL), right(NULL) {}
};

class KthLargest
{
public:
    CustomNode *root = NULL;
    int k;

    CustomNode *insert(CustomNode *root, int num)
    {
        if (root == NULL)
            return new CustomNode(num);
        if (root->val < num)
            root->right = insert(root->right, num);
        else
            root->left = insert(root->left, num);

        root->cnt++; //增加树中的节点

        return root;
    }

    int search(CustomNode *root, int k)
    {
        if (root == NULL)
            return 0;
        int nodesRight = 0;
        if (root->right != NULL)
            nodesRight = root->right->cnt;
        int rootLargest = nodesRight + 1; //M + 1最大
        if (rootLargest == k)
            return root->val;
        else if (k < rootLargest)
            return search(root->right, k);
        k = k - rootLargest;
        return search(root->left, k);
    }

    KthLargest(int k, vector<int> &nums)
    {
        //构建一个树
        for (int num : nums)
        {
            this->root = this->insert(this->root, num);
        }
        this->k = k;
    }

    int add(int val)
    {
        this->root = this->insert(this->root, val); //O(logN) time
        //查找第k个最大值
        return search(this->root, this->k);
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end
