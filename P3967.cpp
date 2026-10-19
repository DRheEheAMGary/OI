/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=100,inf=(1ll<<62);
int n,w[N][N],lx[N],ly[N],sl[N],mch[N],pre[N];
bool vy[N];
vector <pair<int,int>> eds;
void bfs (int k) {
    int u,v=0,_v=0,dta;
    mch[v]=k;
    memset(pre,0,sizeof pre);
    for (int i=1;i<=n;i++) sl[i]=inf;
    while (1) {
        u=mch[v];
        dta=inf;
        vy[v]=1;
        for (int i=1;i<=n;i++) {
            if (vy[i]) continue;
            int d=lx[u]+ly[i]-w[u][i];
            if (sl[i]>d) {
                sl[i]=d;
                pre[i]=v;
            }
            if (sl[i]<dta) {
                dta=sl[i];
                _v=i;
            }
        }
        lx[k]-=dta;
        for (int i=1;i<=n;i++) {
            if (vy[i]) {
                lx[mch[i]]-=dta;
                ly[i]+=dta;
            }
            else sl[i]-=dta;
        }
        v=_v;
        if (mch[v]==0) break;
    }
    while (v) {
        mch[v]=mch[pre[v]];
        v=pre[v];
    }
}
int km () {
    memset(mch,0,sizeof mch);
    memset(lx,0,sizeof lx);
    memset(ly,0,sizeof ly);
    for (int i=1;i<=n;i++) {
        lx[i]=-inf;
        for (int j=1;j<=n;j++) lx[i]=max(lx[i],w[i][j]);
    }
    for (int i=1;i<=n;i++) {
        memset(vy,0,sizeof vy);
        bfs(i);
    }
    int res=0;
    for (int i=1;i<=n;i++) {
        if (mch[i]) res+=w[mch[i]][i];
    }
    return res;
}
signed main() {
    Cios;
    cin>>n;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) cin>>w[i][j];
    }
    int k=km();
    for (int i=1;i<=n;i++) {
        if (mch[i]) eds.push_back({mch[i],i});
    }
    vector <pair<int,int>> ress;
    for (auto [u,v]:eds) {
        int _w=w[u][v];
        w[u][v]=-inf;
        int _k=km();
        w[u][v]=_w;
        if (_k!=k) ress.push_back({u,v}); 
    }
    cout<<k<<"\n";
    sort(ress.begin(),ress.end());
    for (auto [u,v]:ress) cout<<u<<" "<<v<<"\n";
    return 0;
}