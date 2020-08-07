<!--
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-07 22:32:37
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-07 22:59:36
-->
# [题目描述](https://leetcode-cn.com/problems/integer-to-roman)
罗马数字包含以下七种字符： `I`， `V`， `X`， `L`，`C`，`D` 和 `M`。

| 字符 | 数值 |
| ---- | ---- |
| I    | 1    |
| V    | 5    |
| X    | 10   |
| L    | 50   |
| C    | 100  |
| D    | 500  |
| M    | 1000 |

例如， 罗马数字 `2` 写做 `II` ，即为两个并列的 `1`。`12` 写做 `XII` ，即为 `X + II` 。 `27` 写做  `XXVII`, 即为 `XX + V + II` 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 `4` 不写做 `IIII`，而是 `IV`。数字 `1` 在数字 `5` 的左边，所表示的数等于大数 `5` 减小数 `1` 得到的数值 `4` 。同样地，数字 `9` 表示为 `IX`。这个特殊的规则只适用于以下六种情况：

`I` 可以放在 `V (5)` 和 `X (10)` 的左边，来表示 `4` 和 `9`。

`X` 可以放在 `L (50)` 和 `C (100)` 的左边，来表示 `40` 和 `90`。 

`C` 可以放在 `D (500)` 和 `M (1000)` 的左边，来表示 `400` 和 `900`。

给定一个整数，将其转为罗马数字。输入确保在 `1` 到 `3999` 的范围内。

```
示例 1:
输入: 3
输出: "III"
```
```
示例 2:
输入: 4
输出: "IV"
```
```
示例 3:
输入: 9
输出: "IX"
```
```
示例 4:
输入: 58
输出: "LVIII"
解释: L = 50, V = 5, III = 3.
```
```
示例 5:
输入: 1994
输出: "MCMXCIV"
解释: M = 1000, CM = 900, XC = 90, IV = 4.
```

# 考点
- 模拟
- 贪心

# 代码（模拟）
```
class Solution {
public:
    //建表，枚举个、十、百、千可能出现的字母组合，根据给定数字各个位的值从表中直接取字母
    string intToRoman(int num) {
        string table[4][10] = {{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}, 
                                {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}, 
                                {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}, 
                                {"", "M", "MM", "MMM"}
                                };
        string result;
        int cnt = 0;  //统计数位
        while(num > 0)
        {
            int tmp = num % 10;
            result = table[cnt][tmp] + result;
            num /= 10;
            cnt++;
        }
        return result;
    }
};
```

# 代码（贪心）
```
class Solution {
public:
    string intToRoman(int num)
    {
        vector<int> nums = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> str = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string res;
        int index = 0;
        while(index < 13)
        {
            while(num >= nums[index])
            {
                res += str[index];
                num -= nums[index];
            }
            index++;
        }
        return res;
    }
};
```