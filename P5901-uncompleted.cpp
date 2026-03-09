/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e5+10,B=450;
class Block {
    int n,r,lim;
    vector <int> g[N];
    vector <int> hv;
    vector <int> cl[N];
    int fa[N],col[N],dfn[N],pos[N],sz[N];
    int dfncnt=0;
    int tmp[N];
    int up[N/B+5][N],down[N/B+5][N];
    void dfs (int u) {
        dfn[u]=++dfncnt;
        sz[u]=1;
        for (int v:g[u]) {
            if (v==fa[u]) continue;
            dfs(v);
            sz[u]+=sz[v];
        }
    }
    public:
    void resize (int _n) {
        n=_n;
        lim=sqrt(n);
    }
    void setColorSize (int _r) {
        r=_r;
    }
    void setRoot (int idx,int _r) {
        fa[idx]=0;
        col[idx]=_r;
    }
    void addPoint (int idx,int _fa,int _col) {
        fa[idx]=_fa;
        g[_fa].push_back(idx);
        col[idx]=_col;
    }
    void init () {
        dfs(1);
        memset (tmp,0,sizeof tmp);
        memset (pos,-1,sizeof pos);
    }
};
signed main(){
    return 0;
}