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
/*     vector<string> restoreIpAddresses(string s) {
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
    } */
    //讲道理！！！这道题给的字符串长度应该不会特别长，因为要返回的是所有可能的IP地址格式
    //那么！用暴力法也是可以考虑的！！！
    //整个字符串应该被合理地分成4个部分，那么只要穷举每个部分然后判断是否合理就可以啦！
    bool valid(string s)
    {
        //0~255意味着不超过3位
        if(s.size() <= 0 || s.size() > 3)
            return false;
        //除此之外s不能以0为开头
        if(s[0] == '0' && s.size() > 1)
            return false;
        //计算数的大小
        int result = 0;
        for(int i = 0; i < s.size(); i++)
        {
            result = result * 10 + s[i] - '0';
        }
        return (result >= 0 && result <= 255);
    }
    vector<string> restoreIpAddresses(string s) 
    {
        int n = s.size(); 
        vector<string> res;
        if(n > 12 || n < 4) //肯定不可能分成4个合理的部分
            return {};
        for(int i = 1; i < n; i++)
        {
            string a = s.substr(0, i);  //第一部分
            if(valid(a))
            {
                for(int j = i + 1; j < n; j++)
                {
                    string b = s.substr(i, j - i);
                    if(valid(b))
                    {
                        for(int k = j + 1; k < n; k++)
                        {
                            string c = s.substr(j, k - j);
                            string d = s.substr(k, n - k);
                            if(valid(c) && valid(d))
                            {
                                res.push_back(a + '.' + b + '.' + c + '.' + d);
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

