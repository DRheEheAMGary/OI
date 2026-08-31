/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=100,N2=1e4+10;
int n,m,res;
int mp[N][N];
int wcnt=0,hcnt=0;
vector <int> g[N2];
int mch[N2];
bool vis[N2];
int bkh[N2],bkw[N2];
struct belong {
    int w,h;
}bel[N][N];
bool dfs (int u) {
    for (int v:g[u]) {
        if (vis[v]) continue;
        vis[v]=1;
        if (!mch[v]||dfs(mch[v])) {
            mch[v]=u;
            return 1;
        }
    }
    return 0;
}
signed main() {
    Cios;
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) cin>>mp[i][j];
    }
    for (int i=1;i<=n;i++) {
        bool nw=0;
        for (int j=1;j<=m;j++) {
            if (!nw&&mp[i][j]!=2) {
                nw=1;
                wcnt++;
                bkw[wcnt]=i;
            }
            if (mp[i][j]==0) bel[i][j].w=wcnt;
            else if (mp[i][j]==1) bel[i][j].w=0;
            else nw=0;
        }
    }
    for (int j=1;j<=m;j++) {
        bool nw=0;
        for (int i=1;i<=n;i++) {
            if (!nw&&mp[i][j]!=2) {
                nw=1;
                hcnt++;
                bkh[hcnt]=j;
            }
            if (mp[i][j]==0) bel[i][j].h=hcnt;
            else if (mp[i][j]==1) bel[i][j].h=0;
            else nw=0;
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (!bel[i][j].w||!bel[i][j].h) continue;
            g[bel[i][j].w].push_back(bel[i][j].h);
        }
    }
    for (int i=1;i<=wcnt;i++) {
        memset(vis,0,sizeof vis);
        res+=dfs(i);
    }
    cout<<res<<"\n";
    for (int i=1;i<=hcnt;i++) {
        if (mch[i]) cout<<bkw[mch[i]]<<" "<<bkh[i]<<"\n";
    }
    return 0;
}