#include <iostream>
using namespace std;

int partition(int *arr,int left,int right)
{
    int base=arr[left];

    int index=left+1;
    for(int i=index+1;i<=right;i++)
    {
        if(arr[i]<base)
        {
            swap(arr[i],arr[index]);
            index++;
        }
    }
    swap(arr[left],arr[index-1]);
    return index-1;
}

int qsort_k(int * arr,int left,int right,int k)
{
    if(left>=right)return arr[left];
    int mid=partition(arr,left,right);
    if(k==mid+1)return arr[mid];
    else if(k>mid)
    {
        return qsort_k(arr,mid+1,right,k);
    }
    else
    {
        return qsort_k(arr,left,mid-1,k);
    }
}
int main()
{
    int a[]={6,7,8,5,4,3,2,1};
    for(int i=0;i<8;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<qsort_k(a,0,7,5)<<endl;

    for(int i=0;i<8;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
