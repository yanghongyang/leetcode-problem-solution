### 题目描述

单词的 **广义缩写词** 可以通过下述步骤构造：先取任意数量的不重叠的子字符串，再用它们各自的长度进行替换。例如，`"abcde"` 可以缩写为 `"a3e"`（`"bcd"` 变为 `"3"` ），`"1bcd1"`（`"a"` 和 `"e"` 都变为 `"1"`），`"23"`（`"ab"` 变为 `"2"` ，`"cde"` 变为 `"3"` ）。

给你一个字符串 `word` ，返回一个由所有可能 **广义缩写词** 组成的列表。按 **任意顺序** 返回答案。

**示例 1**

```
输入：word = "word"
输出：["4","3d","2r1","2rd","1o2","1o1d","1or1","1ord","w3","w2d","w1r1","w1rd","wo2","wo1d","wor1","word"]
```

**示例 2**

```
输入：word = "a"
输出：["1","a"]
```

**提示**

- $1 <= word.length <= 15$
- `word` 仅由小写英文字母组成

> 来源：力扣（LeetCode）
> 链接：https://leetcode-cn.com/problems/generalized-abbreviation
> 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

### 考点

- 回溯
- 位运算

### 解法 1

参考自 powcai 大哥。（因为太久没练回溯，有点忘记了怎么写......）

对于每一个字符，都可以选择并入，也可以选择不并入。如果选择并入，那么计数器+1，如果不并入，那么将这个字母接在当前的字符串后，同时计数器清零。

代码如下：

```c++
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> ans;
        dfs(0, "", 0, ans, word);
        return ans;
    }

    void dfs(int i, string temp, int cnt, vector<string>& ans, string& word) {
        if(i == word.size()) {  // 如果到了边界，就加入总答案
            if(cnt > 0) {
                temp += to_string(cnt);
            } 
            ans.push_back(temp);
        } else {
            dfs(i + 1, temp, cnt + 1, ans, word);   // 如果当前的字母算进数字，则什么都不用操作
            string t = temp;    // 如果当前的字母不算进数字，则需要在当前字符串后加入当前字母，然后重新计数（cnt=0）
            if(cnt > 0) {
                t += to_string(cnt);
            }
            t += word[i];
            dfs(i + 1, t, 0, ans, word);
        }
    }
};
```

//时间复杂度：$O(2^n)$。理由为，使用回溯，并且不能剪枝。对于字符串的每一个字母，都可以选择并入，也可以选择不并入，所以总共 $2^n$ 种答案，因此时间复杂度为 $O(2^n)$ 。

//空间复杂度：$O(2^n)$。

这个时间复杂度分析的好像有点问题，所以我摘抄了一下官方题解的分析。

时间复杂度： $O(n 2^n)$。对于每一次 backtrack 调用，要么到达椰子节点，要么分支成两个回溯调用。所有这些回溯调用共同构成了一个 $2^n$ 的完全二叉回溯树，它有 $2^n$ 个叶子节点和 $2^{n - 1}$个内部节点。对于每个叶子节点，需要 $O(n)$ 的时间构建缩写字符串。对于每个内部节点，只需要常数级别的时间。因此，总时间复杂度由叶子节点决定，总共是 $O(n2^n)$。

空间复杂度： $O(n)$ 。如果不算上返回列表，我们只需要 $O(n)$ 的空间在 StringBuilder 中保存字符以及额外的 $O(n)$ 的系统栈空间。在回溯的题目中，系统栈空间跟最大回溯深度呈线性关系，此题中为 $n$ 。

> 作者：LeetCode
> 链接：https://leetcode-cn.com/problems/generalized-abbreviation/solution/lie-ju-dan-ci-de-quan-bu-suo-xie-by-leetcode/
> 来源：力扣（LeetCode）
> 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

cai哥还提供了一种 dfs 的解法，我提供一个 cpp 的版本：

```c++
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> ans;
        dfs(0, "", ans, word);
        return ans;
    }

    void dfs(int i, string temp, vector<string>& ans, string& word) {
        if(i == word.size()) {  // 如果到了边界，就加入总答案 
            ans.push_back(temp);
        } else {
            for(int j = i; j < word.size(); j++) {
                string t = temp;
                if(j > i) {
                    t += to_string(j - i);
                }
                t += word[j];
                dfs(j + 1, t, ans, word);
            }
            string t = temp;
            t += to_string(word.size() - i);
            dfs(word.size(), t, ans, word);
        }
    }
};
```

### 解法 2

位运算：使用 0 代表没有被缩写的字符， 1 代表缩写的单次，每一个缩写对应到 n 位的二进制数字。

word -> 0011 则对应 wo2

```c++
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        int n = word.size();
        vector<string> ans;
        for(int i = 0; i < (1 << n); i++) {
            string str;
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(i & (1 << j)) {  // 如果是连续的 1
                    cnt++;
                } else {
                    if(cnt) {
                        str += to_string(cnt);
                        cnt = 0;
                    }
                    str += word[j];
                }
            }
            if(cnt) {
                str += to_string(cnt);
                cnt = 0;
            }
            ans.emplace_back(str);
        }
        return ans;
    }
};
```

