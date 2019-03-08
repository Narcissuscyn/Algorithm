//三路快排
// Created by Narcissus Chen on 2019-03-08.
//

//void QuickSort(int arr[], int left, int right) {
//    assert(arr);
//    if (left >= right) {
//        return;
//    }
//    int l = left - 1, r = right, value = arr[right];
//    int p = left - 1;
//    int q = right;
//    while (1) {
//        //向左向右扫描找到不小于value的值
//        while (arr[++l] < value) { ; }
//        //从右向左扫描找到不大于value的值
//        while (arr[--r] > value) { if(r == left) break; }
//        if (l >= r) {
//            break;
//        }
//        swap(arr[l], arr[r]);
//        //如果arr[l]的值和value是相等的，就把它放入到数组左边
//        if (arr[l]== value) {
//            p++;
//            swap(arr[p], arr[l]);
//        }
//        //同理，把和value相等的值放入到数组右边
//        if (arr[r]==value) {
//            q--;
//            swap(arr[q], arr[r]);
//        }
//    }
//    /*上面的循环找到了需要的元素,然后交换*/
//    swap(arr[l], arr[right]);
//    r = l - 1; l = l + 1;
//    int k = 0;
//    //把相等的元素都交换到数组的中间
//    for (k = left; k <= p; ++k, --r) {
//        swap(arr[k], arr[r]);
//    }
//    for (k = right - 1; k >= q; --k, ++l) {
//        swap(arr[k], arr[l]);
//    }
//    QuickSort(arr, left, r);
//    QuickSort(arr, l, right);
//}