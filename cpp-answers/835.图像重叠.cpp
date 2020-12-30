/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-12-30 08:58:11
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-12-30 09:39:19
 */
/*
 * @lc app=leetcode.cn id=835 lang=cpp
 *
 * [835] 图像重叠
 */

// @lc code=start
class Solution
{
public:
    //可能和图像处理有些关系？统计img1和img2中出现1时的距离向量disvec，最后遍历disvec取其次数最多的，即为答案
    int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2)
    {
        int n = img1.size();
        vector<vector<int>> disvec(2 * n + 1, vector<int>(2 * n + 1, 0)); //距离向量
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (img1[i][j] == 1)
                {
                    for (int k = 0; k < n; k++)
                    {
                        for (int z = 0; z < n; z++)
                        {
                            if (img2[k][z] == 1)
                            {
                                disvec[k - i + n][z - j + n]++;
                            }
                        }
                    }
                }
            }
        }
        for (auto &vec : disvec)
        {
            for (auto &value : vec)
            {
                res = max(res, value);
            }
        }
        return res;
    }
};
// @lc code=end
