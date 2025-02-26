/*
### 题目要求
- 给定一个长度为N的数组A和一个整数K
- 需要找出所有满足以下条件的区间[i,j]:
  - 区间内所有数的和能被K整除
  - i和j是数组的有效下标(0 ≤ i ≤ j < N)

### 输入格式
- 第一行：两个整数N和K (1 ≤ N,K ≤ 10^5)
- 接下来N行：每行一个整数Ai (1 ≤ Ai ≤ 10^5)

### 输出格式
- 一个整数：表示满足条件的区间个数

### 示例
输入：
```
5 2
1
2
3
4
5
```
输出：
```
6
```

### 当前代码分析
当前实现使用了三重循环，时间复杂度O(N³)：
```c
for(int i=0; i<N; i++)          // 枚举起点
    for(int j=i; j<N; j++)      // 枚举终点
        for(int x=i; x<=j; x++)  // 计算区间和
```

建议使用前缀和优化至O(N)复杂度。
*/
#include <stdio.h>

#define MAXN 100005

long long sum[MAXN];  // 前缀和数组
int cnt[MAXN];       // 余数统计数组

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    
    // 计算前缀和
    sum[0] = 0;
    for(int i = 1; i <= N; i++) {
        int x;
        scanf("%d", &x);
        sum[i] = sum[i-1] + x;
    }
    
    // 统计每个余数出现的次数
    long long ans = 0;
    for(int i = 0; i <= N; i++) {
        int rem = sum[i] % K;
        if(rem < 0) rem += K;  // 处理负数余数
        cnt[rem]++;
    }
    
    // 计算结果
    for(int i = 0; i < K; i++) {
        ans += (long long)cnt[i] * (cnt[i] - 1) / 2;
    }
    
    printf("%lld\n", ans);
    return 0;
}