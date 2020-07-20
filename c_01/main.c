#include<stdio.h>
#include<stdlib.h>

int finding(int age)
{
    int _count;
    printf("请输入一个你能坚持周末出去参加活动的次数:");
    scanf("%d", &_count);
    int factor = rand() % age;

    return factor * _count;
}

int courage(int age)
{
    int isC;
    printf("您是否有勇气在被拒绝后，坚持表白(0表示不会坚持，1表示继续坚持):");
    scanf("%d", &isC);
    int factor = rand() % age;

    return factor * isC;
}

int accept(int isFind, int isC)
{
    return (int)((isFind * isC) / (isFind + isC));
}


int main()
{
    int isSingle = 0;
    int age;
    int luck;

    printf("请输入您的年龄:");
    scanf("%d", &age);


    int isFind = finding(age);
    int isC = courage(age);
    luck = accept(isFind, isC);
    
    if (luck)
    {
        int _times = rand() % 2;
        if(_times){
            printf("朋友，恭喜您将在%d岁结婚!\n", _times + age);
        }
        else
        {
            printf("朋友，恭喜您将在今年结婚!\n");
        }
    }else{
        printf("朋友，为了明天的幸福，勇敢的改变一次吧\n");
    }

    return 0;
}
