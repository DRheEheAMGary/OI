#include <bits/stdc++.h>
using namespace std;

// 使用第二份代码的风格：宏定义与常量
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

intc N = 4e5 + 10;

class Block {
    int n, m, sz, num;
    int a[N], pos[N], bl[N], br[N];
    int min_pos[N], max_pos[N], tmp_max_pos[N];
    int max_dist = 0;
    vector<int> disc;

    struct ques {
        int idx, l, r, ans;
    } q[N];

    // 暴力查询：对应第一份代码的 BruteQuery
    int query(int l, int r) {
        static int mn[N], mx[N];
        int res = 0;
        for (int i = l; i <= r; i++) {
            if (!mn[a[i]]) mn[a[i]] = i;
            mx[a[i]] = i;
            res = max(res, mx[a[i]] - mn[a[i]]);
        }
        // 清理现场
        for (int i = l; i <= r; i++) mn[a[i]] = mx[a[i]] = 0;
        return res;
    }

public:
    void pushQues(int idx, int l, int r) {
        q[idx] = {idx, l, r, 0};
    }

    void init(int _n, int _m, int* _a) {
        n = _n;
        m = _m;
        sz = sqrt(n);
        num = (n - 1) / sz + 1;
        
        // 离散化
        for (int i = 1; i <= n; i++) {
            a[i] = _a[i];
            disc.push_back(a[i]);
        }
        sort(disc.begin(), disc.end());
        disc.erase(unique(disc.begin(), disc.end()), disc.end());
        for (int i = 1; i <= n; i++) {
            a[i] = lower_bound(disc.begin(), disc.end(), a[i]) - disc.begin() + 1;
        }

        // 分块初始化
        for (int i = 1; i <= n; i++) pos[i] = (i - 1) / sz + 1;
        for (int i = 1; i <= num; i++) {
            bl[i] = (i - 1) * sz + 1;
            br[i] = min(n, i * sz);
        }

        // 莫队排序
        sort(q + 1, q + 1 + m, [&](ques x, ques y) {
            if (pos[x.l] != pos[y.l]) return pos[x.l] < pos[y.l];
            return x.r < y.r;
        });
    }

    void solve() {
        int qidx = 1;
        for (int i = 1; i <= num && qidx <= m; i++) {
            // 每个块开始前重置
            max_dist = 0;
            memset(min_pos, 0, sizeof(int) * (disc.size() + 2));
            memset(max_pos, 0, sizeof(int) * (disc.size() + 2));
            
            int L = br[i] + 1, R = br[i];

            for (; qidx <= m && pos[q[qidx].l] == i; qidx++) {
                int ql = q[qidx].l, qr = q[qidx].r;
                
                // 情况1：左右端点在同一块内
                if (qr <= br[i]) {
                    q[qidx].ans = query(ql, qr);
                    continue;
                }

                // 情况2：右端点单调向右移动
                while (R < qr) {
                    R++;
                    if (!min_pos[a[R]]) min_pos[a[R]] = R;
                    max_pos[a[R]] = R;
                    max_dist = max(max_dist, max_pos[a[R]] - min_pos[a[R]]);
                }

                // 处理左侧零散块（回滚部分）
                int tmp_res = max_dist;
                int cur_L = L;
                while (cur_L > ql) {
                    cur_L--;
                    if (!tmp_max_pos[a[cur_L]]) tmp_max_pos[a[cur_L]] = cur_L;
                    // 距离 = max(右侧出现的最远位置, 零散块内出现的最远位置) - 当前左端点
                    int far = max(max_pos[a[cur_L]], tmp_max_pos[a[cur_L]]);
                    tmp_res = max(tmp_res, far - cur_L);
                }

                q[qidx].ans = tmp_res;

                // 回滚左侧零散块的影响
                while (cur_L < L) {
                    tmp_max_pos[a[cur_L++]] = 0;
                }
            }
        }
    }

    void printAns() {
        // 按原序号排序输出
        sort(q + 1, q + 1 + m, [](ques x, ques y) {
            return x.idx < y.idx;
        });
        for (int i = 1; i <= m; i++) cout << q[i].ans << "\n";
    }
} bl;

int n, m, temp_a[N];

signed main() {
    Cios;
    if (!(cin >> n)) return 0;
    for (int i = 1; i <= n; i++) cin >> temp_a[i];
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        bl.pushQues(i, l, r);
    }
    
    bl.init(n, m, temp_a);
    bl.solve();
    bl.printAns();
    
    return 0;
}