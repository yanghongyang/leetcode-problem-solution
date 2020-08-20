<!--
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-20 11:15:00
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-20 11:20:26
-->
# [题目描述](https://leetcode-cn.com/problems/top-k-frequent-elements)
给定一个非空的整数数组，返回其中出现频率前 ***k*** 高的元素。
```
示例 1:
输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
```
```
示例 2:
输入: nums = [1], k = 1
输出: [1]
```
```
提示：
你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。
你可以按任意顺序返回答案。
```
```
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/top-k-frequent-elements
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

# 考点
- 堆
- 优先队列

# 题目分析
排序算法辣么多，可是题目要求时间复杂度必须优于 $O(n log n)$ , $n$ 是数组的大小。那可用的算法实际上就非常少了。

一种可行的方法是使用堆。

使用 `unordered_map` 对数组中的所有元素出现频次进行统计。接着使用优先队列来建立堆。最后返回队列前 `k` 个元素组成的 `vector` 即可。

# 代码
```cpp
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]]++;
        }
        vector<int> res;
        priority_queue<pair<int, int>> pq;
        //使用优先队列来对map的频次进行排序
        for (auto it = map.begin(); it != map.end(); it++)
        {
            //将map中元素的频次和元素值进行make_pair
            pq.push(make_pair(it->second, it->first));
        }
        for (int i = 0; i < k; i++)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
```