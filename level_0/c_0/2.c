#include<stdio.h>
// 数组与指针
/*
    1.数组名本身就是一个指针，它指向数组的第一个元素的地址;
    因此，数组arr可以直接赋值给指针变量pr

    2.动态数组的创建
    类型说明符 *数组名 = (类型说明符*)malloc(数组长度*sizeof(类型说明符));
*/

int main(){
    int arr[3] = {1, 2, 3};
    printf("arr[0]=%p\n", &arr[0]);
    printf("pr=%p\n", arr);

    int *pr = arr;
    printf("arr[0]=%d\n", arr[0]);
    printf("pr[0]=%d\n", *pr);

    printf("arr[1]=%d\n", arr[1]);
    printf("pr[1]=%d\n", *(pr+1));

    return 0;
}