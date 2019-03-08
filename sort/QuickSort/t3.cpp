////
//// Created by Narcissus Chen on 2019-03-08.
////
//
////2.快排+插排
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
