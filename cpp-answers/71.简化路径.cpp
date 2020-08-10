/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        stringstream is(path);
        vector<string> str;
        string res = "";
        string tmp = "";
        while(getline(is, tmp, '/'))    //不停读取，并以‘/’作分隔符，将分隔到的字符串存到tmp中
        {
            if(tmp == "" || tmp == ".")
            {
                continue;   
            }
            else if(tmp == ".." && !str.empty())    //如果栈不为空，并且此时的分隔字符串tmp是".."，就需要出栈
            {
                str.pop_back();
            }
            else if(tmp != "..")    //如果分隔字符串是其他的内容，就说明是目录名，此时需要压栈
            {
                str.push_back(tmp);
            }
        }
        for(string s : str)
        {
            res += "/" + s;
        }
        if(res.empty())
        {
            return "/";
        }
        return res;
    }
};
// @lc code=end

