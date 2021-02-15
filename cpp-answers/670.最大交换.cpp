/*
 * @lc app=leetcode.cn id=670 lang=cpp
 *
 * [670] 最大交换
 */

// @lc code=start
class Solution
{
public:
    int maximumSwap(int num)
    {
        vector<int> ans;
        int tmp = num;
        while (tmp > 0) //处理数字，变成字符串
        {
            int t = tmp % 10;
            ans.push_back(t);
            tmp /= 10;
        }
        int cnt = 0; //记录交换次数的
        int maxn = 0;
        int posn = 0;
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            if (cnt == 1)
                break;
            maxn = ans[i];
            posn = i;
            for (int j = i - 1; j >= 0; j--)
            {
                if (maxn <= ans[j]) //找到了最大值和最大值所在的位置
                {
                    maxn = max(maxn, ans[j]);
                    posn = j;
                }
            }
            if (maxn != ans[i])
            {
                swap(ans[i], ans[posn]);
                cnt++;
            }
        }
        long long res = 0;
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            res += ans[i];
            res *= 10;
        }
        res /= 10;
        return res;
    }
};
// @lc code=end
