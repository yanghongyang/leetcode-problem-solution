### 考点
- 双指针
- 模拟

### 思路
求最大连续 1 的个数，要求连续，所以最直接想到的方法便是使用左指针和右指针进行滑动和模拟。

控制左指针位置暂时不变，右指针进行滑动，如果 `nums[right] == 1` ，则继续向右滑动；而如果 `nums[right] == 0` ，那说明现在 1 已经不连续了，因此需要更新当前统计的最大连续 1 的个数（ `cnt = max(cnt, right - left + 1)` ），除此之外还需要更新左指针所在的位置（ `left = right + 1` ）。

双指针最容易出错的点在于**边界问题的处理**，本题也不例外。考虑题目所给案例 [1,1,0,1,1,1] ，如果右指针 right 指向最后一个数字为 1 ，则此时也需要更新计数器 `cnt` （ `cnt = max(cnt, right - left)` ）

至于为何为 `right - left + 1` 和 `right - left` ，可以在草稿纸上算一算，很容易发现 `right - left + 1` 是因为当前 `right` 指向的数是 `1` 而不是 `0` ，而 `right - left` 是因为当前 `right` 指向的数是 `0` 而不是 `1` ，因此当前的 `right` 位置是不算进连续 1 的个数里面的。

**代码1（朴素版）**
```cpp []
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int left = 0, right = 0;
        for(right = 0; right < nums.size() && left < nums.size(); right++)
        {
            if(nums[right] == 1)
            {
                if(right < nums.size() - 1)
                    continue;
                else 
                    cnt = max(cnt, right - left + 1);
            }
            else    // if nums[i] == 0
            {
                cnt = max(cnt, right - left);
                left = right + 1;
            }
        }
        return cnt;
    }
};
```

时间复杂度： $O(N)$ ，这里 N 表示 nums 的规模。

空间复杂度： $O(1)$ ，这里理解为仅使用了左右指针和计数器等常数级空间。

**代码1** 仅仅打败了百分之三四十的用户，这意味着一定的改进空间。仔细观察，发现在判断 `nums[right] == 1` 成立的时候，每一次都要判断 `right < nums.size() - 1` ，这无疑消耗了一定的时间，有没有可能不这么写，并且保持正确性呢？

接着发现，当 right 行进到 nums 的右边界时，尽管此时没有办法在 for 循环体内进行 cnt 的更新，但可以在循环体外进行判断。

直接看代码吧，这种一点点的改进使得运行时间提高了一些些。

**代码2**
```cpp []
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int left = 0, right = 0;
        for(right = 0; right < nums.size() && left < nums.size(); right++)
        {
            if(nums[right] == 1)
            {
                continue;
            }
            else    // if nums[i] == 0
            {
                cnt = max(cnt, right - left);
                left = right + 1;
            }
        }
        cnt = max(cnt, right - left);
        return cnt;
    }
};
```

时间复杂度： $O(N)$ ，这里 N 表示 nums 的规模。

空间复杂度： $O(1)$ ，这里理解为仅使用了左右指针和计数器等常数级空间。

### 后记
哈哈哈这题我 8 个月前还不怎么会写呢哈哈哈哈，现在不到 10 分钟就写出来了哈哈哈，有长进有长进~ 心情愉悦~