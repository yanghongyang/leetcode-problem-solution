### 考点
- 二叉树遍历

### 思路
解这道题之前，首先需要明确二叉树的**前序遍历**和**中序遍历**的特点。

二叉树的前序遍历，简而言之为：根节点最先遍历，然后递归遍历根节点的左子树和右子树。

二叉树的中序遍历，简而言之为：按照左中右的顺序，根节点在递归遍历完左子树之后遍历，接着递归遍历右子树。

接下来分析题目所给案例：
```
前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
```

首先确定根节点。根据前序遍历，`preorder` 的首个元素即为整个二叉树的根节点。

接着确定根节点的左右子树。根据中序遍历，`inorder` 中根节点的左边全是属于左子树的元素，而右边全是属于右子树的元素。至此就可以把案例分成左子树（9），根节点（3），右子树（20，15，7）三个部分。

已经确定了全树的根节点，要想构造整个树，需要知道根节点的左孩子（即左子树的根节点）和右孩子（即右子树的根节点）。根据之前的分析，已经确定了左子树和右子树组成的元素以及它们的先序遍历和中序遍历结果。因此按照递归的思路循环往复就可以得到答案。

### 递归
**代码（版本1）**
```cpp []
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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int prestart, int preend, int instart, int inend)
    {
        if(prestart > preend)
            return nullptr;
        TreeNode* node = new TreeNode(preorder[prestart]);  //根节点
        int pos;
        for(int i = instart; i <= inend; i++)
        {
            if(inorder[i] == preorder[prestart])    //找到当前根节点在对应中序遍历中的位置
            {
                pos = i;
                break;
            }
        }
        node -> left = build(preorder, inorder, prestart + 1, prestart + pos - instart, instart, pos - 1);
        node -> right = build(preorder, inorder, prestart + pos - instart + 1, preend, pos + 1, inend);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
```

**代码1** 中的代码，可能引起注意的是这两行：
```cpp []
node -> left = build(preorder, inorder, prestart + 1, prestart + pos - instart, instart, pos - 1);
node -> right = build(preorder, inorder, prestart + pos - instart + 1, preend, pos + 1, inend);
```
作一下解释，还是以题目案例为例。

```
前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
首先，易知根节点为 3 ，接着在中序中找到了对应的位置 pos。
方便起见，把 prestart 简写为 ps，preend 简写为 pe, instart 简写为 is，inend简写为 ie。

3       9       20      15      7
ps                              pe

9       3       15      20      7
is      pos                     ie

如何递归？

因此中序遍历的左边为左子树，右边为右子树。先从左子树开始，对于左子树需要找到左子树根节点。在先序遍历中，如果存在左子树，则左子树根节点紧跟着全树根节点（ps+1）。如果左子树不存在的话，可以直接用 prestart>preend 进行判定。
左子树对应的元素个数如何判定？根据中序遍历，中序遍历根节点的左边全部都是左子树的元素，因此左子树对应的元素个数为：pos-is。
因此在先序遍历中，左子树的范围为[ps+1, ps+1+pos-is-1]，即为[ps+1, ps+pos-is]。
而在中序遍历中，由于根节点左边全部为左子树，因此左子树的范围为[is, pos-1]

3       9       20      15      7
ps      ps+1                    pe 
        ps+pos-is

9       3       15      20      7
is      pos                     ie
pos-1

同理可以确定在先序遍历中右子树的范围：[ps+pos-is+1, pe]
在中序遍历中右子树的范围：[pos+1, ie]

3       9       20      15      7
ps      ps+1                    pe 
                ps+pos-is+1     pe

9       3       15      20      7
is      pos                     ie
                pos+1           ie

```

时间复杂度：$O(NlogN)$，其中 N 为二叉树的节点个数。
这里理解为：尽管出现了递归，但是对于整个二叉树，每个节点仅被访问了一次。理应为 $O(N)$。

但在这里值得注意的是，每一次都需要**顺序**查找中序遍历中根节点的位置，因此也消耗了时间，算作 $O(NlogN)$ 时间？（对不起有点晕了）

空间复杂度：$O(logN)$，递归空间为树的高度，即$O(logN)$。

接着我在网上看到了大伙们的解法，用到了哈希表。一开始不明白为啥要用哈希表，但结合刚刚对于**代码1**的分析，我明白了。使用哈希表的作用是**存储节点和数字的映射关系，从而不用在中序遍历中按顺序查找，直接利用映射关系即可在中序遍历中快速找到根节点位置，从而提速**。

**代码2**
```cpp []
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
    unordered_map<int, int> mp;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int prestart, int preend, int instart, int inend)
    {
        if(prestart > preend)
            return nullptr;
        TreeNode* node = new TreeNode(preorder[prestart]);
        int pos = mp[preorder[prestart]];
        node -> left = build(preorder, inorder, prestart + 1, prestart + pos - instart, instart, pos - 1);
        node -> right = build(preorder, inorder, prestart + pos - instart + 1, preend, pos + 1, inend);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
```
时间复杂度：$O(N)$。N 为二叉树元素的个数。这里理解为每个二叉树的元素被遍历了 1 次。

空间复杂度：$O(N)$。这里理解为，建哈希表所需要$O(N)$的空间。尽管需要考虑递归带来的树高，但由于 `N > logN` ，因此空间复杂度为 $O(N)$。

可以看出，先比较**代码1**，**代码2**仅仅进行了寥寥几行的更改，但由于使用了更高级的数据结构，使得查找速度得到了大幅度提升。（时间复杂度上，代码2 打败了99.65% 的用户，但内存消耗仅击败了 26.99% 的用户）

### 迭代
有了递归解法，接下来来思考是否有迭代的解法。因为众所周知，递归需要使用到递归栈，在空间上是一种消耗。

是否可以模拟递归要用到的递归栈，从而写出迭代解法呢？大概是可以的吧......啊但是我不会写啊啊啊。

[官方题解](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solution/cong-qian-xu-yu-zhong-xu-bian-li-xu-lie-gou-zao-9/)给出了迭代解法。一言以蔽之：找到并判定先序遍历中的节点到底是左孩子还是某节点的右孩子。

```cpp []
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(!preorder.size())
            return nullptr;
        stack<TreeNode*> sta;
        TreeNode* root = new TreeNode(preorder[0]);
        sta.push(root);
        int index = 0;
        for(int i = 1; i < preorder.size(); i++)
        {
            int pv = preorder[i];
            TreeNode* node = sta.top();
            if(node -> val != inorder[index])   //如果不相等的话，就说明一直是左孩子。除了构建之外，为了可能之后会出现的右孩子，需要将当前节点入栈。
            {
                node -> left = new TreeNode(pv);
                sta.push(node -> left);
            }
            else   //当出现了栈顶元素和当前元素相等的情况，说明下一个节点可能是当前栈中节点的右孩子
            {
                //根据压栈顺序和二叉树先序的遍历的相反顺序关系，出栈
                while(!sta.empty() && sta.top() -> val == inorder[index])
                {
                    node = sta.top();
                    sta.pop();
                    index++;
                }
                //下一个节点就是之前栈顶结点的右孩子
                node -> right = new TreeNode(pv);
                sta.push(node -> right);
            }
        }
        return root;
    }
};
```

时间复杂度： $O(N)$。

空间复杂度：$O(N)$。

### 后记
这题十分经典，根据笔者乱七八糟的本科回忆，**代码1** 和迭代解法都应该曾在数据结构课上听老师讲过。既然是听老师讲过的话，那是不是严蔚敏的《数据结构》课本里也会有呢？

然后我就查了查......结果没有。那么大概就是可爱的数据结构老师把这道题作为例题给我们讲了吧。虽然这四年没少给老师坏印象（诸如迟到和课程设计水等等等等），但我依然很喜欢很尊敬这位老师！

除此之外，感觉其他版本的数据结构教材其实编的也不错？只不过THU的邓老师讲课实在是很棒以至于我忽略了其他的教材吧哈哈哈。

这题给我的收获主要是 **优化的时候可以从数据结构的角度考虑一下**。

感觉迭代版需要更多的思维量以及对二叉树遍历更深刻的理解。这里先把代码放在这里，隔几天再过来复习复习。