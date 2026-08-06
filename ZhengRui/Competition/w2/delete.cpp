/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define szof sizeof
intc N=5e5+10;
constexpr double inf=1e20;
int n,k,a[N];
// double dp[N][N];
double cost (int i,int j) {return abs(a[i]-a[j])*1.0/(i-j);}
// struct node {
//     double val;
//     int idx;
//     bool operator < (const node &p) const {return val>p.val;}
// };
void dfs (int u,int ced,int lst,double nw,double &res) {
    if (u==n+1) {
        if (ced>=n-k) res=min(res,nw);
        return;
    }
    if (lst==0) dfs(u+1,ced+1,u,0,res);
    else dfs(u+1,ced+1,u,max(cost(u,lst),nw),res);
    dfs(u+1,ced,lst,nw,res);
}
signed main() {
    Cios;
    // freopen ("test/delete/ex_delete3.in","r",stdin);
    // freopen ("ans.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    if (n<=18) {
        double res=inf;
        dfs(0,0,0,0,res);
        cout<<fixed<<setprecision(9)<<res<<"\n";
    }
    else {
        double res=0;
        for (int i=1;i<n;i++) res=max(res,cost(i,i-1));
        cout<<fixed<<setprecision(9)<<res<<"\n";
    }
    // for (int i=1;i<=k;i++) {
    //     for (int j=1;j<=n;j++) dp[i][j]=inf;
    // }
    // dp[0][0]=0;
    // for (int i=1;i<=n;i++) {
    //     for (int j=0;j<=min(i,k);j++) {
    //         priority_queue <node> pq;
    //         pq.push({dp[j-1][j-1],j-1});
    //         for (int k=j;k<=i;k++) {
    //             node t=pq.top();
    //             dp[j][k]=min(dp[j][k],max(t.val,cost(k,t.idx)));
    //             pq.push({dp[j-1][k],k});
    //         }
    //     }
    // }
    // double res=inf;
    // for (int i=k;i<=n;i++) res=min(res,dp[k][i]);
    // cout<<fixed<<setprecision(9)<<res<<"\n";
    return 0;
}

/*
clang++ -g delete.cpp -o delete -std=c++14 -O2 -Wall
*/