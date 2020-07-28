/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-02 07:18:13
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-02 07:30:38
 */
/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第K小的元素
 */

// @lc code=start
class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        //直接排序法
        /*
        vector<int> res;
        for (auto &row : matrix)
        {
            for (int it : row)
            {
                res.push_back(it);
            }
        }
        sort(res.begin(), res.end());
        return res[k - 1];
        */
        //归并排序
        /*
            从这n个有序数组中找到第k大的数
            n个数组归并，需要用小根堆维护，以优化时间复杂度
        */
        struct point
        {
            int val, x, y;
            point(int val, int x, int y) : val(val), x(x), y(y) {}
            bool operator>(const point &a) const { return this->val > a.val; }
        };
        priority_queue<point, vector<point>, greater<point>> que;
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            que.emplace(matrix[i][0], i, 0);
        }
        for (int i = 0; i < k - 1; i++)
        {
            point now = que.top();
            que.pop();
            if (now.y != n - 1)
            {
                que.emplace(matrix[now.x][now.y + 1], now.x, now.y + 1);
            }
        }
        return que.top().val;
    }
};
// @lc code=end
