/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-27 23:46:15
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-27 23:52:12
 */
/*
 * @lc app=leetcode.cn id=705 lang=cpp
 *
 * [705] 设计哈希集合
 */

// @lc code=start
class MyHashSet
{
public:
    vector<vector<int> *> set;
    const int size = 500;
    /** Initialize your data structure here. */
    MyHashSet()
    {
        set.resize(size);
    }

    void add(int key)
    {
        const int index = key % size;
        if (!contains(key))
        {
            auto v = set[index];
            if (v == nullptr)
            {
                v = new vector<int>;
            }
            v->push_back(key);
            set[index] = v;
        }
    }

    void remove(int key)
    {
        const int index = key % size;
        auto v = set[index];
        if (v == nullptr)
            return;
        for (auto iter = v->begin(); iter != v->end(); iter++)
        {
            if (*iter == key)
            {
                v->erase(iter);
                return;
            }
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        const int index = key % size;
        const auto v = set[index];
        if (v == nullptr)
            return false;
        for (auto e : *v)
        {
            if (e == key)
                return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end
