/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
#include <queue>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define szof sizeof
intc N=1e5+10;
int n,m,q;
vector <int> g[N];
int dis1[N],dis2[N];
struct node {
    int u,l;
    bool operator < (const node &p) const {return (u==p.u?(l>p.l):(u>p.u));}
};
void bfs () {
    priority_queue<node> pq;
    memset(dis1,0x3f,szof dis1);
    memset(dis2,0x3f,szof dis2);
    dis2[1]=0;
    for (int v:g[1]) {
        pq.push({v,1});
        dis1[v]=1;
    }
    while (pq.size()) {
        auto [u,l]=pq.top();
        pq.pop();
        for (int v:g[u]) {
            if ((l+1)%2==1) {
                if (dis1[v]>l+1) {
                    dis1[v]=l+1;
                    pq.push({v,l+1});
                }
            }
            else {
                if (dis2[v]>l+1) {
                    dis2[v]=l+1;
                    pq.push({v,l+1});
                }
            }
        }
    }
}
signed main() {
    Cios;
    cin>>n>>m>>q;
    for (int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs();
    for (int i=1;i<=q;i++) {
        int a,l;
        cin>>a>>l;
        if (l%2==1) {
            if (dis1[a]<=l) cout<<"Yes\n";
            else cout<<"No\n";
        }
        else {
            if (dis2[a]<=l) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
    return 0;
}