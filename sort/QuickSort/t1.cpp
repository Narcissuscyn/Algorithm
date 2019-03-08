//
//基础版本
// Created by Narcissus Chen on 2019-03-08.
//

void swap(int *a,int i,int j)
{
    int temp=a[j];
    a[j]=a[i];
    a[i]=temp;
}

void quickSort(int *a,int left,int right)
{
    if(left<right)
    {
        int i=left,j=right-1,base=right;
        while (i<j)
        {
            while(a[i]<a[base])i++;//// 从左向右找第一个大于等于x的数
            while (a[j]>=a[base])j--;//从右向左找第一个小于x的数
            if(i<j) {
                swap(a, i, j);
            }
        }
        if(a[i]>a[base])swap(a,i,base);
        quickSort(a,left,i-1);
        quickSort(a,i+1,right);
    }
}