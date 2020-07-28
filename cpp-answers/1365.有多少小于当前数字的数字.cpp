/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-22 15:51:51
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-22 16:34:12
 */
/*
 * @lc app=leetcode.cn id=1365 lang=cpp
 *
 * [1365] 有多少小于当前数字的数字
 */

// @lc code=start
class Solution
{
public:
    /*vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            int cnt = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                if (j == i)
                    continue;
                if (nums[i] > nums[j])
                    cnt++;
            }
            res.push_back(cnt);
        }
        return res;
    }*/
    //下面这种做法可能是想表达频次数组+前缀和的意思，但是我没看懂
    /*
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        map<int, vector<int>> mp; // [value [indexes]];
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]].push_back(i);
        int cnt = 0;
        for (auto &[val, idx] : mp)
        {
            for (int n : idx)
                nums[n] = cnt;
            cnt += idx.size();
        }
        return nums;
    }*/
    /*
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        vector<int> cnt(101, 0);
        vector<int> vec(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++)
        {
            cnt[nums[i]]++;
        }
        for (int i = 1; i <= 100; i++)
        {
            cnt[i] += cnt[i - 1]; //求前缀和
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i])
                vec[i] = (cnt[nums[i] - 1]);
        }
        return vec;
    }*/
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        vector<int> tmp(nums);
        sort(tmp.begin(), tmp.end());
        int n = nums.size();
        vector<int> res;
        for (auto x : nums)
        {
            if (x == tmp[0])
            {
                res.push_back(0);
                continue;
            }
            int l = 0, r = n - 1;
            while (l < r)
            {
                int mid = l + r + 1 >> 1;
                if (tmp[mid] < x)
                    l = mid;
                else
                    r = mid - 1;
            }
            res.push_back(r + 1);
        }
        return res;
    }
};
// @lc code=end
