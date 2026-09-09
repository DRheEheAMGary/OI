/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#ifdef DEBUG
#define dbg cout<<"hanser"<<endl;
#else
#define dbg 
#endif
intc dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int n,m,res=0;
char c[21][10];
vector <pair<int,int>> s;
int idx=0,bel[21][10];
bool alv[150];
inline bool check (int x,int y) {
    if (x>n||y>m||x<1||y<1) return 0;
    if (bel[x][y]) return 0;
    return 1;
}
void dfs (int x,int y,int id) {
    bel[x][y]=id;
    for (int i=0;i<4;i++) {
        int vx=x+dx[i],vy=y+dy[i];
        if (!check(vx,vy)) continue;
        if (c[vx][vy]==' ') alv[id]=1;
        else if (c[vx][vy]==c[x][y]) dfs(vx,vy,id);
    }
}
void dfs_static (int i) {
    if (i==s.size()) {
        memset(bel,0,sizeof bel);
        memset(alv,0,sizeof alv);
        idx=0;
        bool ress=1;
        for (int j=1;j<=n;j++) {
            for (int k=1;k<=m;k++) {
                if (c[j][k]==' ') continue;
                if (!bel[j][k]) {
                    dfs(j,k,++idx);
                    if (!alv[idx]) {
                        ress=0;
                        break;
                    }
                }
            }
            if (!ress) break;
        }
        res+=ress;
        return;
    }
    int x=s[i].first,y=s[i].second;
    c[x][y]=' ';dfs_static(i+1);
    c[x][y]='B';dfs_static(i+1);
    c[x][y]='W';dfs_static(i+1);
}
signed main() {
    Cios;
    freopen ("chess.in","r",stdin);
    freopen ("chess.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin>>c[i][j];
            if (c[i][j]=='?') s.push_back({i,j});
            if (c[i][j]=='.') c[i][j]=' ';
        }
    }
    dfs_static(0);
    cout<<res<<"\n";
    return 0;
}

/*
g++ -g chess.cpp -o chess.exe -O2 -std=c++14 -static -DDEBUG; .\chess.exe

*/