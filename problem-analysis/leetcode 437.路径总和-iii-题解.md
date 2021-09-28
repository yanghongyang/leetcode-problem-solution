### 题目描述

给定一个二叉树的根节点 `root` ，和一个整数 `targetSum` ，求该二叉树里节点值之和等于 `targetSum` 的 路径 的数目。

**路径** 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

**示例 1**

```
输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
输出：3
解释：和等于 8 的路径有 3 条。
```

**示例 2**

```
输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：3
```

**提示**

- 二叉树的节点个数的范围是 `[0,1000]`
- $-10^9 <= Node.val <= 10^9$
- $-1000 <= targetSum <= 1000$ 

> 来源：力扣（LeetCode）
> 链接：https://leetcode-cn.com/problems/path-sum-iii
> 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

### 考点

- 二叉树
- 递归

### 解法 1

对于二叉树的每一个节点，都进行一次深度优先搜索来确定是否存在潜在的和为 `targetSum` 的路径。那么问题可以分解为两步：

1. 当前的节点为何
2. 当前节点的众多路径里是否有和为 `targetSum` 的路径

使用先序遍历，遍历二叉树的每一个节点。对于每一个节点，使用深度优先搜索判断路径和。

```c++
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
class Solution {
public:
    int ans = 0;
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) {
            return 0;
        }
        dfs(root, targetSum);
        pathSum(root -> left, targetSum);
        pathSum(root -> right, targetSum);
        return ans;
    }

    void dfs(TreeNode* root, int sum) {
        if(root == nullptr) {
            return ;
        }
        sum -= root -> val;
        if(sum == 0) {
            ans++;
        }
        dfs(root -> left, sum);
        dfs(root -> right, sum);
    }
};
```

时间复杂度：$O(N^2)$，可以理解为，首先要遍历每一个二叉树节点，然后对于每一个二叉树节点，相当于又构建了一个小的二叉树（但是这个小二叉树的节点只遍历一遍），因此时间复杂度为$O(N^2)$。

空间复杂度：暂时不会。不过三叶姐说如果忽略递归的开销，是$O(1)$([【宫水三叶】一题双解 :「DFS」&「前缀和」 - 路径总和 III - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/path-sum-iii/solution/gong-shui-san-xie-yi-ti-shuang-jie-dfs-q-usa7/))，但是感觉这样很不靠谱...



#### 解法 2

前缀和的方法。代码和注释来自夏天哥[前缀和，递归，回溯 - 路径总和 III - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/path-sum-iii/solution/qian-zhui-he-di-gui-hui-su-by-shi-huo-de-xia-tian/)。

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int pathSum(TreeNode root, int targetSum) {
        // key 是前缀和， value 是大小为 key 的前缀和出现的次数
        Map<Integer, Integer> prefixSumCount = new HashMap<>();

        // 前缀和为 0 的一条路径 
        prefixSumCount.put(0, 1);

        // 前缀和的递归回溯
        return recursionPathSum(root, prefixSumCount, targetSum, 0);
    }

    private int recursionPathSum(TreeNode node, Map<Integer, Integer> prefixSumCount, int target, int currentSum) {
        // 递归终止条件
        if(node == null) {
            return 0;
        }
        // 本层要做的事情
        int res = 0;
        // 当前路径上的和
        currentSum += node.val;

        // 看 root 到当前节点的路径上是否存在 前缀和 + target == currentSum 的路径
        // 当前节点到根节点进行反推，如果此前有和为 currentSum - target，而当前的和又为 currentSum ，那么两者的差就肯定为 target
        // currentSum - target 相当于找路径的起点，起点的 sum + target == currentSum，当前点到起点的距离就是 target
        res += prefixSumCount.getOrDefault(currentSum - target, 0);
        // 更新路径上当前节点前缀和的个数
        prefixSumCount.put(currentSum, prefixSumCount.getOrDefault(currentSum, 0) + 1);

        // 进入下一层
        res += recursionPathSum(node.left, prefixSumCount, target, currentSum);
        res += recursionPathSum(node.right, prefixSumCount, target, currentSum);

        // 回到本层，恢复状态，去除当前节点的前缀和的数量
        prefixSumCount.put(currentSum, prefixSumCount.get(currentSum) - 1);

        return res;
    }
}
```

