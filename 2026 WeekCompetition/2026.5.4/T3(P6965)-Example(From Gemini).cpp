#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 3000005; // 2-SAT 图的最大节点数

struct TrieNode {
    int child[2];
    vector<int> ids; // 存储终止于该节点的字符串对应的 节点编号(Literal)
} trie[1000005];

int trie_cnt = 1;
int n, total_vars; 
vector<int> adj[MAXN];

// 2-SAT 核心建边逻辑：选了 u 必须选 v，同时 选了非v 必须选 非u
void add_edge(int u, int v) {
    adj[u].push_back(v);         // u -> v
    adj[v ^ 1].push_back(u ^ 1); // 非v -> 非u
}

// 插入字符串到 Trie，id 是该字符串对应的 节点编号(2i 或 2i+1)
void insert(const string& s, int id) {
    int u = 1;
    for (char c : s) {
        int v = c - '0';
        if (!trie[u].child[v]) trie[u].child[v] = ++trie_cnt;
        u = trie[u].child[v];
    }
    trie[u].ids.push_back(id);
}

// 遍历 Trie 树，通过辅助变量建立排他限制
// u: 当前 Trie 节点
// last_aux_lit: 上一个辅助变量的“真”节点编号
void build_graph(int u, int last_aux_lit) {
    int cur_last_lit = last_aux_lit;
    
    // 遍历所有在这个 Trie 节点结尾的字符串
    for (int lit : trie[u].ids) {
        
        // 创建一个新的辅助变量，变量编号增加
        int new_aux_var = ++total_vars; 
        int new_aux_lit = 2 * new_aux_var; // 新辅助变量的“真”节点
        
        // 规则1：如果选了当前串(lit)，则当前前缀状态变为真
        add_edge(lit, new_aux_lit);
        
        // 如果上方已经有前缀状态了
        if (cur_last_lit != -1) {
            // 规则2：如果上方有串被选(cur_last_lit为真)，当前串绝对不能选(lit^1)
            add_edge(cur_last_lit, lit ^ 1);
            
            // 规则3：将上方的前缀状态传递给当前的新前缀状态
            add_edge(cur_last_lit, new_aux_lit);
        }
        
        // 更新当前前缀状态，给同节点的下一个串，或者下方的子树用
        cur_last_lit = new_aux_lit;
    }
    
    // 向下遍历子树
    for (int i = 0; i < 2; i++) {
        if (trie[u].child[i]) {
            build_graph(trie[u].child[i], cur_last_lit);
        }
    }
}

// Tarjan 算法求强连通分量 (SCC)
int dfn[MAXN], low[MAXN], scc[MAXN], timer, scc_cnt;
int stk[MAXN], top;
bool in_stk[MAXN];

void tarjan(int u) {
    dfn[u] = low[u] = ++timer;
    stk[++top] = u;
    in_stk[u] = true;
    for (int v : adj[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (in_stk[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        scc_cnt++;
        while (true) {
            int v = stk[top--];
            in_stk[v] = false;
            scc[v] = scc_cnt;
            if (u == v) break;
        }
    }
}

string s[500005];
int q_pos[500005];

int main() {
    // 优化输入输出速度
    ios::sync_with_stdio(false);
    cin.tie(0);

    if (!(cin >> n)) return 0;
    
    total_vars = n; // 初始有 n 个字符串变量，编号 1 到 n

    // 读入字符串（编号 1 到 n）
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        q_pos[i] = -1;
        for (int j = 0; j < s[i].length(); j++) {
            if (s[i][j] == '?') {
                q_pos[i] = j;
                break;
            }
        }
        
        if (q_pos[i] == -1) {
            // 如果没有 '?'，它只有一种状态，我们强制让它填 '0'（即节点 2*i 为真）
            insert(s[i], 2 * i);
            // 2-SAT 强制为真的套路：让它的反面(2i+1)推出它的正面(2i)
            // 意思是：就算它是假，也会导致它是真，所以它只能是真。
            add_edge(2 * i + 1, 2 * i); 
        } else {
            // 如果有 '?'，分别插入 '0' 和 '1' 的两种状态
            s[i][q_pos[i]] = '0';
            insert(s[i], 2 * i);       // 填 '0' 对应节点 2*i
            
            s[i][q_pos[i]] = '1';
            insert(s[i], 2 * i + 1);   // 填 '1' 对应节点 2*i+1
            
            s[i][q_pos[i]] = '?';      // 恢复原状，以便后续输出
        }
    }

    // 在 Trie 树上进行前缀优化建图，初始前缀状态设为 -1 (无)
    build_graph(1, -1);

    // 跑 Tarjan，注意有效节点是从 2 到 2 * total_vars + 1
    // (因为变量 1 是 2和3，变量 total_vars 是 2*total_vars 和 2*total_vars+1)
    for (int i = 2; i <= 2 * total_vars + 1; i++) {
        if (!dfn[i]) tarjan(i);
    }

    // 判断是否有解
    for (int i = 1; i <= n; i++) {
        // 如果一个变量的“真”和“假”在同一个强连通分量里，说明互相矛盾，无解
        if (scc[2 * i] == scc[2 * i + 1]) {
            cout << "NO\n";
            return 0;
        }
    }

    // 如果有解，输出答案
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        // 2-SAT 输出方案的经典结论：
        // 哪个状态所在的 SCC 编号更小，我们就选哪个状态
        if (scc[2 * i] < scc[2 * i + 1]) { 
            // 选了 2*i (填 '0')
            if (q_pos[i] != -1) s[i][q_pos[i]] = '0';
        } else {
            // 选了 2*i + 1 (填 '1')
            if (q_pos[i] != -1) s[i][q_pos[i]] = '1';
        }
        cout << s[i] << "\n";
    }

    return 0;
}