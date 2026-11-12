/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e5+10;
int n,m,k,l;
struct edge {
    int to,nxt;
}e[N*20];
int hd[N],ecnt=0;
void addedge (int u,int v) {
    e[++ecnt]={v,hd[u]},hd[u]=ecnt;
    e[++ecnt]={u,hd[v]},hd[v]=ecnt;
}
int dfn[N],low[N],dfncnt=0;
int ha[N],hb[N];
vector <pair <int,int>> res;
void Tarjan (int u,int fa) {
    dfn[u]=low[u]=++dfncnt;
    for (int i=hd[u],v=e[i].to;i;i=e[i].nxt,v=e[i].to) {
        if (!dfn[v]) {
            Tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if (low[v]>dfn[u]) {
                if (!ha[v]||!hb[v]||ha[v]==k||hb[v]==l) res.push_back({u,v});
            }
            ha[u]+=ha[v];
            hb[u]+=hb[v];
        }
        else if (v!=fa) low[u]=min(low[u],dfn[v]);
    }
}
signed main() {
    Cios;
    cin>>n>>m>>k>>l;
    for (int i=1;i<=k;i++) {
        int _a;
        cin>>_a;
        ha[_a]=1;
    }
    for (int i=1;i<=l;i++) {
        int _b;
        cin>>_b;
        hb[_b]=1;
    }
    for (int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        addedge(u,v);
    }
    Tarjan(1,0);
    cout<<res.size()<<"\n";
    for (auto [u,v]:res) cout<<u<<" "<<v<<"\n";
    return 0;
}

/*
g++ -g mainc.cpp -o mainc.exe -std=c++14 -O2 -static; echo "finish"; .\mainc.exe; rm mainc.exe
cd $work && g++  mainc.cpp -o mainc -std=c++14 -O2 && echo "finish" && ./mainc && rm mainc
*/