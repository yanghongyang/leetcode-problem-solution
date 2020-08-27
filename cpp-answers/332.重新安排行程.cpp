/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
class Solution
{
public:
    //应该是个欧拉环路吧。
    map<string, multiset<string>> targets;
    vector<string> route;

    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        for (auto ticket : tickets)
            targets[ticket[0]].insert(ticket[1]);
        visit("JFK");
        return vector<string>(route.rbegin(), route.rend());
    }

    void visit(string airport)
    {
        while (targets[airport].size())
        {
            string next = *targets[airport].begin();
            targets[airport].erase(targets[airport].begin());
            visit(next);
        }
        route.push_back(airport);
    }
};
// @lc code=end
