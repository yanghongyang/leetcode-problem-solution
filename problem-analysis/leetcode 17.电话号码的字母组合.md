<!--
 * @Description:
 * @Author: Hongyang_Yang
 * @Date: 2020-08-08 09:46:21
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-08 10:08:18
-->

# [题目描述](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number)

给定一个仅包含数字  `2-9`  的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 `1` 不对应任何字母。
[映射图片](https://assets.leetcode-cn.com/aliyun-lc-upload/original_images/17_telephone_keypad.png)

```
示例:
输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
说明:
尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
```

```
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

# 考点（解题方向）

- 回溯（通过 dfs 实现）
- 队列（bfs 思想）

# 代码（回溯）

这道题和全排列有一点点相似，那么比较好的方法就是回溯法。

使用 dfs 进行回溯，注意状态的恢复即可。

```
class Solution {
public:
    vector<string> letter = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty())
            return res;
        string tmp = "";
        dfs(digits, 0, tmp, res, letter);
        return res;
    }
    void dfs(string digits, int pos, string& path, vector<string>& res, vector<string>& letter)
    {
        if(pos == digits.size())
        {
            res.push_back(path);
            return ;
        }
        for(auto c : letter[digits[pos] - '0'])
        {
            path.push_back(c);
            dfs(digits, pos + 1, path, res, letter);
            path.pop_back();
        }
    }
};
```

# 代码（队列）

既然可以用 dfs 解决，也就可以用 bfs 解决。bfs 的一般实现都使用的是队列。

参考解答：[c++ 队列简单实现、易懂](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/solution/c-dui-lie-jian-dan-shi-xian-yi-dong-by-su-ge/)

代码如下：

```
class Solution {
public:
    //队列
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        map<char, string> m = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        int n = digits.size();
        queue<string> que;  //队列
        //将第一个数字对应的字母入队
        for(int i = 0; i < m[digits[0]].size(); i++)
        {
            string str;
            str.push_back(m[digits[0]][i]);
            que.push(str);  //string入队
        }
        string s;   //用于存储队头
        for(int i = 1; i < n; i++)
        {
            int length = que.size();    //当前队列长度
            while(length--)
            {
                for(int j = 0; j < m[digits[i]].size(); j++)
                {
                    s = que.front();
                    s = s + m[digits[i]][j];//  队头加上新元素
                    que.push(s);    //入队
                }
                que.pop();
            }
        }
        while(!que.empty())
        {
            res.push_back(que.front()); //队头元素存储至res
            que.pop();  //队头出队
        }
        return res;
    }
};
```
