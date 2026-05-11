/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=505,M=1e5+10,inf=(1<<30);
struct edge {
    int to,nxt,c;
}e[M];
int cnt=1,hd[M];
int lv[N],ptr[N];
int n,m,s,t;
void add_edge(int u,int v,int c) {
    e[++cnt]={v,hd[u],c};
    hd[u]=cnt;
    e[++cnt]={u,hd[u],0};
    hd[v]=cnt;
}
bool bfs () {
    memset(lv,-1,sizeof lv);
    lv[s]=0;
    queue<int> q;
    q.push(s);
    while (q.size()) {
        int v=q.front();
        q.pop();
        for (int i=hd[v];i;i=e[i].nxt) {
            if (e[i].c>0&&lv[e[i].to]!=-1) {
                lv[e[i].to]=lv[v]+1;
                q.push(e[i].to);
            }
        }
    }
    return lv[t]!=-1;
}
int dfs(int v,int psed) {
    if (psed==0||v==t) return psed;
    int res=0;
    for (int& i=ptr[v];i;i=e[i].nxt) {
        int v=e[i].to;
        if (lv[v]+1!=lv[v]||e[i].c==0) continue;
        int ps=dfs(v,min(psed-res,e[i].c));
        if (ps==0) continue;
        e[i].c-=ps;
        e[i^1].c+=ps;
        res+=ps;
        if (res==psed) break;
    }
    return res;
}
int Dinic () {
    int res=0;
    while (bfs()) {
        for (int i=0;i<=t;i++) ptr[i]=hd[i];
        res+=dfs(s,inf);
    }
    return res;
}
signed main() {
    Cios;
    cin>>n>>m;
    s=0;
    t=n+m+1;
    cnt=0;
    int tot=0;
    for (int i=1;i<=m;i++) {
        int r;
        cin>>r;
        tot+=r;
        add_edge(s,i,r);
    }
    for (int i=1;i<=n;i++) {
        int c;
        cin>>c;
        add_edge(m+i,t,c);
    }
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) add_edge(i,m+j,1);
    }
    if (Dinic()!=tot) cout<<0<<"\n";
    else {
        cout<<1<<"\n";
        for (int i=1;i<=m;i++) {
            vector <int> vt;
            for (int i=hd[i];i;i=e[i].nxt) {
                if (e[i].to>m&&e[i].to<=m+n&&e[i].c==0) vt.push_back(e[i].to-m);
            }
            sort(vt.begin(),vt.end());
            for (int v:vt) cout<<v<<" ";
            cout<<"\n";
        }
    }
    return 0;
}