/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-24 19:41:17
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-24 20:15:38
 */
/*
 * @lc app=leetcode.cn id=457 lang=cpp
 *
 * [457] 环形数组循环
 */

// @lc code=start
class Solution
{
public:
    //本题的思路有三步：
    //1. 判断是否相同方向
    //2. 在方向相同的情况下，判断是否出现了环
    //3. 在出现环的时候，判断环的长度是否大于1

    //第一步，判断nums[i]和nums[j]是否是相同方向
    bool sameDir(vector<int> &nums, int i, int j)
    {
        if ((nums[i] > 0 && nums[j] > 0) || (nums[i] < 0 && nums[j] < 0))
            return true;
        return false;
    }
    //第二步，判断是否出现了环
    //这一步的实现可以借鉴链表中判断环的方法，即快慢指针
    //但是在实现之前需要先确定快指针的位置，也就是当前位置的下一个位置是多少
    int next(int i, vector<int> &nums) //i是当前元素的位置
    {
        int n = nums.size();
        int loc = ((i + nums[i]) % n + n) % n; //因为nums[i]可能是负的，所以在(i+nums[i])%n之后需要再加一个n，此时为了防止上溢出，还需要再取余
        return loc;
    }

    bool circularArrayLoop(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 0)
            return false;
        for (int i = 0; i < n; i++)
        {
            int slow = i, fast = i;
            while (sameDir(nums, slow, next(fast, nums)) && sameDir(nums, slow, next(next(fast, nums), nums)))
            {
                slow = next(slow, nums);
                fast = next(next(fast, nums), nums);
                if (slow == fast)
                {
                    //如果找到了循环，则执行第三步
                    if (slow == next(slow, nums)) //这说明环的长度只有1，因此不算
                    {
                        break;
                    }
                    return true;
                }
            }
            //如果没有找到循环，那么咋办呢？
            //不咋办...
            //应该是可以剪枝的，但我怎么剪枝都RE...唉就这样吧
        }
        return false;
    }
};
// @lc code=end
