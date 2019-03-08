#include <iostream>
using namespace std;
//基础版本
void insert_sort(int *p,int num)
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

//增强版（二叉查插入排序）：在查找每个元素时使用二分查找
void insert_sort_1(int *p,int num)
{
    for(int i=1;i<num;i++)
    {
        //二分查找，减少查找过程中的比较次数
        int left=0,right=i-1,m=-1;
        while (left<=right)
        {
            m=(left+right)/2;
            if(p[m]>p[i])
            {
                right=m-1;
            } else
            {
                left=m+1;
            }
        }
        //统一移动
        int temp=p[i];
        for(int j=i-1;j>=right+1;j--)//注意这里的判断条件是right+1,因为不需要插入到i前面时，right=i-1,
            // 此时不需要移动只需要令p[i]=temp即可，也就是p[right+1]=temp;
        {
            p[j+1]=p[j];
        }
        p[right+1]=temp;
    }
}
int main() {
    int a[]={8,7,6,5,4,3,2,1,10,11,12,13,14,15,16,17,19,19,20};
    int len=sizeof(a)/4;
    clock_t startTime,endTime;
    startTime = clock();//计时开始
//    bubble_sort(a, len);
//    bubble_sort_1(a, len);
    insert_sort_1(a, len);
    endTime = clock();//计时开始
    cout<<"算法执行持续时间："<<(double)(endTime - startTime) / CLOCKS_PER_SEC<<"秒"<<endl;
    for(int i=0;i<len;i++)
    {
        cout<<a[i]<<' ';
    }
    return 0;
    return 0;
}