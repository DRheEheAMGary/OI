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
int n,m,k;
vector <int> g[N<<2];
int dfn[N<<2],low[N<<2],bel[N<<2];
int dfncnt=0,cnt=0;
stack <int> s;
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
    if (dfn[u]==low[u]) {
        cnt++;
        while (1) {
            int v=s.top();
            s.pop();
            bel[v]=cnt;
            if (v==u) break;
        }
    }
}
//i->i; ~i->i+n; pre[i]->i+2n; ~pre[i]->i+3n
/*
~u->v
~v->u
i->pre[i]
~pre[i]->~i
i->~pre[i-1]
pre[i-1]->~i
pre[i-1]->pre[i]
~pre[i]->~pre[i-1]
*/
signed main() {
    Cios;
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        g[u+n].push_back(v);
        g[v+n].push_back(u);
    }
    for (int i=1;i<=k;i++) {
        int w;
        cin>>w;
        int pre=-1,p;
        for (int j=1;j<=w;j++) {
            cin>>p;
            g[p].push_back(p+2*n);
            g[p+3*n].push_back(p+n);
            if (j!=1) {
                g[p].push_back(pre+3*n);
                g[pre+2*n].push_back(p+n);
                g[pre+2*n].push_back(p+2*n);
                g[p+3*n].push_back(pre+3*n);
            }
            pre=p;
        }
    }
    for (int i=1;i<=n*4;i++) {
        if (!dfn[i]) Tarjan (i);
    }
    for (int i=1;i<=n;i++) {
        if (bel[i]==bel[i+n]) {
            cout<<"NIE\n";
            return 0;
        }
    }
    cout<<"TAK\n";
    return 0;
}