#include <stdio.h>

//引用

int main()
{
    int i = 5;
    int &j = i;
    i = 7;
    printf("i=%d\n", i);
    printf("j=%d\n", j);
    return 0;
}