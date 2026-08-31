/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e5+10;
int n,m;
vector <int> g[N];
int dfn[N],low[N],bel[N];
int cnt=0,dfncnt=0;
stack <int> s;
inline int fto (char c) {return (c!='Y');}
void Tarjan (int u) {
    dfn[u]=low[u]=++dfncnt;
    s.push(u);
    for (int v:g[u]) {
        if (!dfn[v]) {
            Tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if (!bel[v]) low[u]=min(low[u],low[v]);
    }
    if (low[u]==dfn[u]) {
        cnt++;
        while (1) {
            int v=s.top();
            s.pop();
            bel[v]=cnt;
            if (v==u) break;
        }
    }
}
bool rch[N];
void dfs (int u) {
    rch[u]=1;
    for (int v:g[u]) {
        if (rch[v]) continue;
        dfs(v);
    }
}
signed main() {
    Cios;
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
        int a,b;
        char ca,cb;
        cin>>a>>ca>>b>>cb;
        g[a+n*(!fto(ca))].push_back(b+n*fto(cb));
        g[b+n*(!fto(cb))].push_back(a+n*fto(ca));
    }
    for (int i=1;i<=2*n;i++) {
        if (!dfn[i]) Tarjan(i);
    }
    for (int i=1;i<=n;i++) {
        if (bel[i]==bel[i+n]) {
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
    }
    for (int i=1;i<=n;i++) {
        bool yes,no;
        dfs(i);
        yes=!rch[i+n];
        for (int i=1;i<=2*n;i++) rch[i]=0;
        dfs(i+n);
        no=!rch[i];
        for (int i=1;i<=2*n;i++) rch[i]=0;
        if (yes&&no) cout<<"?";
        else if (yes) cout<<"Y";
        else if (no) cout<<"N";
    }
    return 0;
}