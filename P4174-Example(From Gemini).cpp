#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9; // 定义无穷大
const int MAXN = 60005;  // 节点总数最大值: S + N + M + T
const int MAXM = 400005; // 边数最大值: (N + M + 2*M) * 2

// 链式前向星存图
int head[MAXN], to[MAXM], cap[MAXM], nxt[MAXM], cnt = 1;
int level[MAXN], cur[MAXN];

// 添加有向边和反向边
void add_edge(int u, int v, int c) {
    // 正向边，容量为 c
    to[++cnt] = v;
    cap[cnt] = c;
    nxt[cnt] = head[u];
    head[u] = cnt;
    // 反向边，容量为 0，用于反悔
    to[++cnt] = u;
    cap[cnt] = 0;
    nxt[cnt] = head[v];
    head[v] = cnt;
}

// BFS 对图进行分层
bool bfs(int s, int t) {
    fill(level, level + t + 1, -1);
    level[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = nxt[i]) {
            int v = to[i];
            // 容量大于 0 且 v 未被访问过
            if (cap[i] > 0 && level[v] == -1) {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    return level[t] != -1; // 能否到达汇点
}

// DFS 寻找增广路 (带当前弧优化)
int dfs(int u, int t, int pushed) {
    if (pushed == 0 || u == t) return pushed;
    int flow = 0;
    for (int &i = cur[u]; i; i = nxt[i]) { // 注意这里的 &i，是当前弧优化的核心
        int v = to[i];
        if (level[u] + 1 != level[v] || cap[i] == 0) continue;
        
        int push = dfs(v, t, min(pushed - flow, cap[i]));
        if (push == 0) continue;
        
        cap[i] -= push;
        cap[i ^ 1] += push; // 反向边容量增加
        flow += push;
        if (flow == pushed) break;
    }
    return flow;
}

// Dinic 主函数
int dinic(int s, int t) {
    int flow = 0;
    while (bfs(s, t)) {
        // 初始化当前弧
        for (int i = 0; i <= t; i++) cur[i] = head[i];
        while (int pushed = dfs(s, t, INF)) {
            flow += pushed;
        }
    }
    return flow;
}

int main() {
    // 优化输入输出速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    if (!(cin >> n >> m)) return 0;
    
    // S 设为 0，T 设为 n + m + 1
    int S = 0, T = n + m + 1;
    
    // 读取中转站成本
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        // 中转站连向汇点 T
        add_edge(i, T, p);
    }
    
    int total_profit = 0;
    // 读取用户群信息
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        total_profit += c;
        
        // 为了区分中转站和用户，用户编号设为 n + i
        add_edge(S, n + i, c);         // 源点 S 连向用户，容量为收益
        add_edge(n + i, a, INF);       // 用户连向中转站 A，容量无穷大
        add_edge(n + i, b, INF);       // 用户连向中转站 B，容量无穷大
    }
    
    // 最终答案 = 总收益 - 最小割（即最大流）
    int max_profit = total_profit - dinic(S, T);
    
    cout << max_profit << "\n";
    
    return 0;
}