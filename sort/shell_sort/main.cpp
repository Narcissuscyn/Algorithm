#include <iostream>
using namespace std;
void shell_sort(int *arr,int num)
{
    for (int g = num; g > 0; g /= 2) { // 增量序列 gap
        for (int end = g; end < num; end++) { // 每一个组的结束元素, 从数组第gap个元素开始
            // 每组做插入排序
            int key = arr[end], i;
            for (i = end - g; i >= 0 && key < arr[i]; i -= g) arr[i + g] = arr[i];
            arr[i + g] = key;
        }
    }
}

int main() {
    int a[]={8,9,1,7,2,3,5,4,6,0};
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
