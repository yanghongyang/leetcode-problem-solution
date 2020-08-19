/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-19 10:50:38
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-19 11:29:51
 */
/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution
{
public:
    /*     int countSubstrings(string s)
    {
        //长度为n的字符串会生成2n-1组回文中心[li, ri]。
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < 2 * n - 1; i++)
        {
            int l = i / 2;
            int r = i / 2 + i % 2;
            while (l >= 0 && r < n && s[l] == s[r])
            {
                l--;
                r++;
                ans++;
            }
        }
        return ans;
    } */
    int countSubstrings(string s)
    {
        int n = s.size();
        string t = "$#";
        for (const char &c : s) //Manacher算法的初始化
        {
            t += c;
            t += '#';
        }
        n = t.size();
        t += '!'; //将偶数长度字符串转化为奇数长度字符串
        auto f = vector<int>(n);
        int iMax = 0; //当前中心
        int rMax = 0; //当前的右边界
        int ans = 0;  //返回值
        for (int i = 1; i < n; i++)
        {
            //初始化f[i]
            f[i] = (i <= rMax) ? min(rMax - i + 1, f[2 * iMax - i]) : 1; //计算f数组值（利用对称性）
            //向两边左右延伸，中心扩展
            //必须写++f[i]不然leetcode会RE
            while (t[i + f[i]] == t[i - f[i]])
                ++f[i];
            //动态维护中心和右边界
            //如果回文子串的右边界超过了rMax,则需要更新rMax和iMax的值
            if (i + f[i] - 1 > rMax)
            {
                iMax = i;
                rMax = i + f[i] - 1;
            }
            //统计答案，当前贡献为(f[i] - 1) / 2向上取整，也就是f[i] / 2
            ans += (f[i] / 2);
        }
        return ans;
    }
};
// @lc code=end
