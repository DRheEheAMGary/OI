/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=505,M=5e5+10;
#ifdef CLANGD_
#define M 10
#endif
constexpr intl inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
intl w[M],k[N];
struct station {
    int a;
    intl t;
};
vector <station> sub[M];
intl dis[N][N];
signed main() {
    Cios;
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++) cin>>w[i];
    for (int i=1;i<=n;i++) {
        cin>>k[i];
        for (int j=1;j<=k[i];j++) {
            int _a;
            intl _t;
            cin>>_a>>_t;
            sub[_a].push_back({i,_t});
        }
    }
    memset(dis,0x3f,sizeof dis);
    for (int i=1;i<=n;i++) dis[i][i]=0;
    for (int i=1;i<=m;i++) {
        for (int j1=0;j1<sub[i].size();j1++) {
            for (int j2=j1+1;j2<sub[i].size();j2++) {
                dis[sub[i][j1].a][sub[i][j2].a]=min(dis[sub[i][j1].a][sub[i][j2].a],sub[i][j1].t+sub[i][j2].t);
                dis[sub[i][j2].a][sub[i][j1].a]=min(dis[sub[i][j2].a][sub[i][j1].a],sub[i][j1].t+sub[i][j2].t);
            }
        }
    }
    for (int k=1;k<=n;k++) {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
        }
    }
    while (q--) {
        int x,y;
        cin>>x>>y;
        intl res=0x3f3f3f3f3f3f3f3f;
        for (auto [ax,tx]:sub[x]) {
            for (auto [ay,ty]:sub[y]) res=min(res,tx+ty+dis[ax][ay]);
        }
        cout<<res+w[x]+w[y]<<"\n";
    }
    return 0;
}

/*
g++ -g mainc.cpp -o mainc.exe -std=c++14 -O2 -static; echo "finish"; .\mainc.exe; rm mainc.exe
cd $work && g++  mainc.cpp -o mainc -std=c++14 -O2 && echo "finish" && ./mainc && rm mainc
*/