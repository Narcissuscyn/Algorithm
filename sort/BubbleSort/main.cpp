#include <iostream>
#include <ctime>
using namespace std;
//基础版本
void bubble_sort(int*p,int num)
{
    for(int i=0;i<num;i++)
    {
        for(int j=1;j<num;j++)
        {
            if(p[j-1]>p[j])
            {
                int temp=p[j-1];
                p[j-1]=p[j];
                p[j]=temp;
            }
        }
    }
}
//加强版1：增加flag标识，没有发生交换就停止
void bubble_sort_1(int*p,int num)
{
    bool flag=true;
    while(flag)
    {
        flag=false;
        for(int j=1;j<num;j++)
        {
            if(p[j-1]>p[j])
            {
                int temp=p[j-1];
                p[j-1]=p[j];
                p[j]=temp;
                flag=true;
            }
        }
    }
}

//加强版2：增加flag标识,记录最新不需要发生交换的位置
void bubble_sort_2(int*p,int num)
{
    int len=num;
    while(len>0)
    {
        int flag=0;
        for(int j=1;j<len;j++)
        {
            if(p[j-1]>p[j])
            {
                int temp=p[j-1];
                p[j-1]=p[j];
                p[j]=temp;
                flag=j;
            }
        }
        len=flag;
    }
}
int main() {
    int a[]={8,7,6,5,4,3,2,1,10,11,12,13,14,15,16,17,19,19,20};
    int len=sizeof(a)/4;
    clock_t startTime,endTime;
    startTime = clock();//计时开始
//    bubble_sort(a, len);
//    bubble_sort_1(a, len);
    bubble_sort_2(a, len);
    endTime = clock();//计时开始
    cout<<"算法执行持续时间："<<(double)(endTime - startTime) / CLOCKS_PER_SEC<<"秒"<<endl;
    for(int i=0;i<len;i++)
    {
        cout<<a[i]<<' ';
    }
    return 0;
}
/*
 * 时间输出为：
 * 算法执行持续时间：4e-06秒
 * 1 2 3 4 5 6 7 8 10 11 12 13 14 15 16 17 19 19 20
 *
 * 算法执行持续时间：3e-06秒
 * 1 2 3 4 5 6 7 8 10 11 12 13 14 15 16 17 19 19 20
 *
 * 算法执行持续时间：2e-06秒
 * 1 2 3 4 5 6 7 8 10 11 12 13 14 15 16 17 19 19 20
 *
 */