<!--
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2021-01-10 16:50:56
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2021-01-10 17:13:13
-->

#### 解题思路
- 双指针

#### 题目分析
本题最容易想到的解法便是 **双指针** 解法了。因为涉及到 `nums` 的连续子区间，所以固定左指针为区间的左端点，右指针进行滑动来寻找区间的右端点。

对于这个解法有两种类似的实现。

#### 代码
1. 粗糙版

```cpp []
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size() <= 0)
            return ans;
        int left = nums[0], right = nums[0]; 
        int n = nums.size();
        int i;
        for(i = 1; i < n; i++)
        {
            if(nums[i] == nums[i - 1] + 1)
            {
                right = nums[i];
            }
            else 
            {
                if(left == right)
                    ans.push_back(to_string(left));
                else 
                {
                    string s = to_string(left) + "->" + to_string(right);
                    ans.push_back(s);
                }
                left = right = nums[i];
            }
        }
        if(left == right)
            ans.push_back(to_string(left));
        else 
        {
            string s = to_string(left) + "->" + to_string(right);
            ans.push_back(s);
        }
        return ans;
    }
};
```
上述代码需要考虑向量最后一个汇总区间的情况。因此比较容易出错。

2. 优雅版（抄自外网）

```cpp []
class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> res;
        for (int i = 0; i < nums.size(); i++)
        {
            int pre = nums[i];
            while (i + 1 < nums.size() && nums[i + 1] == nums[i] + 1)
                i++;
            if (pre == nums[i])
                res.push_back(to_string(pre));
            else
            {
                res.push_back(to_string(pre) + "->" + to_string(nums[i]));
            }
        }
        return res;
    }
};
```
第 `2` 版代码以每一次循环的 `i` 为左端点，同时将 `i` 作为右指针进行滑动，十分简洁，代码值得借鉴和学习。

上述两种代码，由于均只做了一次遍历，因此时间复杂度均为 $O(N)$ ， 空间复杂度为 $O(1)$ （除了返回的答案之外只使用了常数辅助空间）。

#### 后记
题目还是比较简单的，但是通过这道题可以得到一个教训，那就是在 **使用双指针解法时，需要认真考虑端点的情况** 。拿本题而言，容易把右指针指向向量尾的情况给忽略掉。