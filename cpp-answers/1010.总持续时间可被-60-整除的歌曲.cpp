/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-29 21:06:07
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-29 21:15:19
 */
/*
 * @lc app=leetcode.cn id=1010 lang=cpp
 *
 * [1010] 总持续时间可被 60 整除的歌曲
 */

// @lc code=start
class Solution
{
public:
    int numPairsDivisibleBy60(vector<int> &time)
    {
        //暴力方法果然超时了，所以得想想其他的方法
        /*
        int cnt = 0;
        for (int i = 0; i < time.size(); i++)
        {
            for (int j = i + 1; j < time.size(); j++)
            {
                if ((time[i] + time[j]) % 60 == 0)
                    cnt++;
            }
        }
        return cnt;
        */
        int cnt = 0;
        vector<int> tmp(60, 0); //拿一个长度为60的数组进行存储，利用%的性质，如果有(i+j)%60 == 0，则对于x来讲，如果x%60=a，则y%60=60-a。
        for (int i = 0; i < time.size(); i++)
        {
            int t = time[i] % 60;
            if (t == 0) //如果本身就可以被60整除，需要单独处理
                cnt += tmp[0];
            else
                cnt += tmp[60 - t];
            tmp[t]++; //更新tmp数组
        }
        return cnt;
    }
};
// @lc code=end
