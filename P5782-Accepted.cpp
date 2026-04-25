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
inline int otr (int x) {return (x%2==0)?(x-1):(x+1);}
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
signed main() {
    Cios;
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
        int a,b;
        cin>>a>>b;
        g[a].push_back(otr(b));
        g[b].push_back(otr(a));
    }
    for (int i=1;i<=2*n;i++) {
        if (!dfn[i]) Tarjan(i);
    }
    for (int i=1;i<=2*n;i++) {
        if (i%2==1&&bel[i]==bel[i+1]) {
            cout<<"NIE\n";
            return 0;
        }
    }
    for (int i=1;i<=2*n;i++) {
        if (bel[i]<bel[otr(i)]) cout<<i<<"\n";
    }
    return 0;
}