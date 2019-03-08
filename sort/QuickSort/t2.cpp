//
// Created by Narcissus Chen on 2019-03-08.
//

//1.第k大的数字
//int partition(int *arr,int left,int right)
//{
//    int base=arr[left];
//
//    int i=left+1,j=right;
//
//    while(i<j)
//    {
//        while(arr[i]<=base)
//        {
//            i++;
//        }
//
//        while(arr[j]>base)
//        {
//            j--;
//        }
//        if(i<j)
//        {
//            swap(arr[i],arr[j]);
//        }
//    }
//    if(arr[j]<arr[left])
//        swap(arr[left],arr[j]);
//    return j;
//}
//
//int qsort_k(int * arr,int left,int right,int k)
//{
//    if(left>=right)return arr[left];
//    int mid=partition(arr,left,right);
//    if(k==mid+1)return arr[mid];
//    else if(k>mid)
//    {
//        return qsort_k(arr,mid+1,right,k);
//    }
//    else
//    {
//        return qsort_k(arr,left,mid-1,k);
//    }
//}