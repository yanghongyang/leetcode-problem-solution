/*
 * @lc app=leetcode.cn id=421 lang=cpp
 *
 * [421] 数组中两个数的最大异或值
 */

// @lc code=start
//抄答案的，链接在这儿：https://leetcode-cn.com/problems/maximum-xor-of-two-numbers-in-an-array/solution/qian-zhui-shu-shen-du-you-xian-bian-li-c-by-bartho/
struct TrieNode
{
    TrieNode *left;
    TrieNode *right;
    TrieNode() : left(NULL), right(NULL) {}
};
class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }
    void insert(vector<int> nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            TrieNode *node = root;
            unsigned int p = 0x80000000; //一定要用unsigned int，才能做逻辑位移
            while (p)
            {
                if (p & nums[i])
                {
                    if (node->right == NULL)
                    {
                        node->right = new TrieNode();
                    }
                    node = node->right;
                }
                else
                {
                    if (node->left == NULL)
                    {
                        node->left = new TrieNode();
                    }
                    node = node->left;
                }
                p = p >> 1;
            }
        }
    }
    int searchMax()
    {
        TrieNode *p = root;
        int res = 0;
        while (!p->left || !p->right)
        {
            if (p->left)
                p = p->left;
            else if (p->right)
                p = p->right;
            else
                break;
        }
        TrieNode *p1 = p->left;
        TrieNode *p2 = p->right;
        if (p1 && p2)
        {
            res = 1;
            search(p1, p2, res);
            return res;
        }
        else
            return 0;
    }
    void search(TrieNode *p1, TrieNode *p2, int &res)
    {
        if (!p1->left && !p1->right && !p2->left && !p2->right)
            return;
        //中间递归
        int r1 = 0, r2 = 0, r3 = 0;
        int temp = res;
        if (p1->left && p2->right)
        {
            res = res << 1;
            res++;
            search(p1->left, p2->right, res);
            r1 = res;
            res = temp;
        }
        if (p1->right && p2->left)
        {
            res = res << 1;
            res++;
            search(p1->right, p2->left, res);
            r2 = res;
            res = temp;
        }
        if (!((p1->left && p2->right) || (p1->right && p2->left)))
        {
            if (p1->left && p2->left)
            {
                res = res << 1;
                search(p1->left, p2->left, res);
                r3 = res;
                res = temp;
            }
            if (p1->right && p2->right)
            {
                res = res << 1;
                search(p1->right, p2->right, res);
            }
        }
        if (r1 > res)
            res = r1;
        if (r2 > res)
            res = r2;
        if (r3 > res)
            res = r3;
    }
};

class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        Trie trie;
        trie.insert(nums);
        return trie.searchMax();
    }
};
// @lc code=end
