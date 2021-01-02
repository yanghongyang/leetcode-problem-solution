/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2021-01-01 19:50:41
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2021-01-02 19:37:26
 */
/*
 * @lc app=leetcode.cn id=1419 lang=cpp
 *
 * [1419] 数青蛙
 */

// @lc code=start
class Solution
{
public:
    int minNumberOfFrogs(string croakOfFrogs)
    {
        int c = 0, r = 0, o = 0, a = 0, k = 0; //初始化，每个变量表示其代表的字母出现的个数
        int ans = 0;
        bool flag = true; //判断是否构成青蛙叫
        for (int i = 0; i < croakOfFrogs.size(); i++)
        {
            if (croakOfFrogs[i] == 'c')
                c++;
            else if (croakOfFrogs[i] == 'r')
                r++;
            else if (croakOfFrogs[i] == 'o')
                o++;
            else if (croakOfFrogs[i] == 'a')
                a++;
            if (croakOfFrogs[i] == 'k') //这个时候应该注意了，出现k意味着有个青蛙叫完了，同时也可以判断出，到底之前有多少个青蛙同时在叫（统计k之前c的个数）
            {
                k++; //k的个数+1
                ans = max(ans, c);
                if (c >= r && r >= o && o >= a && a >= k) //如果确实是个青蛙叫
                {
                    c--;
                    r--;
                    o--;
                    a--;
                    k--;
                }
            }
            //如果不构成青蛙叫，那就直接跳出并且返回-1
            if (!(c >= r && r >= o && o >= a && a >= k))
            {
                flag = false;
                break;
            }
        }
        if (!flag || (c != 0 || r != 0 || o != 0 || a != 0 || k != 0)) //不构成青蛙叫的情况，一种是五个字母没构成顺序（flag = false），另一种是遍历到最后某个字母多了
        {
            return -1;
        }
        return ans;
    }
};
// @lc code=end
