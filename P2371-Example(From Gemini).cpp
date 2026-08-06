#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll INF = 2e18; // 设置一个足够大的值
ll a[15], dist[500005];
int n;
ll l, r;

// 求最大公约数
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve_rotation() {
    // 1. 找到最小值作为模数 M
    sort(a + 1, a + n + 1);
    int M = a[1];
    
    // 2. 初始化 dist
    for (int i = 0; i < M; i++) dist[i] = INF;
    dist[0] = 0;

    // 3. 逐个使用 a[i] 更新 dist 数组
    for (int i = 2; i <= n; i++) {
        int step = a[i] % M;
        if (step == 0) continue; 
        
        int d = gcd(step, M); // 环的个数
        for (int start = 0; start < d; start++) {
            // “二次转圈”：
            // 第一圈保证找到一个相对较小的值，或者模拟松弛过程
            // 第二圈保证所有点都被该环上的最小值充分更新
            int cur = start;
            for (int round = 0; round < 2; round++) {
                for (int cnt = 0; cnt < M / d; cnt++) {
                    int next = (cur + step) % M;
                    if (dist[cur] != INF && dist[next] > dist[cur] + a[i]) {
                        dist[next] = dist[cur] + a[i];
                    }
                    cur = next;
                }
            }
        }
    }
}

ll count_ans(ll x, int M) {
    if (x < 0) return 0;
    ll res = 0;
    for (int i = 0; i < M; i++) {
        if (dist[i] <= x) {
            res += (x - dist[i]) / M + 1;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> l >> r;
    int idx = 0;
    for (int i = 1; i <= n; i++) {
        ll val;
        cin >> val;
        if (val != 0) a[++idx] = val; // 排除 0
    }
    n = idx;

    if (n == 0) { // 特判
        cout << 0 << endl;
        return 0;
    }

    solve_rotation();
    
    int M = a[1];
    cout << count_ans(r, M) - count_ans(l - 1, M) << endl;

    return 0;
}