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
char mp[N][N];
int wcnt=0,hcnt=0;
vector <int> g[N2];
int mch[N2];
bool vis[N2];
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
    int T;
    cin>>T;
    int _=1;
    while (T--) {
        cout<<"Case :"<<_++<<"\n";
        cin>>n>>m;
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) cin>>mp[i][j];
        }
        for (int i=1;i<=n;i++) {
            bool nw=0;
            for (int j=1;j<=m;j++) {
                if (!nw&&mp[i][j]!='#') {
                    nw=1;
                    wcnt++;
                }
                if (mp[i][j]=='o') bel[i][j].w=wcnt;
                else if (mp[i][j]=='*') bel[i][j].w=0;
                else nw=0;
            }
        }
        for (int j=1;j<=m;j++) {
            bool nw=0;
            for (int i=1;i<=n;i++) {
                if (!nw&&mp[i][j]!='#') {
                    nw=1;
                    hcnt++;
                }
                if (mp[i][j]=='o') bel[i][j].h=hcnt;
                else if (mp[i][j]=='*') bel[i][j].h=0;
                else nw=0;
            }
        }
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                if (!bel[i][j].w||!bel[i][j].h) continue;
                g[bel[i][j].w].push_back(wcnt+bel[i][j].h);
            }
        }
        for (int i=1;i<=wcnt;i++) {
            memset(vis,0,sizeof vis);
            res+=dfs(i);
        }
        cout<<res<<"\n";
        memset(mch,0,sizeof mch);
        wcnt=0;
        hcnt=0;
        for (int i=1;i<N2;i++) g[i].clear();
        memset(bel,0,sizeof bel);
    }
    return 0;
}