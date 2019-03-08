#include <iostream>

using namespace std;
int inverse_count=0;
void merge(int *arr,int l,int r,int m)
{

    int l1=m-l+1;
    int l2=r-m;
    //两个中专数组，arr作为结果数组
    int*a_l=new int[l1];
    int *a_r=new int[l2];
    for(int i=0;i<l1;i++)
    {
        a_l[i]=arr[i+l];
    }
    for(int j=0;j<l2;j++)
    {
        a_r[j]=arr[j+m+1];//注意，第二个数组是从mid+1开始的；
    }
    int i=0,j=0;
    while (i<l1&&j<l2)
    {
        if(a_l[i]<a_r[j])
        {
            arr[l]=a_l[i];
            l++;
            i++;
        }
        else
        {
            arr[l]=a_r[j];
            l++;
            j++;
            //因为l2[j]大于l1[i],所以l2[j]肯定大于[0,length-1]之中[0,i]之间的所有数，产生逆序对
            if (a_r[j] > a_l[i])
            {
                inverse_count +=  l1-i+1;
            }
        }
    }

    while (i<l1)
    {
        arr[l]=a_l[i];
        l++;
        i++;
    }
    while (j<l2)
    {
        arr[l]=a_r[j];
        l++;
        j++;
    }
    delete []a_l;
    delete []a_r;
    return;
}

void mergeSort(int *arr,int start,int end)
{

    if(start<end)
    {
        int mid=(start+end)/2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,start,end,mid);
    }


}

int main() {
    int a[]={4,6,8,5,9};
    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    mergeSort(a,0,4);
    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<" ";
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
/*
 * output:
 * 4 6 8 5 9
 * 4 5 6 8 9
 */