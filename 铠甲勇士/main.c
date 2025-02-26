#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
题目：铠甲勇士对战暗影护法

描述：
1. 初始条件：
   - 有M个暗影护法，战斗力分别为B1,B2,...,BM
   - 有N个铠甲勇士，能量值分别为A1,A2,...,AN
   - 铠甲勇士的能量值有特殊性质：任意两个能量值中，一个是另一个的整数倍

2. 战斗规则：
   - 铠甲勇士可以进行合体，将能量值相加
   - 合体后的总能量值必须恰好等于护法的战斗力才能击败他
   - 需要计算击败每个护法最少需要多少个铠甲勇士合体
   - 如果无法击败某个护法，输出-1

输入格式：
第一行：两个整数N和M (1 ≤ N,M ≤ 10^5)
第二行：N个整数A1,A2,...,AN (1 ≤ Ai ≤ 10^10)，表示铠甲勇士的能量值
第三行：M个整数B1,B2,...,BM (1 ≤ Bi ≤ 10^10)，表示暗影护法的战斗力

输出格式：
一行M个整数，表示击败每个护法所需的最少合体数；无法击败则输出-1

样例输入：
3 2
2 2 2
6 3

样例输出：
3 -1

样例解释：
- 对于战斗力为6的护法：需要3个能量值为2的铠甲勇士合体（2+2+2=6）
- 对于战斗力为3的护法：无法用任何组合击败（因为所有能量值都是2）
*/

// 定义结构体
typedef struct {
    int x;   // 数值
    int num; // 数量
} KaiJia;

KaiJia kaijia[100000];
KaiJia originalKaiJia[100000]; // 用于保存原始数据

// 比较函数，用于降序排序
int compare(const void* a, const void* b) {
    KaiJia* k1 = (KaiJia*)a;
    KaiJia* k2 = (KaiJia*)b;
    return k2->x - k1->x;
}

// 合并相同数据的函数
void mergeKaiJia(KaiJia* kaijia, int* size) {
    if (*size <= 1) return;

    int newSize = 0;
    kaijia[newSize].x = kaijia[0].x;
    kaijia[newSize].num = kaijia[0].num;

    for (int i = 1; i < *size; i++) {
        if (kaijia[i].x == kaijia[newSize].x) {
            kaijia[newSize].num += kaijia[i].num;
        }
        else {
            newSize++;
            kaijia[newSize].x = kaijia[i].x;
            kaijia[newSize].num = kaijia[i].num;
        }
    }
    *size = newSize + 1;
}

int main(int argc, char* argv[]) {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &kaijia[i].x);
        kaijia[i].num = 1; // 初始数量为1
    }
    int a[100000];
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }
    // 对结构体数组按 x 值进行降序排序
    qsort(kaijia, n, sizeof(KaiJia), compare);

    int size = n;
    mergeKaiJia(kaijia, &size);
    for (int i = 0; i < m; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (a[i] / kaijia[j].x > 0) {
                int temp = a[i] / kaijia[j].x;
                if (temp > kaijia[j].num) {
                    temp = kaijia[j].num;
                }
                count += temp;
                a[i] = a[i] - temp * kaijia[j].x;
            }
        }
        if (a[i] == 0) {
            printf("%d ", count);
        }
        else {
            printf("-1 ");
        }
    }
    return 0;
}