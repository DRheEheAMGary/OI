/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e4+10;
int n;
int d[N];
vector <int> g[N];
int mch[N];
bool vis[N];
bool dfs (int u) {
    for (int v:g[u]) {
        if (vis[v]) continue;
        vis[v]=1;
        if (!mch[v]||dfs(mch[v])) {
            mch[v]=u;
            mch[u]=v;
            return 1;
        }
    }
    return 0;
}
signed main() {
    Cios;
    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>d[i];
        if (i+d[i]<n) g[i].push_back(d[i]+i+n);
        if (i-d[i]>=0) g[i].push_back(i-d[i]+n);
        if (i+n-d[i]<n) g[i].push_back(i+n-d[i]+n);
        if (i-n+d[i]>=0) g[i].push_back(i+d[i]);
        if (g[i].size()!=0) sort(g[i].begin(),g[i].end()); 
    }
    int res=0;
    for (int i=n-1;i>=0;i--) {
        memset(vis,0,sizeof vis);
        res+=dfs(i);
    }
    if (res!=n) {
        cout<<"No Answer";
        return 0;
    }
    for (int i=0;i<n;i++) cout<<mch[i]-n<<" \n"[i==n-1];
    return 0;
}