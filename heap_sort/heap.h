//
// Created by Narcissus Chen on 2019-01-22.
//

#ifndef SORT_HEAP_H
#define SORT_HEAP_H

enum{DEFAULT_SIZE=10};
template <class T>
class Heap
{
public:
    Heap()=default;
    virtual ~Heap()= default;
    virtual void show_heap()const =0;
    virtual bool insert_heap(const T&)=0;
    virtual bool  remove_heap(T&)=0;
    virtual void heap_sort()=0;
};
#endif //SORT_HEAP_H

