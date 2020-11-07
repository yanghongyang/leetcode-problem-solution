/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-07 17:30:48
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-07 17:43:25
 */
#include <bits/stdc++.h>
#define d(x) cout << (x) << endl
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 20;

vector<string> st;
//set<string> st;
int len;
char a[N];
char stk[N];

void dfs(int in, int out, string str) //in代表几个字符进过栈了
{                                     //out代表现在栈里还有几个字符
    if (in == len && out == 0)
    { //str代表当前出栈字符串
        //st.insert(str);
        st.push_back(str);
        return;
    }
    if (in < len)
    {
        char c = stk[out];
        stk[out] = a[in];
        dfs(in + 1, out + 1, str);
        stk[out] = c; //回溯
    }
    if (out > 0)
    {
        string str1 = str + stk[out - 1];
        dfs(in, out - 1, str1);
    }
}

int main()
{
    scanf("%s", a);
    len = strlen(a);
    dfs(0, 0, "");
    //cout << st.size() << endl;
    int cnt = 0;
    for (auto x : st)
    {
        if (x == "MAMAMIAM")
            cnt++;
        //printf("%s\n", x.c_str());
    }
    cout << cnt << endl;
    return 0;
}
