#include <iostream>
using namespace std;
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

int main()
{
    int a[]={9,8,7,6,5,4,3,2,1};
    for(int i=0;i<9;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    quickSort(a,0,8);

    for(int i=0;i<9;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}