// 归并排序
#include <stdio.h>
#include <iostream>
using namespace std;

void mergeArr (int[], int[], int, int, int);
void mergeSort(int originArr[], int sortArr[], int left, int right)
// 将数组originArr[left..right]归并排序至sortArr[left..right]
{
    if (left==right)  // 如果待排序数组只有一个元素则无需排序
    {
        sortArr[left] = originArr[left];
        return;
    }
    else
    {
        int mid = (left + right) / 2;
        int tempArr[right];
        mergeSort(originArr, tempArr, left, mid);
        mergeSort(originArr, tempArr, mid+1, right);
        mergeArr(tempArr, sortArr, left, mid, right);
    }
}

void mergeArr(int arrTwo[], int arrOne[], int left, int mid, int right)
// 将已经排好序的2个数组arrTwo[left..mid]和arrTwo[mid..right]归并到数组arrOne[left..right]
{
    int a = left, b = mid+1, c = left;
    while (c<=right)
    {
        if (a>mid)
        {
            while (b<=right)
                arrOne[c++] = arrTwo[b++];
            break;
        }
        if (b>right)
        {
            while (a<=mid)
                arrOne[c++] = arrTwo[a++];
            break;
        }
        if (arrTwo[a] < arrTwo[b])
            arrOne[c++] = arrTwo[a++];
        else
            arrOne[c++] = arrTwo[b++];
    }

}

int main()
{
    int a[] = {2,123,4,132,4515,1,1341,-4,413,51};
    int b[9];
    mergeSort(a, b, 0, 9);
    for (int i=0; i<10; i++)
        cout<<b[i]<<" ";
}
