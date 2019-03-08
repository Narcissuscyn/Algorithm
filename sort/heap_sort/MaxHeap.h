//
// Created by Narcissus Chen on 2019-01-22.
//

#ifndef SORT_MAXHEAP_H
#define SORT_MAXHEAP_H

#include "heap.h"
class MaxHeap: public Heap<int> {
public:
    /**
     * 创建一个空堆
     */
    MaxHeap(int sz=DEFAULT_SIZE);
    /**
     * 根据已有数组堆创建一个堆
     */
    MaxHeap(const int[],const int );
    /**
     * 析构函数
     */
    ~MaxHeap();
    /**
     * 显示堆
     */
    void show_heap()const;
    /**
     * 向堆中插入元素
     * @return
     */
    bool insert_heap(const int&);
    /**
     * 移除堆中的元素
     * @return
     */
    bool  remove_heap(int&);
    void heap_sort();
protected:
    /**
     * 下浮
     */
    void shift_down(int,int);
    /**
     * 上浮
     */
    void shift_up(int);

private:
    //指向堆的指针
    int *heap;
    //已有堆中元素个数
    int size;
    //堆的容量
    int capacity;

};


#endif //SORT_MAXHEAP_H
