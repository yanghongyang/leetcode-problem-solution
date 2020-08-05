# [题目描述](https://leetcode-cn.com/problems/house-robber-iii/)
在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

```
示例 1:
输入: [3,2,3,null,3,null,1]
输出: 7 
解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.
```

```
示例 2:
输入: [3,4,5,1,3,null,1]
输出: 9
解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.
```
# 写在前面
之前并没有写过树状dp的题目，在CPP实现过程中主要参考[王小二](https://leetcode-cn.com/problems/house-robber-iii/solution/san-chong-fang-fa-jie-jue-shu-xing-dong-tai-gui-hu/)的题解。这篇题解写的非常棒！受教了！本篇题解的价值主要在于提供多种CPP解法供参考，所以还是有一点点点价值的！嗯！
# 考点
- 动态规划
- 树状dp
- 递归
- 空间优化

# 题目分析
这道题目的难点主要在小偷发现该地区的所有房屋排列类似于一颗二叉树......

动态规划的核心在于最优子结构，也就是，如果小偷想在根节点处获得最高金额，必须在根节点的左右子树上也都获得最高金额。

有三种解法来解答该问题。在实现的时候，可以在树状dp的基础上对空间进行压缩。
- 暴力递归
- 暴力基础上的记忆化
- 树状dp
- 树状dp+空间压缩

# 解法一：暴力递归（CPP解法超时，JAVA解法正常）
对于本题来讲，最直接的想法是递归直接解。

对于节点来讲，可以选择也可以不选。

那么使用`money`来统计选择当前节点情况下的值，

如果不选当前节点，则必须分别计算当前节点的左子树和右子树的最大值，之后统计两者之和。

将`money`和两者之和进行比较取其最大值即为解答。

代码如下：
```
//暴力法，超时
int rob(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int money = root->val;
    if (root->left != NULL)
    {
        money += (rob(root->left->left) + rob(root->left->right));
    }
    if (root->right != NULL)
    {
        money += (rob(root->right->left) + rob(root->right->right));
    }
    return max(money, rob(root->left) + rob(root->right));
}
```

# 解法二：暴力基础上的记忆化
解法一很费时。

在解法一的基础上分析，发现在递归调用过程中，节点的左子树和右子树判断时出现了**重复计算**的情况。

因此使用一个hash map对每个节点的最大值进行存储，达到**记忆化**的效果。

代码如下：
```
//少量的优化：记忆化
//性能大幅度提升！不超时了，并且内存消耗变少
int rob(TreeNode *root)
{
    unordered_map<TreeNode *, int> memo;
    return robInternal(root, memo);
}
int robInternal(TreeNode *root, unordered_map<TreeNode *, int> &memo)
{
    if (root == NULL)
        return 0;
    if (memo.find(root) != memo.end())
        return memo[root];
    int money = root->val;
    if (root->left != NULL)
    {
        money += (robInternal(root->left->left, memo) + robInternal(root->left->right, memo));
    }
    if (root->right != NULL)
    {
        money += (robInternal(root->right->left, memo) + robInternal(root->right->right, memo));
    }
    int result = max(money, robInternal(root->left, memo) + robInternal(root->right, memo));
    memo[root] = result;
    return result;
}
```

# 解法三：树状dp
在解法二的基础上分析，发现解法二有一行代码：
```
int result = max(money, robInternal(root->left, memo) + robInternal(root->right, memo));
```
可以看到，不管怎样优化，都是将情况分为偷根节点和不偷根节点两种的。

那么可以使用两个Hash map来分别计算偷根节点和不偷根节点的情况，最后返回两个Hash map中的最大值。

代码如下：
```
//树形dp
//用两个hash map分别记录当前节点选中和未选中的最大值
unordered_map<TreeNode *, int> yes, no;
int rob(TreeNode *root)
{
    robInterval(root);
    return max(yes[root], no[root]);
}
void robInterval(TreeNode *root)
{
    if (root == NULL)
        return;
    robInterval(root->left);
    robInterval(root - > right);
    yes[root] = root->val + no[root->left] + no[root->right];
    no[root] = max(yes[root->left], no[root->left]) + max(yes[root->right], no[root->right]);
}
```
# 解法四：树状dp+空间压缩
在解法三的基础上进一步优化。主要在存储空间的优化上。优化存储空间的基础上也大大提升了时间效率。

实现过程中可以不用两个hash map，而是直接使用两个变量进行实时的更新。

代码如下：
```
//对树状dp的朴素做法进行空间压缩，不使用两个hash map而是使用两个变量来记录遍历过程中出现的问题
int rob(TreeNode *root)
{
    int l = 0, r = 0;
    return robInterval(root, l, r);
}
int robInterval(TreeNode *root, int &l, int &r)
{
    if (!root)
        return 0;
    int ll = 0, lr = 0, rl = 0, rr = 0;
    l = robInterval(root->left, ll, lr);
    r = robInterval(root->right, rl, rr);
    return max(root->val + ll + lr + rl + rr, l + r);
}
```