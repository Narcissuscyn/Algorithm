#include<iostream>
using namespace std;
void count_sort(int*a,int num)
{
    if(a==NULL||num==1)return ;
    int min_=a[0],max_=a[0];
    for(int i=1;i<num;i++)
    {
        if(a[i]>max_)max_=a[i];
        if(a[i]<min_)min_=a[i];
    }
    int *count=new int[max_+1];
//    for (int i=0;i<=max_;i++)count[i]=0;
    memset(count,0, (max_+1)* sizeof(int));

    for(int i=0;i<num;i++)count[a[i]]++;
    int idx=0;
    for(int i=0;i<=max_;i++)
    {
        for(int j=0;j<count[i];j++)
        {
            a[idx]=i;
            idx++;
        }
    }
    delete[] count;
}

int main() {
    int a[]={4,6,8,5,9};
    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    count_sort(a,5);
    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}