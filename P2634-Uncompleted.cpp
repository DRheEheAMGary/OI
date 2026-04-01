/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e4+10;
struct edge {
    int to,w;
};
int n,rt,rs,res;
int vis[N],cnt[4],sum[4],siz[N];
vector <edge> g[N];
int gcd (int a,int b) {return b?gcd(b,a%b):a;}
void getroot (int u,int f) {
    
}
int getres (int u) {
    
}
void solve (int u) {
    vis[u]=1;
    res+=getres(u);
    for (edge v:g[u]) {
        if (vis[v.to]) continue;
         rs=siz[v.to];
         getroot(v.to,u);
         solve(rt);
    }
}
signed main() {
    Cios;
    return 0;
}