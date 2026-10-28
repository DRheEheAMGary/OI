/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1005,M=20,inf=1<<30;
int n,m,a[N][M];
int pre[N][M],nxt[N][M];
int dis[N][M];
int fa[N][M];
int res[N][N];
inline int find (int u,int stt) {
    if (!u||dis[u][stt]==inf) return u;
    return fa[u][stt]=find(fa[u][stt],stt);
}
struct qnode {int u,stt;};
signed main() {
    // freopen("path.in","r",stdin);
    // freopen("path.out","w",stdout);
    Cios;
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) cin>>a[i][j];
    }
    for (int stt=0;stt<(1<<m);stt++) {
        map<vector<int>,vector<int>> mp;
        for (int i=1;i<=n;i++) {
            vector <int> sg;
            for (int j=0;j<m;j++) {
                if (stt&(1<<j)) sg.push_back(a[i][j+1]);
            }
            mp[sg].push_back(i);
        }
        for (auto &[_idx,vt]:mp) {
            if (vt.size()==1) pre[vt[0]][stt]=nxt[vt[0]][stt]=vt[0];
            else {
                int sz=vt.size();
                for (int i=0;i<sz;i++) {
                    pre[vt[i]][stt]=vt[(i-1+sz)%sz];
                    nxt[vt[i]][stt]=vt[(i+1)%sz];
                }
            }
        }
    }
    for (int t=1;t<=n;t++) {
        for (int i=1;i<=n;i++) {
            for (int j=0;j<(1<<m);j++) dis[i][j]=inf,fa[i][j]=i;
        }
        queue<qnode> q;
        auto qpush=[&] (int u,int stt,int d) {
            int p=find(pre[u][stt],stt);
            dis[u][stt]=d;
            fa[u][stt]=(p==u?0:p);
            q.push({u,stt});
        };
        for (int j=0;j<(1<<m);j++) qpush(t,j,0);
        while (q.size()) {
            auto [u,stt]=q.front();
            q.pop();
            int d=dis[u][stt];
            int preu=pre[u][stt],nxtu=nxt[u][stt];
            if (dis[preu][stt]>d+1) qpush(preu,stt,d+1);
            if (dis[nxtu][stt]>d+1) qpush(nxtu,stt,d+1);
            for (int c=0;c<m;c++) {
                if (!(stt&(1<<c))) {
                    int nstt=stt|(1<<c);
                    if (dis[u][nstt]>d+1) qpush(u,nstt,d+1);
                }
            }
            for (int c=0;c<m;c++) {
                if (stt&(1<<c)) {
                    int nstt=stt^(1<<c);
                    int lu=pre[u][stt];
                    int lim=(u-lu+n)%n;
                    if (lim==0) lim=n;
                    int cur=find(u,nstt);
                    while (cur) {
                        int cdis=(u-cur+n)%n;
                        if (cdis>=lim) break;
                        qpush(cur,nstt,d+1);
                        cur=find(cur,nstt);
                    }
                }
            }
        }
        for (int i=1;i<=n;i++) res[i][t]=dis[i][0];
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) cout<<res[i][j]<<" \n"[j==n];
    }
    return 0;
}

/*
g++ -g path.cpp -o path.exe -std=c++14 -O2 -static; echo "finish"; .\path.exe; rm path.exe
cd $work && g++ path.cpp -o path -std=c++14 -O2 && echo "finish" && ./path && rm path
*/