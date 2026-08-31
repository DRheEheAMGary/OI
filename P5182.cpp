/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=105,N2=10005;
bool bl[N][N];
int n,t;
vector <int> g[N2];
int get_id (int x,int y) {return (x-1)*n+y;}
void addedge (int x1,int y1,int x2,int y2) {
    int id1=get_id(x1,y1);
    int id2=get_id(x2,y2);
    g[id1].push_back(id2);
}
bool vis[N2];
int mch[N2];
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
    cin>>n>>t;
    for (int i=1;i<=t;i++) {
        int x,y;
        cin>>x>>y;
        bl[x][y]=1;
    }
    for (int x=1;x<=n;x++) {
        for (int y=1;y<=n;y++) {
            if (bl[x][y]) continue;
            if (x-1>=1&&!bl[x-1][y]) addedge(x,y,x-1,y);
            if (x+1<=n&&!bl[x+1][y]) addedge(x,y,x+1,y);
            if (y-1>=1&&!bl[x][y-1]) addedge(x,y,x,y-1);
            if (y+1<=n&&!bl[x][y+1]) addedge(x,y,x,y+1);
        }
    }
    int res=0;
    for (int i=1;i<=n*n;i++) {
        memset(vis,0,sizeof vis);
        if (dfs(i)) res++;
    }
    cout<<res/2<<"\n";
    return 0;
}