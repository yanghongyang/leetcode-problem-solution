/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-29 22:16:26
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-29 22:37:35
 */
/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start

class Solution
{
public:
    //快速排序的改进算法：
    /*
        在分解的过程中，对子数组进行划分，如果划分得到的q正好是所需要的下标，则直接返回a[q]；
        否则，如果q比目标下标小，就递归右子区间，否则递归左子区间。
        这样可以把原来递归两个区间变成只递归一个区间，提高时间效率。
        引入随机化来加速过程，使得时间代价的期望为O(n)
    */
    /*
    int quickSelect(vector<int> &a, int l, int r, int index) //实现优化
    {
        int q = randomPartition(a, l, r);
        if (q == index)
        {
            return a[q];
        }
        else
        {
            return q < index ? quickSelect(a, q + 1, r, index) : quickSelect(a, l, q - 1, index);
        }
    }
    inline int randomPartition(vector<int> &a, int l, int r)
    {
        int i = rand() % (r - l + 1) + l; //随机化
        swap(a[i], a[r]);
        return partition(a, l, r);
    }
    inline int partition(vector<int> &a, int l, int r) //划分
    {
        int x = a[r];
        int i = l - 1;
        for (int j = l; j < r; j++)
        {
            if (a[j] <= x)
                swap(a[++i], a[j]);
        }
        swap(a[i + 1], a[r]);
        return i + 1;
    }
    int findKthLargest(vector<int> &nums, int k)
    {
        srand(time(0));
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
    */
    //基于堆排序的选择方法
    void maxHeapify(vector<int> &a, int i, int heapSize)
    {
        int l = i * 2 + 1, r = i * 2 + 2;
        int largest = i;
        if (l < heapSize && a[l] > a[largest])
            largest = l;
        if (r < heapSize && a[r] > a[largest])
            largest = r;
        if (largest != i)
        {
            swap(a[i], a[largest]);
            maxHeapify(a, largest, heapSize);
        }
    }

    void buildMaxHeap(vector<int> &a, int heapSize)
    {
        for (int i = heapSize / 2; i >= 0; i--)
        {
            maxHeapify(a, i, heapSize);
        }
    }

    int findKthLargest(vector<int> &nums, int k)
    {
        int heapSize = nums.size();
        buildMaxHeap(nums, heapSize);
        for (int i = nums.size() - 1; i >= nums.size() - k + 1; i--)
        {
            swap(nums[0], nums[i]);
            heapSize--;
            maxHeapify(nums, 0, heapSize);
        }
        return nums[0];
    }
};

// @lc code=end
