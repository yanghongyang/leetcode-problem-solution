/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-14 20:29:13
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-14 21:00:38
 */
/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 */

// @lc code=start
class NumArray
{
private:
    //线段树
    vector<int> bit_tree;
    vector<int> origin; //记录原始数组，从而能够在update的时候计算出位置i处的值的变化量；bit_tree是该数组的反映

    int low_bit(int x)
    {
        return x & (-x);
    }

    //给定原数据有边界下标值，求其前缀
    int prefixSum(int index)
    {
        index += 1;
        int result = 0;
        while (index > 0)
        {
            result += this->bit_tree[index];
            index -= low_bit(index);
        }
        return result;
    }

public:
    NumArray(vector<int> &nums)
    {
        this->origin.push_back(0);
        this->origin.insert(this->origin.end(), nums.begin(), nums.end());

        this->bit_tree.push_back(0);
        this->bit_tree.insert(this->bit_tree.end(), nums.begin(), nums.end());

        //初始化bit_tree
        //即根据给定的i，更新所有能管到i的右边界
        for (int i = 1; i < this->bit_tree.size(); i++)
        {
            int j = i + low_bit(i);
            if (j < this->bit_tree.size())
            {
                this->bit_tree[j] += this->bit_tree[i];
            }
        }
    }

    //注意此处是将i的下标的值更新为val，而不是在原基础上增加val
    //但原理还是一样的，先求出其变化值
    void update(int i, int val)
    {
        i += 1;
        int dec = val - this->origin[i]; // 注意bit_tree中记录的是区间和，origin记录的才是bit_tree对应的原始数组
        this->origin[i] = val;

        while (i < this->bit_tree.size())
        {
            this->bit_tree[i] += dec;
            i += low_bit(i);
        }
    }

    int sumRange(int i, int j)
    {
        return prefixSum(j) - prefixSum(i - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
// @lc code=end
