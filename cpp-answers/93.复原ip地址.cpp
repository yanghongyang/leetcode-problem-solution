/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 */

// @lc code=start
class Solution {
public:
    //这道题一看就是...回溯法
    //回溯法万岁！
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string ip;
        dfs(s, 0, 0, ip, res);
        return res;
    }
    void dfs(string s, int start, int step, string ip, vector<string>& result)
    {
        if(start == s.size() && step == 4)
        {
            ip.erase(ip.end() - 1); //移掉最后一个'.'
            result.push_back(ip);
            return ;
        }
        if(s.size() - start > (4 - step) * 3)
            return; //这意味着剩下的数字太多了
        if(s.size() - start < (4 - step))
            return; //这意味着剩下的数字太少了
        int num = 0;
        for(int i = start; i < start + 3; i++)  //因为分隔的数字大小在0~255之间，所以顶多3位
        {
            num = num * 10 + (s[i] - '0');
            //如果num在0~255之间的话，继续搜索
            if(num <= 255)
            {
                ip += s[i];
                dfs(s, i + 1, step + 1, ip + '.', result);
            }
            if(num == 0)
                break;
        }
    }
};
// @lc code=end

