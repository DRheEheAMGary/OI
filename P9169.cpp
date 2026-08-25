/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=12,_N=2e6+10;
intc dx[]={0,-1,0,0,1},dy[]={0,0,1,-1,0};
int n,m;
int id[N][N][N][N][N][N][2];//black:(1,2) | red1:(3,4) | red2:(5,6) | now:0(red)/1(black)
int ididx=1;
int st;
bool vis[_N],h[_N];
int f[_N],in[_N];
char cmap[N][N];
// vector <int> g[_N];
int hd[_N];
struct edge {
    int to,nxt;
}e[_N*7];
int eidx=0;
inline void addedge (int u,int v) {e[++eidx]={v,hd[u]},hd[u]=eidx;}
inline bool check (int i,int j,int x,int y,int p,int q) {
    if (i>n||x>n||p>n) return 0;
    if (j>m||y>m||q>m) return 0;
    if (i<1||x<1||p<1) return 0;
    if (j<1||y<1||q<1) return 0;
    if (cmap[i][j]=='#'||cmap[x][y]=='#'||cmap[p][q]=='#') return 0;
    if (x==p&&y==q) return 0;
    return 1;
}
inline void bfs () {
    queue<int> q;
    for (int i=2;i<=ididx;i++) {
        if (vis[i]) q.push(i);
    }
    while (q.size()) {
        int u=q.front();
        q.pop();
        if (u==st) return;
        for (int i=hd[u],v=e[i].to;i;i=e[i].nxt,v=e[i].to) {
            if (vis[v]) continue;
            in[v]--;
            if (h[u]==0) {
                f[v]=f[u]+1;
                h[v]=1;
                vis[v]=1;
                q.push(v);
            } 
            else if (in[v]==0) {
                f[v]=f[u]+1;
                h[v]=0;
                vis[v]=1;
                q.push(v);
            }
        }
    }
}
signed main() {
    Cios;
    int _id,T;
    cin>>_id>>T;
    while (T--) {
        cin>>n>>m;
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) cin>>cmap[i][j];
        }
        int bx=0,by=0,rx1=0,rx2=0,ry1=0,ry2=0;
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                if (cmap[i][j]=='X') bx=i,by=j;
                else if (cmap[i][j]=='O'&&!rx1) rx1=i,ry1=j;
                else if (cmap[i][j]=='O') rx2=i,ry2=j;
            }
        }
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                for (int x=1;x<=n;x++) {
                    for (int y=1;y<=m;y++) {
                        for (int p=1;p<=n;p++) {
                            for (int q=1;q<=m;q++) {
                                if (check(i,j,x,y,p,q)) id[i][j][x][y][p][q][0]=++ididx,id[i][j][x][y][p][q][1]=++ididx;
                            }
                        }
                    }
                }
            }
        }
        st=id[bx][by][rx1][ry1][rx2][ry2][0];
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                for (int x=1;x<=n;x++) {
                    for (int y=1;y<=m;y++) {
                        for (int p=1;p<=n;p++) {
                            for (int q=1;q<=m;q++) {
                                if (!check(i,j,x,y,p,q)) continue;
                                int nw=id[i][j][x][y][p][q][0];
                                for (int d=1;d<=4;d++) {
                                    if (check(i,j,x+dx[d],y+dy[d],p,q)) {
                                        addedge(id[i][j][x+dx[d]][y+dy[d]][p][q][1],nw);
                                        in[nw]++;
                                    }
                                    if (check(i,j,x,y,p+dx[d],q+dy[d])) {
                                        addedge(id[i][j][x][y][p+dx[d]][q+dy[d]][1],nw);
                                        in[nw]++;
                                    }
                                }
                                for (int d=1;d<=3;d++) {
                                    if (check(i+dx[d],j+dy[d],x,y,p,q)) {
                                        addedge(id[i+dx[d]][j+dy[d]][x][y][p][q][0],nw^1);
                                        in[nw^1]++;
                                    }
                                }
                                if (i==1) {
                                    h[nw]=0;
                                    h[nw^1]=1;
                                    vis[nw]=vis[nw^1]=1;
                                    f[nw]=f[nw^1]=0;
                                }
                                else if ((i==x&&j==y)||(i==p&&j==q)) {
                                    h[nw]=h[nw^1]=0;
                                    vis[nw]=vis[nw^1]=1;
                                    f[nw]=f[nw^1]=0;
                                }
                                if (!in[nw]) {
                                    h[nw]=0;
                                    vis[nw]=1;
                                    f[nw]=0;
                                }
                                if (!in[nw^1]) {
                                    h[nw^1]=0;
                                    vis[nw^1]=1;
                                    f[nw^1]=0;
                                }
                            }
                        }
                    }
                }
            }
        }
        bfs();
        if (!vis[st]) cout<<"Tie\n";
        else if (h[st]) cout<<"Red "<<f[st]<<"\n";
        else cout<<"Black "<<f[st]<<"\n";
        for (int i=2;i<=ididx;i++) {
            vis[i]=f[i]=h[i]=in[i]=hd[i]=0;
        }
        ididx=1,eidx=0;
    }
    return 0;
}