/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#ifdef CLANGD_
intc N=10;
#else
intc N=1e5+10;
#endif
int n,k,ty,a[N];
struct edge {
    int to,nxt;
}e[N],ne[N];
int hd[N],nhd[N],ecnt=0;
void addedge(int u,int v) {
    ecnt++;
    e[ecnt]={v,hd[u]},hd[u]=ecnt;
    ne[ecnt]={u,nhd[v]},nhd[v]=ecnt;
}
bool vis[N];
void dfs (int u,int rt,int &st,int &ed) {
    vis[u]=1;
    for (int i=nhd[u],v=ne[i].nxt;~i;i=ne[i].nxt,v=ne[i].to) {
        if (v==rt) {
            st=v;
            ed=u;
            return;
        }
        if (!vis[v]) dfs(v,rt,st,ed);
    }
}
void getSize (int u,int st,int &size) {
    size++;
    for (int i=hd[u],v=e[i].nxt;~i;i=e[i].nxt,v=e[i].to) {
        if (v==st) continue;
        getSize(v,st,size);
    }
}
struct Distance {
    int id,nxt;
}dis[N];
int dd[N],dcnt=0;
void clearDis (int sz) {
    for (int i=0;i<=sz;i++) dd[i]=-1;
    dcnt=0;
}
void pushDis (int d,int idx) {
    dis[++dcnt]={idx,dd[d]},dd[d]=dcnt;
}
void dfsDis (int u,int st,int di) {
    pushDis(di,u);
    for (int i=nhd[u],v=ne[i].nxt;~i;i=ne[i].nxt,v=ne[i].to) {
        if (v==st) continue;
        dfsDis(v,st,di+1);
    }
}
int cnt[N];
bool onr[N];
int tod[N],sumd[N];
void findR (int u,int &size) {
    cnt[u]++;
    if (cnt[u]==2) onr[u]=1,size++;
    if (cnt[u]==3) return;
    for (int i=hd[u],v=e[i].nxt;~i;i=e[i].nxt,v=e[i].to) findR(v,size);
}
struct Result {
    int sum,id;
};
vector <Result> res;
signed main() {
    Cios;
    cin>>n>>k>>ty;
    if (k<n) {
        
        return 0;
    }
    memset(hd,-1,sizeof hd);
    memset(nhd,-1,sizeof nhd);
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
        int s;
        cin>>s;
        addedge(i,s);
    }
    for (int i=1;i<=n;i++) {
        if (!vis[i]) {
            int st=0,ed=0;
            dfs(i,i,st,ed);
            if (!st) continue;
            int sz=0;
            getSize(st,st,sz);
            clearDis(sz);
            dfsDis(st,st,0);
            int rsz=0;
            findR(st,rsz);
            for (int i=0;i<rsz;i++) {
                sumd[i]=0;
                tod[i]=0;
                for (int j=dd[i],id=dis[i].id;~j;j=dis[i].nxt,id=dis[i].id) {
                    if (onr[id]) tod[i]=id;
                    sumd[i]+=a[id];
                }
            }
            for (int i=rsz;i<sz;i++) {
                if (~dd[i]) break;
                for (int j=dd[i],id=dis[i].id;~j;j=dis[i].nxt,id=dis[i].id) {
                    sumd[i%rsz]+=a[id];
                }
            }
            for (int i=0;i<rsz;i++) res.push_back({sumd[i],tod[i]});
        }
    }
    int maxv=-1;
    for (auto [sum,id]:res) maxv=max(maxv,sum);
    cout<<maxv<<"\n";
    if (ty==1) for (auto [sum,id]:res) {
        if (sum==maxv) cout<<id<<" ";
    }
    return 0;
}