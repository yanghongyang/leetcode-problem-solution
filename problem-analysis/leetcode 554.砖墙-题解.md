<!--
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2021-01-04 11:52:18
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2021-01-04 13:47:54
-->

#### 考点
- 贪心
- 哈希

#### 题目分析
题目要求穿过的砖块数目最少，因此可以换一个角度思考。只需要尽可能多地不穿过砖块即可。只要能尽可能多地穿过 **砖块的缝隙** ，就可以达到要求。

第 `i` 层第 `j` 块砖块（ `wall[i][j]` ）的缝隙值，为在第 `i` 层已经加了前 `j -1` 个砖块的情况下，再加上第 `wall[i][j]` 长度的值。 那么可以使用哈希表记录每一层砖块总长度，接着再遍历一遍，取其中的最大值，即可以穿过砖块数目最少。记此时的最大值为 `ans` 。总共有 `n` 层，则最多穿过 `n` 个砖块，因此最后答案为 `n-ans` 。

除此之外，注意边界问题的处理，即在统计砖块总长度的时候，不需要包括最后一个砖块。

#### 代码
```cpp []
class Solution
{
public:
    int leastBricks(vector<vector<int>> &wall)
    {
        unordered_map<int, int> mp;
        int n = wall.size();
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = 0; j < wall[i].size() - 1; j++)
            {
                sum += wall[i][j];
                mp[sum]++;
            }
        }
        int ans = 0;
        for (auto m : mp)
        {
            if (m.second > ans)
                ans = m.second;
        }
        return n - ans;
    }
};
```

#### 后记
这道题让我想起了本科时候做过的某道 `OJ` 题。（好像是 `easy` 难度来着？）