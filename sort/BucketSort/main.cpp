#include<iostream>
#include <vector>
using namespace std;
void insert_sort(vector<int>&p ,int num)
{
    for(int i=1;i<num;i++)
    {
        int temp=p[i];
        int j=i-1;
        for(;j>=0&&temp<p[j];j--)//注意判断条件
        {
            p[j + 1] = p[j];
        }
        p[j+1]=temp;
    }
}
/**
 * a:待排序数组
 * num:数组个数
 * bucket_size:桶中元素的个数
**/
void bucket_sort(int*a,int num,int bucket_size)
{
    if(a==NULL||num==1)return ;
    int min_=a[0],max_=a[0];
    for(int i=1;i<num;i++)
    {
        if(a[i]>max_)max_=a[i];
        if(a[i]<min_)min_=a[i];
    }
    int bucket_count=(max_-min_)/bucket_size+1;//每个桶的个数
    vector<int>* p=new vector<int>[bucket_count];
    for(int i=0;i<bucket_size;i++)
    {
        p[i]=vector<int>();
    }
    // 利用映射函数将数据分配到各个桶中
    for (int i = 0; i < num; i++) {
        int index = (a[i] - min_) / bucket_size;//求桶坐标
        p[index].push_back(a[i]);
    }
    int idx=0;
    for(int i=0;i<bucket_size;i++)
    {
        insert_sort(p[i],p[i].size());
        for(int j=0;j<p[i].size();j++)
        {
            a[idx]=p[i][j];
            idx++;
        }
    }
}

int main() {
    int a[]={4,6,8,5,9,10,19,13,11,39};
    int count= sizeof(a)/ sizeof(int);
    for(int i=0;i<count;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    bucket_sort(a,count,5);
    for(int i=0;i<count;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
/*
 * 4 6 8 5 9 10 19 13 11 39
 *4 5 6 8 9 10 11 13 19 39
*/