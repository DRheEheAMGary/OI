/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e6+10;
int n,deg[N],out_to[N],out_w[N];
intl f[N],mxd[N],ans=0; // f[u]表示u往子树走的最长单链，mxd[u]表示u子树内的纯直径
struct edge {
    int to,w;
};
vector <edge> g[N];
queue <int> q;

signed main() {
    Cios;
    cin>>n;
    for (int i=1;i<=n;i++) {
        int u,l;
        cin>>u>>l;
        g[i].push_back({u,l});
        g[u].push_back({i,l});
        deg[i]++; deg[u]++;
        out_to[i]=u; out_w[i]=l; // 记录原本的有向出边
    }
    
    // 1. 拓扑排序剥离所有树枝，顺便做树形 DP
    for (int i=1;i<=n;i++) {
        if (deg[i]==1) q.push(i);
    }
    
    while (q.size()) {
        int u=q.front(); q.pop();
        for (auto [v,w]:g[u]) {
            if (deg[v]>1) {
                mxd[v]=max(mxd[v],f[v]+f[u]+w); // 更新 v 内部的子树直径
                f[v]=max(f[v],f[u]+w);           // 更新 v 往下延伸的最长单链
                if (--deg[v]==1) q.push(v);
            }
        }
    }
    
    // 2. 遍历所有基环树，处理环上 DP
    for (int i=1;i<=n;i++) {
        if (deg[i]<=1) continue; // 不是环上节点，或者已经随别的环处理过了
        
        // 顺藤摸瓜把环抠出来
        vector <int> cir;
        int cur=i;
        while (deg[cur]>1) {
            cir.push_back(cur);
            deg[cur]=0; // 标记已访问
            cur=out_to[cur];
        }
        
        int m=cir.size();
        intl mx_tree=0,mx_cyc=0;
        vector <int> A(2*m+1);
        vector <intl> S(2*m+1,0); // 环上前缀距离
        
        // 复制成双倍链
        for (int j=0;j<m;j++) {
            A[j+1]=A[j+m+1]=cir[j];
            mx_tree=max(mx_tree,mxd[cir[j]]); // 记录纯树内部的最大直径
        }
        for (int j=1;j<2*m;j++) {
            S[j+1]=S[j]+out_w[A[j]];
        }
        
        // 单调队列滑动窗口，最大化 f[A[j]] + S[j] + f[A[k]] - S[k]
        deque <int> Q;
        for (int j=1;j<=2*m;j++) {
            while (Q.size()&&j-Q.front()>=m) Q.pop_front();
            if (Q.size()) {
                mx_cyc=max(mx_cyc,f[A[j]]+S[j]+f[A[Q.front()]]-S[Q.front()]);
            }
            while (Q.size()&&f[A[j]]-S[j]>=f[A[Q.back()]]-S[Q.back()]) Q.pop_back();
            Q.push_back(j);
        }
        
        // 每个连通块的贡献是【纯子树内最大直径】与【跨环最长路径】的最大值
        ans+=max(mx_tree,mx_cyc);
    }
    
    cout<<ans<<"\n";
    return 0;
}