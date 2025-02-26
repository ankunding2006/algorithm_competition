#include <stdio.h>
#include <math.h>

#define MAX_N 100005

int N, K;
int H[MAX_N], W[MAX_N];

int check(int size) {
    if (size == 0) return 1;
    int count = 0;
    for (int i = 0; i < N; i++) {
        count += (H[i] / size) * (W[i] / size);
        if (count >= K) return 1;
    }
    return count >= K;
}

int solve() {
    // 计算理论最大边长
    long long total_area = 0;
    for (int i = 0; i < N; i++) {
        total_area += (long long)H[i] * W[i];
    }
    int upper_bound = (int)sqrt(total_area / K);
    
    // 二分查找
    int left = 1;
    int right = upper_bound;
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
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &H[i], &W[i]);
    }
    printf("%d\n", solve());
    return 0;
}