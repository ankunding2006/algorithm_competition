/*
问题描述
第十六届蓝桥杯比赛太火爆了，赛场周围的酒店早早地就被抢订一空，剩下的房间寥寥无几。作为蓝桥学院的指导老师，小蓝为此头疼不已，因为他需要将同学们分配到不同的酒店去入住。

本次比赛中，小蓝带领了 M 名同学参赛。考场周围仅剩下 N 家酒店有空房，每家酒店的位置用 A_i 表示。酒店 i 和酒店 j 之间的距离为 |A_i−A_j|。

每位同学将在其中一家酒店入住，每家酒店只容纳一名同学。由于比赛第二天时间紧迫，小蓝希望同学们早早集合赶往考场。集合时间取决于任意两名同学所住酒店之间的最大距离。现在小蓝想知道这个最大距离可能的最小值是多少。

作为同学中的一员，希望你能帮助指导老师小蓝解决这个问题。

输入格式
第一行输入两个整数 N,M(1≤M≤N≤10^5) 表示酒店的数量和同学的数量。

第二行输入 N 个整数 A_1,A_2,A_3,⋯A_N(1≤A_i≤10^9) 表示每家酒店的位置。

输出格式
输出一个整数表示答案。

样例输入
5 3
3 1 6 4 5 

样例输出
2

样例说明
当 3 位同学入住第 4,5,6 号酒店时为其中一种最优情况，答案为 2。
*/

#include <stdlib.h>
#include <stdio.h>


int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}



int main()
{
    int N,M;
    int position[100000];
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&position[i]);
    }
    qsort(position,(size_t)N,sizeof(int),cmpfunc);
    int min=1000000000;
    for (int i = 0; i < N && i+M-1<N; i++)
    {
        if(position[i+M-1]-position[i]<min)
        {
            min=position[i+M-1]-position[i];
        }
    }
    printf("%d",min);
}
