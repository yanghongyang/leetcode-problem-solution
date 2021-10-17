### 题目描述

给你一个 **正** 整数 `num` ，输出它的补数。补数是对该数的二进制表示取反。

**示例 1**

```
输入：num = 5
输出：2
解释：5 的二进制表示为 101（没有前导零位），其补数为 010。所以你需要输出 2 。
```

**示例 2**

```
输入：num = 1
输出：0
解释：1 的二进制表示为 1（没有前导零位），其补数为 0。所以你需要输出 0 。
```

**提示**

- 给定的整数 num 保证在 32 位带符号整数的范围内。
- $num >= 1$
- 你可以假定二进制数不包含前导零位。
- 本题与 1009 https://leetcode-cn.com/problems/complement-of-base-10-integer/ 相同

> 来源：力扣（LeetCode）
> 链接：https://leetcode-cn.com/problems/number-complement
> 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

### 解题思路

既然二进制数不包含前导 0 ，那只需要找到这个数的二进制表示中最高位的 `1` 所在的位置，然后构造从该位开始到最末位都为 `1` 的数字（掩码） `mask`，然后和原来的 `num` 异或就好啦。

但是在找最高位为 `1` 的位置的时候，需要注意一下溢出问题。即最高位只能到第 `31` 位（有符号数），所以如果这个时候直接让掩码 `mask` 等于 `0x7fffffff` 就行了。

代码 `1` ：

```Java
class Solution {
    public int findComplement(int num) {
        // 找到最高位的 1 ，然后构造从该位开始到最低位的数字全部都为 1 的数，之后和 num 进行异或
        int highbit = 0;
        for(int i = 0; i <= 30; i++) {
            if((1 << i) > num) {
                highbit = i;
                break;
            }
        }
        int mask = (1 << (highbit)) - 1;
        if(highbit == 0 && num != 1) {
            mask = 0x7fffffff;
        }

        return mask ^ num;
    }
}
```

当然求掩码 `mask` 的方法也还有很多种......

代码 `2` ：

```java
class Solution {
    public int findComplement(int num) {
        int mask = 1;
        while(mask < num) {
            mask = mask << 1;
            mask += 1;
        }
        return mask ^ num;
    }
}
```

时间复杂度：$O(1)$

空间复杂度：$O(1)$

