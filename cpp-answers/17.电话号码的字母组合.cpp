/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    //考察的是回溯，可以用递归解决，也可以使用队列
    //首先是递归方法
    /*
    vector<string> letter = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty())
            return res;
        string tmp = "";
        dfs(digits, 0, tmp, res, letter);
        return res;
    }
    void dfs(string digits, int pos, string& path, vector<string>& res, vector<string>& letter)
    {
        if(pos == digits.size())
        {
            res.push_back(path);
            return ;
        }
        for(auto c : letter[digits[pos] - '0'])
        {
            path.push_back(c);
            dfs(digits, pos + 1, path, res, letter);
            path.pop_back();
        }
    }*/
    //队列
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        map<char, string> m = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};   //映射map哈希表
        int n = digits.size(); 
        queue<string> que;  //队列
        //将第一个数字对应的字母入队
        for(int i = 0; i < m[digits[0]].size(); i++)
        {
            string str;
            str.push_back(m[digits[0]][i]);
            que.push(str);  //string入队
        }
        string s;   //用于存储队头
        for(int i = 1; i < n; i++)
        {
            int length = que.size();    //当前队列长度
            while(length--)
            {
                for(int j = 0; j < m[digits[i]].size(); j++)
                {
                    s = que.front();
                    s = s + m[digits[i]][j];//  队头加上新元素
                    que.push(s);    //入队
                }
                que.pop();
            }
        }
        while(!que.empty())
        {
            res.push_back(que.front()); //队头元素存储至res
            que.pop();  //队头出队
        }
        return res;
    }
};
// @lc code=end

