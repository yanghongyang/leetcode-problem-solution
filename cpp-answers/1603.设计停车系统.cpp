/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-10-13 08:25:03
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-10-13 08:27:03
 */
/*
 * @lc app=leetcode.cn id=1603 lang=cpp
 *
 * [1603] 设计停车系统
 */

// @lc code=start
class ParkingSystem
{
public:
    int pos[4];
    ParkingSystem(int big, int medium, int small)
    {
        pos[1] = big;
        pos[2] = medium;
        pos[3] = small;
    }

    bool addCar(int carType)
    {
        return pos[carType]-- > 0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
// @lc code=end
