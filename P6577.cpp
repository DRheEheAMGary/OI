/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=505,inf=(1ll<<60);
int n,m,w[N][N],lx[N],ly[N],sl[N],mch[N],pre[N];
bool vy[N];
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
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) w[i][j]=-inf;
    }
    for (int i=1;i<=m;i++) {
        int u,v,c;
        cin>>u>>v>>c;
        w[u][v]=c;
    }
    cout<<km()<<"\n";
    for (int i=1;i<=n;i++) cout<<mch[i]<<" \n"[i==n];
    return 0;
}