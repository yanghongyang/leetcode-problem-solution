/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-28 15:20:14
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-28 17:36:09
 */
/*
 * @lc app=leetcode.cn id=874 lang=cpp
 *
 * [874] 模拟行走机器人
 */

// @lc code=start
class Solution
{
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        int direx[] = {0, 1, 0, -1};
        int direy[] = {1, 0, -1, 0};
        int curx = 0, cury = 0;
        int curdire = 0;
        int comLen = commands.size();
        int ans = 0;
        set<pair<int, int>> obstacleSet;
        for (int i = 0; i < obstacles.size(); i++)
            obstacleSet.insert(make_pair(obstacles[i][0], obstacles[i][1]));

        for (int i = 0; i < comLen; i++)
        {
            if (commands[i] == -1)
            { // -1：向右转 90 度
                curdire = (curdire + 1) % 4;
            }
            else if (commands[i] == -2)
            { // -2：向左转 90 度
                curdire = (curdire + 3) % 4;
            }
            else
            { //  1 <= x <= 9：向前移动 x 个单位长度
                for (int j = 0; j < commands[i]; j++)
                {
                    //试图走出一步，并判断是否遇到了障碍物，
                    int nx = curx + direx[curdire];
                    int ny = cury + direy[curdire];
                    //当前坐标不是障碍点，计算并与存储的最大欧式距离的平方做比较
                    if (obstacleSet.find(make_pair(nx, ny)) == obstacleSet.end())
                    {
                        curx = nx;
                        cury = ny;
                        ans = max(ans, curx * curx + cury * cury);
                    }
                    else
                    {
                        //是障碍点，被挡住了，停留，只能等待下一个指令，那可以跳出当前指令了
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end
