/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-03 17:20:04
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-03 17:22:32
 */
/*
 * @lc app=leetcode.cn id=706 lang=cpp
 *
 * [706] 设计哈希映射
 */

// @lc code=start
class MyHashMap
{
public:
    /** Initialize your data structure here. */
    int mp[1000002];

    MyHashMap()
    {
        memset(mp, -1, 1000002);
    }

    /** value will always be non-negative. */
    void put(int key, int value)
    {
        mp[key] = value;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key)
    {
        return mp[key];
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key)
    {
        mp[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end
