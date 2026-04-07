/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;

#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

intc N = 2e5 + 10, K = 1e6 + 10;
const int INF = 1e9; // 定义一个无穷大

int n, m, k;
struct edge {
    int to, w;
};
vector <edge> g[N];

int res = INF; // 全局最小边数，初始化为无穷大
bool vis[N];
int rt, tsiz;
int siz[N], mxs[N];

// 求树的重心
inline void getroot(int u, int f) {
    siz[u] = 1;
    mxs[u] = 0;
    for (auto [v, w] : g[u]) {
        if (v == f || vis[v]) continue;
        getroot(v, u);
        siz[u] += siz[v];
        mxs[u] = max(mxs[u], siz[v]);
    }
    mxs[u] = max(mxs[u], tsiz - siz[u]);
    if (rt == 0 || mxs[u] < mxs[rt]) rt = u;
}

// 记录 {距离, 边数}
vector <pair<int, int>> dis;

// 修改 getdist：同时记录距离 d 和边数 dep
inline void getdist(int u, int f, int d, int dep) {
    if (d > k) return; // 剪枝：距离已经大于要求值 k，后续肯定不符合（因为边权非负）
    dis.push_back({d, dep});
    for (auto [v, w] : g[u]) {
        if (v == f || vis[v]) continue;
        getdist(v, u, d + w, dep + 1);
    }
}

// ⚠️ 注意：tag数组的下标是距离，所以大小必须是 K 而不是 N
int tag[K]; 

// 点分治处理当前层
inline void solve(int u) {
    vis[u] = true;
    tag[0] = 0; // 距离为 0 的边数是 0
    vector<int> cleared; // 记录需要被复原的 tag 索引

    for (auto [v, w] : g[u]) {
        if (vis[v]) continue;
        dis.clear();
        getdist(v, u, w, 1); // 搜集当前子树的所有距离和边数
        
        // 1. 先统计答案（与前面遍历过的子树拼凑）
        for (auto p : dis) {
            int d = p.first, dep = p.second;
            if (k >= d) {
                res = min(res, dep + tag[k - d]);
            }
        }
        
        // 2. 再将当前子树的信息更新到 tag 数组中
        for (auto p : dis) {
            int d = p.first, dep = p.second;
            if (k >= d) {
                tag[d] = min(tag[d], dep);
                cleared.push_back(d); // 记录下被修改的距离
            }
        }
    }

    // 3. 复原 tag 数组（避免下一次使用 memset 导致 TLE）
    for (int d : cleared) {
        tag[d] = INF;
    }

    // 4. 递归处理所有子树
    for (auto [v, w] : g[u]) {
        if (vis[v]) continue;
        rt = 0;
        tsiz = siz[v]; // 下一次求重心所在的连通块大小
        getroot(v, 0); // 找子树重心
        solve(rt);     // 递归分治
    }
}

signed main() {
    Cios;
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        // 题目明确说明：节点从 0 开始编号
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    // 初始化 tag 数组为无穷大（只初始化 0~k 即可）
    for (int i = 1; i <= k; i++) tag[i] = INF;
    
    rt = 0;
    tsiz = n;
    getroot(0, -1); // 首次找整棵树的重心
    solve(rt);      // 开始点分治

    if (res > 1e8) {
        cout << -1 << "\n"; // 没有找到满足条件的路径
    } else {
        cout << res << "\n";
    }

    return 0;
}