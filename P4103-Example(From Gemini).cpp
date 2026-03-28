/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

intc N=1e6+10;
int n,k,imp[N];
vector <int> g[N],ng[N];
int fa[N],dep[N],sz[N],hv[N],dfn[N],top[N];
int dfncnt=0;

int sum[N],minr[N],maxr[N];

// 新增：关键点标记以及全局答案变量
bool is_imp[N]; 
int ans_sum, ans_min, ans_max;

template <class _tp> class Stack {
    _tp s[N];
    int top_=0;
    public:
    void push (int p) {s[++top_]=p;}
    _tp top () {return s[top_];}
    _tp ptop () {return s[top_-1];}
    int size () {return top_;}
    void clear () {top_=0;}
    void pop () {top_--;}
};
Stack <int> st;

void dfs1 (int u) {
    dep[u]=dep[fa[u]]+1;
    sz[u]=1;
    for (int v:g[u]) {
        if (v==fa[u]) continue;
        fa[v]=u;
        dfs1(v);
        sz[u]+=sz[v];
        if (sz[v]>sz[hv[u]]) hv[u]=v;
    }
}

void dfs2 (int u,int tp) {
    dfn[u]=++dfncnt;
    top[u]=tp;
    if (hv[u]) dfs2(hv[u],tp);
    for (int v:g[u]) {
        if (v==fa[u]||v==hv[u]) continue;
        dfs2(v,v);
    }
}

int lca (int u,int v) {
    while (top[u]!=top[v]) {
        if (dep[top[v]]>dep[top[u]]) swap(u,v);
        u=fa[top[u]];
    }
    return (dep[u]<dep[v])?u:v;
}

void build () {
    sort (imp+1,imp+1+k,[&] (int a,int b) {return dfn[a]<dfn[b];});
    st.push(1);
    if (imp[1]!=1) st.push(imp[1]);
    for (int i=2;i<=k;i++) {
        int lc=lca(st.top(),imp[i]);
        while (st.size()>1&&dfn[st.ptop()]>=dfn[lc]) ng[st.ptop()].push_back(st.top()),st.pop();
        if (lc!=st.top()) ng[lc].push_back(st.top()),st.pop(),st.push(lc);
        st.push(imp[i]);
    }
    while (st.size()>1) ng[st.ptop()].push_back(st.top()),st.pop();
}

void dodp (int u) {
    // 基础状态初始化：是否为查询点
    sum[u] = is_imp[u] ? 1 : 0;
    minr[u] = is_imp[u] ? 0 : 1e15;
    maxr[u] = is_imp[u] ? 0 : -1e15;
    
    for (int v : ng[u]) {
        dodp(v);
        int w = dep[v] - dep[u]; // 虚树边的权重就是原树深度的差值
        
        // 当两边内部都有被选中的关键点时，才进行极值的更新
        if (sum[u] > 0 && sum[v] > 0) {
            ans_min = min(ans_min, minr[u] + minr[v] + w);
            ans_max = max(ans_max, maxr[u] + maxr[v] + w);
        }
        
        // 代价和的累加：这条边将所有被选点划分为 sum[v] 个 和 (k - sum[v]) 个
        ans_sum += w * sum[v] * (k - sum[v]);
        
        // 自底向上转移合并状态
        sum[u] += sum[v];
        minr[u] = min(minr[u], minr[v] + w);
        maxr[u] = max(maxr[u], maxr[v] + w);
    }
    
    // 多测清空好习惯：边回溯边将当前节点的虚树出边清空，重置关键点标记
    ng[u].clear();
    is_imp[u] = 0;
}

signed main() {
    Cios;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    // 初始化树链剖分
    dep[1] = 1;
    fa[1] = 0;
    dfs1(1);
    dfs2(1, 1);
    
    int q;
    cin >> q;
    while (q--) {
        cin >> k;
        for (int i = 1; i <= k; i++) {
            cin >> imp[i];
            is_imp[imp[i]] = 1;
        }
        
        // 如果选择的点数不到2个，构不成通道，特判避免问题
        if (k <= 1) {
            cout << "0 0 0\n";
            if (k == 1) is_imp[imp[1]] = 0; // 顺手清理掉单个标记
            continue;
        }
        
        build();
        
        ans_sum = 0;
        ans_min = 1e15;
        ans_max = -1e15;
        
        // 因为你的 build() 里强制把根节点 1 压入了栈底
        // 所以虚树最终一定是被连通在 1 这个节点上，直接从 1 跑即可
        dodp(1);
        
        cout << ans_sum << " " << ans_min << " " << ans_max << "\n";
    }
    return 0;
}