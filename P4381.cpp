/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e6+10;
int n,deg[N],outto[N],outw[N];
intl dp[N],mxd[N],res=0;
struct edge {
    int to,w;
};
int a[N*2];
intl sum[N*2];
vector <edge> g[N];
queue <int> q;
signed main() {
    Cios;
    cin>>n;
    for (int i=1;i<=n;i++) {
        int u,l;
        cin>>u>>l;
        g[u].push_back({i,l});
        g[i].push_back({u,l});
        deg[u]++;
        deg[i]++;
        outto[i]=u;
        outw[i]=l;
    }
    for (int i=1;i<=n;i++) {
        if (deg[i]==1) q.push(i);
    }
    while (q.size()) {
        int u=q.front();
        q.pop();
        for (auto [v,w]:g[u]) {
            if (deg[v]>1) {
                mxd[v]=max({mxd[u],mxd[v],dp[v]+dp[u]+w});
                dp[v]=max(dp[v],dp[u]+w);
                if (--deg[v]==1) q.push(v);
            }
        }
    }
    for (int i=1;i<=n;i++) {
        if (deg[i]<=1) continue;
        vector <int> cir;
        int cur=i;
        while (deg[cur]>1) {
            cir.push_back(cur);
            deg[cur]=0;
            cur=outto[cur];
        }
        int m=cir.size();
        intl mxont=0,mxnot=0;
        for (int j=0;j<m;j++) {
            a[j+1]=a[j+1+m]=cir[j];
            mxnot=max(mxnot,mxd[cir[j]]);
        }
        sum[1]=0;
        for (int j=1;j<=2*m;j++) sum[j]=sum[j-1]+outw[a[j-1]];
        deque<int> dq;
        for (int j=1;j<=2*m;j++) {
            while (dq.size()&&j-dq.front()>=m) dq.pop_front();
            if (dq.size()) mxont=max(mxont,dp[a[j]]+dp[a[dq.front()]]+sum[j]-sum[dq.front()]);
            while (dq.size()&&dp[a[j]]-sum[j]>=dp[a[dq.back()]]-sum[dq.back()]) dq.pop_back();
            dq.push_back(j);
        }
        res+=max(mxont,mxnot);
    }
    cout<<res<<"\n";
    return 0;
}