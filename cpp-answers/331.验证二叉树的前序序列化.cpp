/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-31 17:52:31
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-31 18:31:55
 */
/*
 * @lc app=leetcode.cn id=331 lang=cpp
 *
 * [331] 验证二叉树的前序序列化
 */

// @lc code=start
class Solution
{
public:
    //根据官方题解，利用槽位slot的思想，起始状态1个槽位，此后每个节点占用一个槽位（即槽位--）。
    //如果是空节点则槽位数量不增加，如果是非空节点则槽位+2
    //用C++解题的关键在于逗号的分隔
    //算了是在下太菜了...抄答案了:https://leetcode-cn.com/problems/verify-preorder-serialization-of-a-binary-tree/solution/jing-jing-de-bi-ji-331-by-ae2a/
    /*     bool isValidSerialization(string preorder)
    {
        stack<bool> s;
        for (int i = 0; i < preorder.size();)
        {
            if (preorder[i] == ',')
                i++;
            else if (preorder[i] == '#')
            {
                if (s.empty())
                    return i == preorder.size() - 1;
                else
                    s.pop();
                i++;
            }
            else
            {
                while (i < preorder.size() && preorder[i] != ',' && preorder[i] != '#')
                    i++;
                s.push(1);
            }
        }
        return false;
    } */
    //这个解法错了，但是现在不知道怎么错的...怪我太菜喽？好气！
    /*     bool isValidSerialization(string preorder)
    {
        int cnt = 1;
        for (int i = 0; i < preorder.size();)
        {
            if (preorder[i] == ',')
                i++;
            else if (preorder[i] == '#')
            {
                cnt--;
                i++;
            }
            else
            {
                while (i < preorder.size() && preorder[i] != ',' && preorder[i] != '#')
                {
                    i++;
                }
                cnt--;
                cnt += 2;
            }
            if (cnt < 0)
                return false;
        }
        return cnt == 0;
    } */
};
// @lc code=end
