/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e5+10,R=2.5e4+10,B=550;
class Sqrt {
    typedef pair<int,int> pii;
    int n,r,lim=500;
    vector <int> g[N];
    vector <int> cl[R];
    int fa[N],col[N],dfn[N],pos[N],sz[N];
    int dfncnt=0,clcnt=0;
    int tmp[N];
    int up[B][R],down[B][R];
    vector <pii> res[R];
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
        // lim=sqrt(n);
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
        memset (pos,-1,sizeof pos);
        for (int i=1;i<=n;i++) {
            cl[col[i]].push_back(i);
        }
        for (int i=1;i<=r;i++) {
            if (cl[i].size()>=lim) {
                pos[i]=++clcnt;
                memset(tmp,0,sizeof tmp);
                for (int u:cl[i]) {
                    tmp[dfn[u]]++;
                    tmp[dfn[u]+sz[u]]--;
                }
                for (int j=1;j<=n;j++) tmp[j]+=tmp[j-1];
                for (int j=1;j<=r;j++) {
                    for (int u:cl[j]) down[pos[i]][j]+=tmp[dfn[u]];
                }
                memset(tmp,0,sizeof tmp);
                for (int u:cl[i]) tmp[dfn[u]]++;
                for (int j=1;j<=n;j++) tmp[j]+=tmp[j-1];
                for (int j=1;j<=r;j++) {
                    for (int u:cl[j]) up[pos[i]][j]+=(tmp[dfn[u]+sz[u]-1]-tmp[dfn[u]-1]);
                }
            }
            else {
                for (int u:cl[i]) {
                    res[i].push_back({dfn[u],1});
                    res[i].push_back({dfn[u]+sz[u],-1});
                }
                sort(res[i].begin(),res[i].end(),[&] (pii a,pii b) {
                    return a.first<b.first;
                });
                sort(cl[i].begin(),cl[i].end(),[&](int a,int b) {
                    return dfn[a]<dfn[b];
                });
            }
        }
    }
    int query (int r1,int r2) {
        int ans=0;
        if (pos[r1]!=-1) {
            ans=down[pos[r1]][r2];
        }
        else if (pos[r2]!=-1) {
            ans=up[pos[r2]][r1];
        }
        else {
            int pr1=0,pr2=0;
            int cnt=0;
            while (pr2<cl[r2].size()) {
                int _nw=cl[r2][pr2];
                while (pr1<res[r1].size()&&res[r1][pr1].first<=dfn[_nw]) {
                    cnt+=res[r1][pr1].second;
                    pr1++;
                }
                ans+=cnt;
                pr2++;
            }
        }
        return ans;
    }
}sq;
int n,r,q;
signed main(){
    Cios;
    cin>>n>>r>>q;
    sq.resize(n);
    sq.setColorSize(r);
    for (int i=1;i<=n;i++) {
        int fa,col;
        if (i==1) {
            cin>>col;
            sq.setRoot(1,col);
        }
        else {
            cin>>fa>>col;
            sq.addPoint(i,fa,col);
        }
    }
    sq.init();
    while (q--) {
        int r1,r2;
        cin>>r1>>r2;
        cout<<sq.query(r1,r2)<<endl;
    }
    return 0;
}