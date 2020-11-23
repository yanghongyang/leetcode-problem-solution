/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-23 23:31:42
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-23 23:44:38
 */
/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] 常数时间插入、删除和获取随机元素
 */

// @lc code=start
class RandomizedSet
{
public:
    /** Initialize your data structure here. */
    RandomizedSet() : seed((random_device())()) {}

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (related_map.count(val))
            return false;
        related_map[val] = values.size();
        values.emplace_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (!related_map.count(val))
            return false;
        //把数组的最后一个元素拷贝到我们当前想要移除的元素的位置
        values[related_map[val]] = values.back();
        //然后把最后一个元素的位置指向当前的位置
        related_map[values.back()] = related_map[val];

        //移除当前元素
        values.pop_back();
        related_map.erase(val);

        return true;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        return values[uniform_int_distribution<>(0, values.size() - 1)(seed)];
    }

private:
    unordered_map<int, int> related_map; //建立集合元素和位置的映射关系
    vector<int> values;                  //记录集合中的元素
    default_random_engine seed;          //
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
