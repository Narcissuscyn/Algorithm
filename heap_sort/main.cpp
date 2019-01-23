#include "MaxHeap.h"
#include <iostream>
#include <vector>
using namespace std;
//class Solution {
//public:
//    int minPathSum(vector<vector<int>>& grid) {
//        int i=grid.size();
//        if(grid.size()==0)return 0;
//        int j=grid[0].size();
//        int flag[1000][1000];
//        for(int m=0;m<1000;m++)
//        {
//            for(int n=0;n<1000;n++)
//            {
//                flag[m][n]=-1;
//            }
//        }
//        return minSum(i-1,j-1,grid,flag);
//    }
//    int minSum(int i,int j,vector<vector<int>>& grid ,int (*flag)[1000])
//    {
//        int l=0,u=0;
//        if(i-1>=0)
//        {
//            if(flag[i-1][j]!=-1)
//                u=flag[i-1][j];
//            else
//                u=minSum(i-1,j,grid,flag);
//        }
//        if(j-1>=0)
//        {
//            if(flag[i][j-1]!=-1)
//                l=flag[i][j-1];
//            else
//                l=minSum(i,j-1,grid,flag);
//        }
//        if(i-1<0){
//            flag[i][j]=l+grid[i][j];
//        }
//        else if(j-1<0){
//            flag[i][j]= u+grid[i][j];
//        }
//        else
//        {
//            flag[i][j]=min(l,u)+grid[i][j];
//        }
//        return flag[i][j];
//
//    }
//};
//
//
//
//int main() {
//    std::cout << "Hello, World!" << std::endl;
//    vector<vector<int>> a;
//    a.push_back(vector<int>{0,0});
//    a.push_back(vector<int>{0,0});
////    a.push_back(vector<int>{4,2,1});
//    Solution solver;
//    int b=solver.minPathSum(a);
//
//    return 0;
//}
//
//#include <iostream>
//#include <queue>
//#include <vector>
//using namespace std;
//
//int heap[100] = {-1, 1, -9, 2, 6, 6, 4, 1, 6, 5, 7, 6};
//int len = 11;
////上浮操作
//void up(int pos)
//{
//    int tmp = heap[pos];
//    int i = pos >> 1, j = pos;
//
//    while(heap[i] < tmp && i >= 1)
//    {
//        heap[j] = heap[i];
//        i >>= 1;
//        j >>= 1;
//    }
//    heap[j] = tmp;
//}
//
//void output()
//{
//    for(int i = 1; i <= 11; i++ )
//    {
//        cout << heap[i] << " ";
//    }
//    cout << endl;
//}
////下沉操作
//void down(int pos)
//{
//    int i = pos, j = pos << 1;
//    int tmp = heap[pos];
//    while(j <= len)
//    {
//        if(heap[j + 1] > heap[j] && j + 1<= len)
//        {
//            j++;
//        }
//        if(tmp > heap[j]) break;
//        heap[i] = heap[j];
//        i = j;
//        j <<= 1;
//    }
//    heap[i] = tmp;
//}
//void build()
//{
//    for(int i = len / 2; i >= 1; i--)
//    {
//        down(i);
//    }
//}
////排序操作
//void heapSort()
//{
//    int i = len;
//    while(i--)
//    {
//        swap(heap[1], heap[len]);
//        len--;
//        down(1);
//        output();
//    }
//}
//int main()
//{
//    build();
//    output();
//    heapSort();
//}

int main()
{
    int a[]={4,6,8,5,9};
    //初始建堆
    MaxHeap h(a,5);
    h.show_heap();
    //堆排序
    h.heap_sort();
    h.show_heap();
    return 0;
}

/*
 * output:
 * 9 6 8 5 4
 * 4 5 6 8 9
 */