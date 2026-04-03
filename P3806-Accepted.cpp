/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e4+10,K=1e7+10,inf=(1ll<<60);
int n,m;
struct edge {
    int to,w;
};
vector <edge> g[N];
int qry[105],res[105];
bool vis[N];
int rt,tsiz;
int siz[N],mxs[N];
template <class _tp> class Stack {
    vector <_tp> st;
    public:
    inline void push (int x) {st.push_back(x);}
    inline void pop () {st.pop_back();}
    inline _tp top () {return st.back();}
    inline void clear () {st.clear();}
    inline int size () {return st.size();}
};
inline void getroot (int u,int f) {
    siz[u]=1;
    mxs[u]=0;
    for (auto [v,w]:g[u]) {
        if (v==f||vis[v]) continue;
        getroot (v,u);
        siz[u]+=siz[v];
        mxs[u]=max(mxs[u],siz[v]);
    }
    mxs[u]=max(mxs[u],tsiz-siz[u]);
    if (rt==0||mxs[u]<mxs[rt]) rt=u;
}
int dis[N],cnt;
inline void getdist (int u,int f,int d) {
    if (d>K) return;
    dis[++cnt]=d;
    for (auto [v,w]:g[u]) {
        if (v==f||vis[v]) continue;
        getdist(v,u,d+w);
    }
}
bool tag[K];
Stack <int> st;
inline void dfssize (int u,int f,int &sz) {
    sz++;
    for (auto [v,w]:g[u]) {
        if (vis[v]||v==f) continue;
        dfssize(v,u,sz);
    }
}
inline void solve (int u) {
    vis[u]=1;
    tag[0]=1;
    st.clear();
    st.push(0);
    for (auto [v,w]:g[u]) {
        if (vis[v]) continue;
        cnt=0;
        getdist(v,u,w);
        for (int i=1;i<=cnt;i++) {
            for (int j=1;j<=m;j++) res[j]|=(qry[j]>=dis[i]&&tag[qry[j]-dis[i]]);
        }
        for (int i=1;i<=cnt;i++) {
            if (dis[i]<K&&(!tag[dis[i]])) {
                tag[dis[i]]=1;
                st.push(dis[i]);
            }
        }
    }
    while (st.size()) tag[st.top()]=0,st.pop();
    for (auto [v,w]:g[u]) {
        if (vis[v]) continue;
        tsiz=0;
        dfssize(v,u,tsiz);
        rt=0;
        mxs[rt]=inf;
        getroot(v,0);
        solve(rt);
    }
}
signed main() {
    Cios;
    cin>>n>>m;
    for (int i=1;i<n;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for (int i=1;i<=m;i++) cin>>qry[i];
    mxs[0]=inf;
    tsiz=n;
    rt=0;
    getroot(1,0);
    solve (rt);
    for (int i=1;i<=m;i++) cout<<(res[i]?"AYE":"NAY")<<"\n";
    return 0;
}