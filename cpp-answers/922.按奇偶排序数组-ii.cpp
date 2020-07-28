/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-25 08:53:11
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-25 09:01:26
 */
/*
 * @lc app=leetcode.cn id=922 lang=cpp
 *
 * [922] 按奇偶排序数组 II
 */

// @lc code=start
class Solution
{
public:
    /* vector<int> sortArrayByParityII(vector<int> &A)
    {
        int oddIndex = 1, evenIndex = 0;
        vector<int> res(A.size());
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] % 2 == 0)
            {
                res[evenIndex] = A[i];
                evenIndex += 2;
            }
            else
            {
                res[oddIndex] = A[i];
                oddIndex += 2;
            }
        }
        return res;
    } */
    vector<int> sortArrayByParityII(vector<int> &A)
    {
        int startp = 0, endp = A.size() - 1;
        while (startp < A.size() && endp >= 0)
        {
            if (A[startp] % 2 == 1 && startp % 2 == 0)
            {
                while (endp)
                {
                    if (A[endp] % 2 == 0 && endp % 2 == 1)
                    {
                        break;
                    }
                    else
                    {
                        endp--;
                    }
                }
                int tmp = A[startp];
                A[startp] = A[endp];
                A[endp] = tmp;
            }
            else
            {
                startp++;
            }
        }
        return A;
    }
};
// @lc code=end
