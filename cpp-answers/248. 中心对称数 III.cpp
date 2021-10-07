class Solution
{
public:
    char dl[5] = {'0', '1', '6', '8', '9'};
    char dr[5] = {'0', '1', '9', '8', '6'};

    bool compare(string &a, string &b)
    {
        if (a.size() != b.size())
        {
            return a.size() > b.size();
        }
        return a >= b;
    }

    bool checkValid(string &num, string &low, string &high)
    {
        return compare(num, low) && compare(high, num);
    }

    int strobogrammaticInRange(string low, string high)
    {
        int res = 0;
        queue<string> qu;

        /* initial */
        qu.push("");
        qu.push("0");
        qu.push("1");
        qu.push("8");

        /* BFS */
        while (!qu.empty())
        {
            string curr = qu.front();
            qu.pop();

            if (curr.size() >= low.size() && curr.size() <= high.size())
            {
                /* 跳过开头是 0 的数 */
                if (!(curr[0] == '0' && curr.size() > 1))
                {
                    if (checkValid(curr, low, high))
                    {
                        res++;
                    }
                }
            }

            if (curr.size() > high.size())
            {
                continue;
            }

            for (int i = 0; i < 5; i++)
            {
                string next = dl[i] + curr + dr[i];
                if (next.size() <= high.size())
                {
                    qu.push(next);
                }
            }
        }
        return res;
    }
};