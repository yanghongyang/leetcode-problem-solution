/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-27 17:06:12
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-27 17:09:02
 */
/*
 * @lc app=leetcode.cn id=1496 lang=cpp
 *
 * [1496] 判断路径是否相交
 */

// @lc code=start
class Solution
{
public:
    bool isPathCrossing(string path)
    {
        set<pair<int, int>> st;
        int xx = 0, yy = 0;
        st.insert({xx, yy});
        for (int i = 0; i < path.size(); i++)
        {
            if (path[i] == 'N')
            {
                yy++;
            }
            else if (path[i] == 'S')
            {
                yy--;
            }
            else if (path[i] == 'E')
            {
                xx++;
            }
            else
            {
                xx--;
            }
            pair<int, int> tmp = {xx, yy};
            if (st.find(tmp) != st.end())
                return true;
            else
                st.insert(tmp);
        }
        return false;
    }
};
// @lc code=end
