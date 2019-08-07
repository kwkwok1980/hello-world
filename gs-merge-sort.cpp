//https://practice.geeksforgeeks.org/problems/merge-sort/1
{
// C program for implementation of Merge Sort
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int l, int m, int r);
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("
");
}
// Driver program to test above functions
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
}
/*This is a function problem.You only need to complete the function given below*/
/* The task is to complete merge() which is used
   in below mergeSort() */
/*   l is for left index and r is right index of the
   sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r) {
    if (l < r)   {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
} */
// Merges two subarrays of arr[].  First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    /*
    for (int a=l; a<=r; ++a)
    {
        std::cout << arr[a] << ", ";
    }
    std::cout << std::endl;
    */
    
    int result[r-l+1];
    int i = l;
    int j = m+1;
    int k = 0;
    
    while (i<=m || j<=r)
    {
        if (i<=m && j<=r)
        {
            if (arr[i] < arr[j])
            {
                result[k++] = arr[i++];
            }
            else
            {
                result[k++] = arr[j++];
            }
        }
        else if (i<=m)
        {
            result[k++] = arr[i++];
        }
        else
        {
            result[k++] = arr[j++];
        }
    }
    
    memcpy(arr+l, result, (r-l+1)*sizeof(int));
    
    /*
    for (int a=0; a<r-l+1; ++a)
    {
        std::cout << result[a] << ", ";
    }
    std::cout << std::endl;
    */
    
    /*
    for (int a=l; a<=r; ++a)
    {
        std::cout << arr[a] << ", ";
    }
    std::cout << std::endl;
    std::cout << "-----------------------" << std::endl;
    */    
    
}