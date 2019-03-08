#include <iostream>
using namespace std;
void shell_sort(int *a,int num)
{
    if(a==NULL||num<2)
        return;
    int d=num/2;

    while (d>0)
    {
        for(int i=0;i<num;i++)
        {
            if(i+d<num)
                if(a[i]>a[i+d])swap(a[i],a[i+d]);
        }
        d/=2;
    }
}

int main() {
    int a[]={8,7,6,5,4,3,2,1,10,11,12,13,14,15,16,17,19,19,20};
    int len=sizeof(a)/4;
    clock_t startTime,endTime;
    startTime = clock();//计时开始
    shell_sort(a, len);
    endTime = clock();//计时开始
    cout<<"算法执行持续时间："<<(double)(endTime - startTime) / CLOCKS_PER_SEC<<"秒"<<endl;
    for(int i=0;i<len;i++)
    {
        cout<<a[i]<<' ';
    }
    return 0;
}

