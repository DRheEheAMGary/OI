/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1000,M=10005;
int n,m;
struct edge {
    int u,v;
}e[M];
int cir[N],idx[N];
vector <int> g[N];
vector <edge> eds;
int dfn[N],low[N],bel[N],dfncnt,cnt;
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
            if (u==v) continue;
        }
    }
}
signed main() {
    Cios;
    int T;
    cin>>T;
    while (T--) {
        cin>>n>>m;
        for (int i=1;i<=m;i++) {
            int u,v;
            e[i]={u,v};
        }
        for (int i=1;i<=n;i++) cin>>cir[i],idx[cir[i]]=i;
        if (m>3*n-6) {
            cout<<"NO\n";
            continue;
        }
        for (int i=1;i<=m;i++) {
            int u=e[i].u,v=e[i].v;
            if (cir[idx[u]+1]!=v&&cir[idx[v]+1]!=u) eds.push_back({u,v});
        }
        for (int i=0;i<eds.size();i++) {
            for (int j=i+1;j<eds.size();j++) {
                auto [u1,v1]=eds[i];
                auto [u2,v2]=eds[j];
                if (u1>v1) swap(u1,v1);
                if (u2>v2) swap(u2,v2);
                if ((u1<u2&&u2<v1&&v1<v2)||(u1>u2&&u2>v1&&v1>v2)) {
                    g[i].push_back(j+m);
                    g[j].push_back(i+m);
                    g[i+m].push_back(j);
                    g[j+m].push_back(i);
                }
            }
        }
        for (int i=1;i<=m;i++) {
            if (!dfn[i]) Tarjan(i);
        }
        bool can_be_solved=1;
        for (int i=1;i<=m;i++) can_be_solved&=(bel[i]!=bel[i+m]);
        cout<<(can_be_solved?"YES\n":"NO\n");
        eds.clear();
        for (int i=1;i<=m;i++) {
            dfn[i]=low[i]=bel[i]=0;
            g[i].clear();
        }
        dfncnt=0;
        cnt=0;
    }
    return 0;
}