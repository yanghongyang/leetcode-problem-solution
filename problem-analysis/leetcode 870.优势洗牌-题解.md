<!--
 * @Description: 
 * 
 * @Author: Hongyang_Yang
 * @Date: 2021-01-03 20:37:01
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2021-01-03 20:59:26
-->
#### 考点
1. 二分查找
2. 贪心
3. 基本数据结构的使用（vector、multiset）
#### 思路
使用贪心策略，先对 `A` 进行排序，再对 `B` 中的每个元素进行遍历，对于 `B[i]` ，在 `A` 中找到第一个比 `B[i]` 大的元素，存放在 `ans` 中。而如果没有找到第一个比 `B[i]` 大的元素，就把 `A` 中最小的元素存放在 `ans` 中。

为了防止 `A` 中同一个元素被存放在 `ans` 中多次，每次查找成功时，都删掉 `A` 中那个比 `B[i]` 大的元素。

#### 代码（使用 vector ）
```cpp []
class Solution
{
public:
    vector<int> advantageCount(vector<int> &A, vector<int> &B)
    {
        vector<int> ans;
        sort(A.begin(), A.end());
        for (int i = 0; i < B.size(); i++)
        {
            auto iter = upper_bound(A.begin(), A.end(), B[i]);
            if (iter != A.end())
            {
                ans.push_back(*iter);
                A.erase(iter);
            }
            else //如果没找到优势对，则只能将tA中最小的数进行匹配
            {
                ans.push_back(A[0]);
                A.erase(A.begin());
            }
        }
        return ans;
    }
};
```

这种朴素的方法会非常耗时。原因在于我们在删除 `A` 中元素时，由于 `A` 是一个 `vector` ，因此在调用 `vector` 中的 `erase` 方法时，由于 `erase()` 方法时间复杂度为 `O(n)` ，因此消耗了大量时间。

一种改进策略为，使用 `multiset` 将 `vector<int>& A` 中的元素进行拷贝（得到 `mA`，然后再对 `mA` 进行排序和删除。大体思路和使用 `vector` 的思路一致，但由于 `multiset` 的删除操作仅需要 `O(logn)` 时间，因此大大提高了时间效率。

#### 代码（使用 multiset ）
```cpp []
vector<int> advantageCount(vector<int> &A, vector<int> &B)
{
    vector<int> ans;
    if (A.size() != B.size() || A.size() <= 0 || B.size() <= 0)
        return ans;
    multiset<int> mA(A.begin(), A.end());
    for (int i = 0; i < B.size(); i++)
    {
        auto iter = mA.upper_bound(B[i]);
        if (iter != mA.end())
        {
            ans.push_back(*iter);
            mA.erase(iter);
        }
        else //如果没找到优势对，则只能将tA中最小的数进行匹配
        {
            ans.push_back(*mA.begin());
            mA.erase(mA.begin());
        }
    }
    return ans;
}
```

#### 后记
本题还有双指针解法，但没有仔细想。