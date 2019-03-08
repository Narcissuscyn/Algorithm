#include <iostream>
using namespace std;
//void swap(int *a,int i,int j)
//{
//    int temp=a[j];
//    a[j]=a[i];
//    a[i]=temp;
//}
//
//void quickSort(int *a,int left,int right)
//{
//    if(left<right)
//    {
//        int i=left,j=right-1,base=right;
//        while (i<j)
//        {
//            while(a[i]<a[base])i++;//// 从左向右找第一个大于等于x的数
//            while (a[j]>=a[base])j--;//从右向左找第一个小于x的数
//            if(i<j) {
//                swap(a, i, j);
//            }
//        }
//        if(a[i]>a[base])swap(a,i,base);
//        quickSort(a,left,i-1);
//        quickSort(a,i+1,right);
//    }
//}

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
//    if(mid<right)
//    {
//        qsort_k(arr,mid+1,right,k);
//    }
//    if(mid>left)
//    {
//        qsort_k(arr,left,mid-1,k);
//    }
//    return arr[k-1];
//}

//

//2.快排+插排
//void insert_sort(int *arr,int left,int right)
//{
//    for(int i=left+1;i<=right;i++)
//    {
//        int j=i-1;
//        int temp=arr[i];
//        while (j>=0&&temp<arr[j])
//        {
//            arr[j+1]=arr[j];
//            j--;
//        }
//        arr[j+1]=temp;
//    }
//}
//
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
//void qsort_k(int * arr,int left,int right,int k,int delta=5)
//{
//    if(left>=right)return;
//
//    if(right-left+1<delta)
//    {
//        cout<<left<<"-"<<right<<endl;
//        for(int i=0;i<10;i++)
//        {
//            cout<<arr[i]<<" ";
//        }
//        cout<<endl;
//
//        insert_sort(arr,left,right);
//        for(int i=0;i<10;i++)
//        {
//            cout<<arr[i]<<" ";
//        }
//        cout<<endl;
//
//        return ;
//    }
//    int mid=partition(arr,left,right);
////    if(k==mid+1)return arr[mid];
//    if(mid<right)
//    {
//        qsort_k(arr,mid+1,right,k,delta);
//    }
//    if(mid>left)
//    {
//        qsort_k(arr,left,mid-1,k,delta);
//    }
//}

//3.三路快排
//
//void quickSort(int *a,int left,int right)
//{
//    if(left<right)
//    {
//        int i=left,j=right-1,base=right;
//        int p=left-1;
//        int q=right;
//        while (i<j)
//        {
//            while(a[i]<a[base])i++;//// 从左向右找第一个大于等于x的数
//            while (a[j]>a[base])j--;//从右向左找第一个小于x的数
//            if(i>=j) {
//                break;
//            }
//            swap(a[i],a[j]);
//            if(a[i]==a[base])
//            {
//                swap(a[p],a[i]);
//                p++;
//            }
//            if(a[j]==a[base])
//            {
//                swap(a[q],a[j]);
//                q--;
//            }
//        }
////        swap(a[i],a[base]);
//
//        swap(a[i], a[right]);
//        j= i- 1; i =i + 1;
//        int k = 0;
//        //把相等的元素都交换到数组的中间
//        for (k = left; k <= p; ++k, --j) {
//            swap(a[k], a[j]);
//        }
//        for (k = right - 1; k >= q; --k, ++i) {
//            swap(a[k],a[i]);
//        }
//        quickSort(a,left,i-1);
//        quickSort(a,i+1,right);
//    }
//}

void QuickSort(int arr[], int left, int right) {
    assert(arr);
    if (left >= right) {
        return;
    }
    int l = left - 1, r = right, value = arr[right];
    int p = left - 1;
    int q = right;
    while (1) {
        //向左向右扫描找到不小于value的值
        while (arr[++l] < value) { ; }
        //从右向左扫描找到不大于value的值
        while (arr[--r] > value) { if(r == left) break; }
        if (l >= r) {
            break;
        }
        swap(arr[l], arr[r]);
        //如果arr[l]的值和value是相等的，就把它放入到数组左边
        if (arr[l]== value) {
            p++;
            swap(arr[p], arr[l]);
        }
        //同理，把和value相等的值放入到数组右边
        if (arr[r]==value) {
            q--;
            swap(arr[q], arr[r]);
        }
    }
    /*上面的循环找到了需要的元素,然后交换*/
    swap(arr[l], arr[right]);
    r = l - 1; l = l + 1;
    int k = 0;
    //把相等的元素都交换到数组的中间
    for (k = left; k <= p; ++k, --r) {
        swap(arr[k], arr[r]);
    }
    for (k = right - 1; k >= q; --k, ++l) {
        swap(arr[k], arr[l]);
    }
    QuickSort(arr, left, r);
    QuickSort(arr, l, right);
}


int main()
{
    int a[]={6,7,8,5,4,3,2,1};
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    QuickSort(a,0,7);

    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}