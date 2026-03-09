/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e5+10,B=1000;
class TreelinkBlock {
    int n,num,size=B;
    int _a[N],a[N],pos[N];
    int bl[B],br[B];
    int dep[N],sz[N],fa[N],hv[N],top[N],dfn[N];
    int dfncnt=0;
    vector <int> g[N];
    bitset <N> cnt[N/B+5][N/B+5];
    void dfs1 (int u) {
        sz[u]=1;
        dep[u]=(fa[u]==0?1:(dep[u]+1));
        hv[u]=0;
        for (int v:g[u]) {
            if (v==fa[u]) continue;
            fa[u]=v;
            dfs1(v);
            sz[u]+=sz[v];
            if (sz[v]>sz[hv[u]]) hv[u]=v;
        }
    }
    void dfs2 (int u,int root) {
        top[u]=root;
        dfn[u]=++dfncnt;
        if (hv[u]) dfs2(hv[u],root);
        for (int v:g[u]) {
            if (v==fa[u]||v==hv[u]) continue;
            dfs2(v,v);
        }
    }
    bitset<N> query_link (int l,int r) {
        l=dfn[l];
        r=dfn[r];
        int pl=pos[l],pr=pos[r];
        bitset<N> ans;
        if (pl==pr||pl+1==pr) {
            for (int i=l;i<=r;i++) ans.set(a[i]);
        }
        else {
            ans=cnt[pl+1][pr-1];
            for (int i=l;i<=br[pl];i++) ans.set(a[i]);
            for (int i=bl[pr];i<=r;i++) ans.set(a[i]);
        }
        return ans;
    }
    public:
    pair<int,int> Init () {
        int m,f;
        cin>>n>>m>>f;
        for (int i=1;i<=n;i++) cin>>_a[i];
        for (int i=1;i<n;i++) {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs1(1);
        dfs2(1,0);
        for (int i=1;i<=n;i++) a[dfn[i]]=_a[i];
        for (int i=1;i<=n;i++) pos[i]=(i-1)/size+1;
        for (int i=1;i<=num;i++) {
            bl[i]=(i-1)*size+1;
            br[i]=min(n,i*size);
        }
        for (int i=1;i<=num;i++) {
            for (int j=i;j<=num;j++) {
                cnt[i][j]=cnt[i][j-1];
                for (int k=bl[j];k<=br[j];k++) cnt[i][j].set(a[k]);
            }
        }
        return make_pair(m,f);
    }
    int query (int l,int r) {
        bitset<N> res;
        while (top[l]!=top[r]) {
            if (dep[top[l]]<dep[top[r]]) swap(l,r);
            res|=query_link(l,top[l]);
            l=fa[top[l]];
        }
        if (dep[l]>dep[r]) swap(l,r);
        res|=query_link(l,r);
        return res._Find_first()-1;
    }
}bl;
signed main(){
    pair<int,int> _p=bl.Init();
    int m=_p.first,f=_p.second;
    int lst=0;
    while (m--) {
        int l,r;
        cin>>l>>r;
        if (f) {
            l^=lst;
            r^=lst;
        }
        lst=bl.query(l,r);
        cout<<lst<<"\n";
    }
    return 0;
}