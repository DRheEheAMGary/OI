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
struct edge {
    int to,w;
};
vector <edge> ng[N];
int cnt,dfncnt=0,fa[N],low[N],dfn[N],dep[N],tot[N],sum[N];
int ndis[N],res=-1,resi=0;
void Tarjan (int u) {
    dfn[u]=low[u]=++dfncnt;
    for (int v:g[u]) {
        if (v==fa[u]) continue;
        if (!dfn[v]) {
            fa[v]=u;
            dep[v]=dep[u]+1;
            Tarjan (v);
            low[u]=min(low[u],low[v]);
            if (low[v]>dfn[u]) {
                ng[u].push_back({v,1});
                ng[v].push_back({u,1});
            }
        }
        else {
            low[u]=min(low[u],dfn[v]);
            if (dfn[v]>dfn[u]) {
                cnt++;
                tot[cnt]=dep[v]-dep[u]+1;
                int cur=u;
                while (cur!=v) {
                    sum[cur]=dep[cur]-dep[v];
                    int mind=min(sum[cur],tot[cnt]-sum[cur]);
                    ng[cur].push_back({cnt,mind});
                    ng[cnt].push_back({cur,mind});
                    cur=fa[cur];
                }
                ng[v].push_back({cnt,0});
                ng[cnt].push_back({v,0});
            }
        }
    }
}

signed main() {
    Cios;
    return 0;
}