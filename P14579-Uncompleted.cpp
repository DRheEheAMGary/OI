/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e3+10,M=5e5+10,inf=0x3f3f3f3f;
int n,m,s,t,ns,nt;
struct edge {
    int to,c,fl,dwn,nxt;
}e[M];
int hd[N],cnt=1;
int lv[N],cur[N];
bool bfs (int _s,int _t) {
    queue<int> q;
    memset(lv,-1,sizeof lv);
    q.push(_s);
    cur[_s]=hd[_s];
    lv[_s]=1;
    while (q.size()) {
        int u=q.front();
        q.pop();
        for (int i=hd[u];~i;i=e[i].nxt) {
            auto [v,c,fl,dwn,nxt]=e[i];
            if (c-fl>0&&lv[v]==-1) {
                q.push(v);
                lv[v]=lv[u]+1;
                cur[v]=hd[v];
            }
        }
    }
    return lv[t]!=-1;
}
signed main() {
    Cios;
    return 0;
}