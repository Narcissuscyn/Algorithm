//
// Created by Narcissus Chen on 2019-01-22.
//
#include <iostream>
#include <form.h>
#include "MaxHeap.h"
using namespace std;
MaxHeap::MaxHeap(int sz) {
    capacity=sz>DEFAULT_SIZE?sz:DEFAULT_SIZE;
    heap=new int[capacity];
    assert(heap!= nullptr);
    size=0;
}
MaxHeap::MaxHeap(const int arr[],const int arrSize)
{
    capacity=arrSize>DEFAULT_SIZE?arrSize:DEFAULT_SIZE;
    heap=new int[capacity];
    size=arrSize;
    for(int i=0;i<arrSize;i++)
    {
        heap[i]=arr[i];
    }
    int curPos=size/2-1;

    while(curPos>=0)
    {
        shift_down(curPos,arrSize-1);
        curPos--;
    }

}

void MaxHeap::shift_down(int start, int end) {
    int i=start;//第i个非叶子节点
    int j=start*2+1;//第i个非叶子节点的左儿子
    int temp=heap[i];
    while (j<=end)//是否继续进行往下沉的条件
    {
        if(j+1<=end&&heap[j]<heap[j+1])//找到两个儿子节点更大的一个
        {
            j++;
        }
        if(temp>=heap[j])break;//表示此节点i已经满足堆的条件，不需要继续往下沉；
        //否则，会继续往下判断
        heap[i]=heap[j];
        i=j;//新的节点
        j=2*j+1;//新节点的左子节点
    }
    heap[i]=temp;//完成两个节点的交换，也可能是heap[i]和自身的赋值,比如在while循环的第一遍循环就break出去。
}

MaxHeap::~MaxHeap() {
    delete heap;
    heap= nullptr;
    capacity=size=0;
}

void MaxHeap::shift_up(int e) {

    int j=e;//j为最后新加入的元素
    int i=(e-1)/2;//j的父节点
    int temp=heap[j];
    while (j>=0)
    {
        if(temp<heap[i])//插入的时候就已经满足堆的条件
        {
            break;
        } else {//插入时不满足
            heap[j]=heap[i];
        }
        j=i;//j指向其父节点
        i=(i-1)/2;//j为新j的父节点
    }
    heap[j]=temp;//完成交换
}


bool MaxHeap::insert_heap(const int &val) {
    if(size>=capacity)return false;
    heap[size]=val;
    shift_up(size);
    size+=1;
    return true;
}

bool MaxHeap::remove_heap(int &val) {
    if(size<=0)return false;
    val=heap[0];
    heap[0]=heap[size-1];
    --size;
    shift_down(0,size-1);//这里root就是数组的第一个元素。
    // 所以从0开始；而在初始建堆的时候是从最后一个非叶子节点开始下沉的，
    // 这样是为了保证在下沉每个节点时，其左右子树都满足堆的条件。
}

void MaxHeap::show_heap() const {
    for(int i=0;i<size;i++)
    {
        std::cout<<heap[i]<<" ";
    }
    cout<<endl;
}

void MaxHeap::heap_sort() {
    for(int i=size-1;i>0;i--)
    {
        int temp=heap[0];
        heap[0]=heap[i];
        heap[i]=temp;
        shift_down(0,i-1);
    }
}