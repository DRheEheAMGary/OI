#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;
const int MAXN = 505;       // 最大节点数（150 + 270 + 2 即可，505 足够）
const int MAXM = 100005;    // 最大边数 (150*270 + 150 + 270)*2 约为 82000

// 链式前向星存图
int head[MAXN], to[MAXM], nxt[MAXM], cap[MAXM], flow[MAXM];
int cnt = 0;

void add_edge(int u, int v, int c) {
    to[cnt] = v; cap[cnt] = c; flow[cnt] = 0; nxt[cnt] = head[u]; head[u] = cnt++;
    to[cnt] = u; cap[cnt] = 0; flow[cnt] = 0; nxt[cnt] = head[v]; head[v] = cnt++;
}

int level[MAXN], ptr[MAXN];
int S, T;

// BFS 构建分层图
bool bfs() {
    fill(level, level + T + 1, -1);
    level[S] = 0;
    queue<int> q;
    q.push(S);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = head[v]; i != -1; i = nxt[i]) {
            if (cap[i] - flow[i] > 0 && level[to[i]] == -1) {
                level[to[i]] = level[v] + 1;
                q.push(to[i]);
            }
        }
    }
    return level[T] != -1;
}

// DFS 寻找增广路 (多路增广优化)
int dfs(int v, int pushed) {
    if (pushed == 0 || v == T) return pushed;
    int flow_out = 0;
    // 当前弧优化
    for (int& i = ptr[v]; i != -1; i = nxt[i]) {
        int tr = to[i];
        if (level[v] + 1 != level[tr] || cap[i] - flow[i] == 0) continue;
        int push = dfs(tr, min(pushed - flow_out, cap[i] - flow[i]));
        if (push == 0) continue;
        flow[i] += push;
        flow[i ^ 1] -= push;
        flow_out += push;
        if (flow_out == pushed) break;
    }
    return flow_out;
}

// Dinic 主函数
int dinic() {
    int max_flow = 0;
    while (bfs()) {
        for (int i = 0; i <= T; ++i) ptr[i] = head[i];
        max_flow += dfs(S, INF);
    }
    return max_flow;
}

int main() {
    // 优化输入输出流
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m, n;
    if (!(cin >> m >> n)) return 0;
    
    S = 0;
    T = m + n + 1; // 汇点编号
    fill(head, head + T + 1, -1);
    cnt = 0;
    
    int total_r = 0;
    int r, c;
    
    // 读入各单位代表人数
    for (int i = 1; i <= m; ++i) {
        cin >> r;
        total_r += r;
        add_edge(S, i, r);
    }
    
    // 读入各餐桌容量
    for (int j = 1; j <= n; ++j) {
        cin >> c;
        add_edge(m + j, T, c);
    }
    
    // 所有单位到餐桌建立容量为 1 的边
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            add_edge(i, m + j, 1);
        }
    }
    
    // 如果跑出的最大流等于总代表人数，说明有解
    if (dinic() != total_r) {
        cout << 0 << "\n";
    } else {
        cout << 1 << "\n";
        // 遍历每个单位，找出满流为1的分配策略边
        for (int i = 1; i <= m; ++i) {
            vector<int> tables;
            for (int e = head[i]; e != -1; e = nxt[e]) {
                if (to[e] > m && to[e] <= m + n && flow[e] == 1) {
                    tables.push_back(to[e] - m);
                }
            }
            // 排序输出让结果看起来更规整（非必须操作）
            sort(tables.begin(), tables.end());
            for (size_t k = 0; k < tables.size(); ++k) {
                cout << tables[k] << (k + 1 == tables.size() ? "" : " ");
            }
            cout << "\n";
        }
    }
    return 0;
}