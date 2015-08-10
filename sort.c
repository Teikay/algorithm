#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b);

//1 冒泡排序
//冒泡排序是非常容易理解和实现，，以从小到大排序举例：
//设数组长度为N。
//1．比较相邻的前后二个数据，如果前面数据大于后面的数据，就将二个数据交换。
//2．这样对数组的第0个数据到N-1个数据进行一次遍历后，最大的一个数据就“沉”到数组第N-1个位置。
//3．N=N-1，如果N不为0就重复前面二步，否则排序完成。
//
void bubbleSort(int a[], int n)
{
    int i,j;
    if(n < 2)
        return;

    for(i = 0; i < n; i++)
        for(j = 1; j < n-i; j++)
            if(a[j-1] > a[j])
                swap(&a[j-1], &a[j]);
    return;
}

//2 直接插入排序
//直接插入排序(Insertion Sort)的基本思想是：每次将一个待排序的记录，
//按其关键字大小插入到前面已经排好序的子序列中的适当位置，直到全部记录插入完成为止。
//
void insertSort(int a[], int n)
{
    int i,j;
    if(n < 2)
        return;

    for(i = 1; i < n; i++)
        for(j = i - 1; j >= 0 && a[j] > a[j+1]; j--)
            swap(&a[j], &a[j+1]);
    return;
}

//3 希尔排序
//尔排序的实质就是分组插入排序，该方法又称缩小增量排序，因DL．Shell于1959年提出而得名。
// 该方法的基本思想是：先将整个待排元素序列分割成若干个子序列（由相隔某个“增量”的元素组成的）分别进行直接插入排序，
// 然后依次缩减增量再进行排序，待整个序列中的元素基本有序（增量足够小）时，再对全体元素进行一次直接插入排序。
// 因为直接插入排序在元素基本有序的情况下（接近最好情况），效率是很高的，因此希尔排序在时间效率上比前两种方法有较大提高。
//
void shellSort(int a[], int n)
{
    int i,j,gap;
    if(n < 2)
        return;

    for(gap = n / 2; gap > 0; gap /= 2)
        for(i = gap; i < n; i++)
            for(j = i - gap; j >= 0 && a[j] > a[j + gap]; j -= gap)
                swap(&a[j], &a[j+gap]);
    return;
}

//4 归并排序
//归并排序，其的基本思路就是将数组分成二组A，B，如果这二组组内的数据都是有序的，那么就可以很方便的将这二组数据进行排序。
//如何让这二组组内数据有序了？可以将A，B组各自再分成二组。依次类推，当分出来的小组只有一个数据时，
//可以认为这个小组组内已经达到了有序，然后再合并相邻的二个小组就可以了。这样通过先递归的分解数列，再合并数列就完成了归并排序。
//

//将有二个有序数列a[first...mid]和a[mid...last]合并。
void mergeArray(int a[], int first, int mid, int last, int temp[])
{
    int i = first, j = mid + 1;
    int m = mid, n = last;
    int k = 0;
    while(i <= m && j <= n)
    {
        if(a[i] <= a[j])
            temp[k++] = a[i++];
    }

    while(i <= m)
        temp[k++] = a[i++];

    while(j <= n)
        temp[k++] = a[j++];

    for(i=0; i<k; i++)
        a[first + i] = temp[i];
}

void mergeSort(int a[], int first, int last, int temp[])
{
    if(first < last)
    {
        int mid = (first + last) / 2;
        mergeSort(a, first, mid ,temp);
        mergeSort(a, mid + 1, last ,temp);
        mergeArray(a, first, mid, last ,temp);
    }
}

void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *b = *a;
    *a = temp;
    return;
}

