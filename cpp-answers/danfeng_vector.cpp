/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-12-18 16:45:35
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-12-18 16:52:48
 */
#include <iostream>
using namespace std;

int searchK(int A[], int lo, int hi)
{
    int left = lo, right = hi;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (mid == left)
            return left;
        if (mid + 1 == right)
            return mid;
        if (A[mid - 1] < A[mid] && A[mid] > A[mid + 1])
            return mid;
        else if (A[mid - 1] < A[mid] && A[mid] < A[mid + 1]) //A[mid]和左右按升序
            left = mid;
        else if (A[mid + 1] < A[mid] && A[mid] < A[mid - 1]) //A[mid]和左右按降序
            right = mid;
    }
}

int main()
{
    int a1[] = {1, 2, 3, 4, 5, 6, 7};
    int a2[] = {7, 6, 5, 4, 3, 2, 1};
    int a3[] = {1, 2, 3, 4, 7, 6, 5, 4};
    int k1 = searchK(a1, 0, 7);
    cout << "k1=" << k1 << endl;
    int k2 = searchK(a2, 0, 7);
    cout << "k2=" << k2 << endl;
    int k3 = searchK(a3, 0, 7);
    cout << "k3=" << k3 << endl;
    return 0;
}
