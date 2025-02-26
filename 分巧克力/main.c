/*
让我重述一下这道题的要求：

**题目核心：**
- 小明有N块长方形巧克力，要分给K个小朋友
- 每块巧克力都是Hi×Wi的方格组成的长方形
- 需要将巧克力切成K块完全相同的正方形

**具体要求：**
1. 切出的巧克力必须是：
   - 正方形形状
   - 边长为整数
   - 大小完全相同
2. 求能切出的最大正方形边长

**输入格式：**
```
N K        (1 ≤ N,K ≤ 10^5)
H1 W1      (1 ≤ Hi,Wi ≤ 10^5)
H2 W2
...
HN WN
```

**输出格式：**
- 一个整数，表示最大可能的正方形边长

**示例：**
```
输入：
2 10
6 5
5 6

输出：
2
```

**约束条件：**
- 保证至少能给每个小朋友1×1的巧克力
- N和K的范围：1到10^5
- Hi和Wi的范围：1到10^5

这是一个最优化问题，需要通过二分查找来解决。
*/

#include <stdio.h>

#define MAX_N 100005

int N, K;
int H[MAX_N], W[MAX_N];

// 检查边长为size时是否能切出K块巧克力
int check(int size) {
    if (size == 0) return 1;
    int count = 0;
    for (int i = 0; i < N; i++) {
        // 计算每块巧克力能切出多少个size*size的正方形
        count += (H[i] / size) * (W[i] / size);
        if (count >= K) return 1;
    }
    return count >= K;
}

int solve() {
    // 二分查找可能的最大边长
    int left = 1;
    int right = 100000;  // 根据题目限制设置上限
    int result = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(mid)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int main() {
    // 读入数据
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &H[i], &W[i]);
    }
    
    printf("%d\n", solve());
    return 0;
}