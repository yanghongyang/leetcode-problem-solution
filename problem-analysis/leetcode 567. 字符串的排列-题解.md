### 考点
- 双指针

### 思路（朴素）
本题要求在 `s2` 中是否包含 `s1` 的排列，“排列”意味着 `s1` 中字母的顺序可以任意排列，那么本题实际上转化为判断 `s2` 中是否存在子区间，使得子区间中元素出现的次数恰好等于 `s1` 中元素出现的次数。

**代码1**
``` cpp []
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int len1 = s1.size();
        int len2 = s2.size();
        int left = 0, right = len1 - 1; //在s2中的左右指针
        unordered_map<char, int> cnt1;  //用于记录s1中字母出现的次数
        for (int i = 0; i < len1; i++)
        {
            cnt1[s1[i] - 'a']++;
        }
        while (right < len2) //开始滑动
        {
            unordered_map<char, int> tmp(cnt1); //复制构造
            for (int i = left; i <= right; i++)
            {
                tmp[s2[i] - 'a']--;
            }
            bool flag = true;
            for (auto c : tmp)
            {
                if (c.second != 0)
                {
                    flag = false;
                    break;
                }
            }
            if (flag == true)
                return true;
            left++;
            right++;
        }
        return false;
    }
};
```


### 思路（完善高效版）
从 **代码1** 中可以看出，尽管通过了题目，但是其中两个 `unordered_map` 的存在是非常不必要的。首先，因为题目所给出的字符串仅包含 `a` ~ `z` 这 26 个字母，所以只需要用 vector 进行存储即可。

除此之外，由于每一次仅仅往右边滑动一个单位，因此完全不必要每一次都对计数表（cnt1）进行复制。只需要在每一次滑动前，把区间左端点的值对应的计数器值减一，然后再在滑动之后右边界的值所在的计数器上加一，即可。

这里值得注意的是，判断两个 vector 是否相等，如果两个 vector 中所包含的元素为简单类型，则可以直接使用 == 或 != 来进行比较。（除此之外，还可以用 `>=` 、`>` 、`<=` 、 `<` 来比较两个 vector 的大小。）


**代码2**
```cpp []
bool checkInclusion(string s1, string s2)
{
    int len1 = s1.size();
    int len2 = s2.size();
    int left = 0, right = len1 - 1; //在s2中的左右指针
    vector<int> cur(26), goal(26);
    for (char c : s1)
        goal[c - 'a']++;
    for (int i = 0; i < len2; i++)
    {
        cur[s2[i] - 'a']++;
        if (i >= s1.size())
            cur[s2[i - s1.size()] - 'a']--;
        if (goal == cur)
            return true;
    }
    return false;
}
```

时间复杂度： $O(n)$
空间复杂度： $O(1)$ ，这里理解为，尽管开了两个 vector ，但是 vector 中的元素个数都为常数。

### 后记
一开始看到这题的时候，足足愣了好几分钟，甚至想把全排列都给排出来然后一个一个往 `s2` 里模拟。甚至参考别人的思路之后还用了暴力法（代码1）......谁能救救只会无脑暴力的孩子。

除此之外，两个 vector 判等可以直接用等于号，作为基础知识，谨记谨记。