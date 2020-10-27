/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-10-27 23:24:38
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-10-27 23:38:58
 */
/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 */

// @lc code=start
//以下代码来自algsCG大佬（链接：https://leetcode-cn.com/problems/fraction-to-recurring-decimal/solution/cmo-ni-ti-jian-dan-yi-dong-by-xiaoneng/）
class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        if (denominator == 0)
            return ""; //边界条件，分母为0
        if (numerator == 0)
            return "0"; //边界条件，分子为0

        string result;

        //转换为long long 防止溢出
        long long num = static_cast<long long>(numerator);
        long long denom = static_cast<long long>(denominator);

        //处理正负号，一正一负取负号
        if ((num > 0) ^ (denom > 0))
            result.push_back('-');

        //分子分母全部转换为正数
        num = llabs(num);
        denom = llabs(denom);

        //处理整数部分
        result.append(to_string(num / denom));

        //处理小数部分
        num %= denom; //获得余数
        if (num == 0)
            return result;                    //余数为0，表示整除，直接返回结果
        result.push_back('.');                //余数不为0，添加小数点
        int index = result.size() - 1;        //获得小数点的下标
        unordered_map<int, int> record;       //map用来记录出现重复数的下标，然后将'('插入到重复数前面就行
        while (num && record.count(num) == 0) //小数部分，余数不为0且余数还没有出现重复数字
        {
            record[num] = ++index;
            num *= 10; //余数扩大10倍，然后求商，和草稿本上运算方法是一样的
            result += to_string(num / denom);
            num %= denom;
        }
        if (record.count(num) == 1) //出现循环余数，直接在重复数字前添加'('，字符串末尾添加')'
        {
            result.insert(record[num], "(");
            result.push_back(')');
        }
        return result;
    }
};
// @lc code=end
