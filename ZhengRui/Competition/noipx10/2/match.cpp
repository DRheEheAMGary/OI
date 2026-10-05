/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e5+10;
struct edge {
    int to,id,nxt;
}e[N];
int n,m,ecnt=0,vis[N],hd[N],vise[N];
void addedge (int u,int v,int id) {
    e[++ecnt]={v,id,hd[u]},hd[u]=ecnt;
    e[++ecnt]={u,id,hd[v]},hd[v]=ecnt;
}
int dfs (int u,int fa) {
    vector <int> unpaired;
    int fai=0;
    vis[u]=1;
    for (int i=hd[u],v=e[i].to,id=e[i].id;~i;i=e[i].nxt,v=e[i].to,id=e[i].id) {
        if (vise[id]) continue;
        if (v==fa) {
            fai=id;
            continue;
        }
        if (vis[v]) {
            unpaired.push_back(id);
            continue;
        }
        else {
            int _res=dfs(v,u);
            if (_res) unpaired.push_back(_res);
        }
    }
    if (unpaired.size()%2==0) {
        for (int i=0;i<unpaired.size();i+=2) cout<<unpaired[i]<<" "<<unpaired[i+1]<<"\n";
        for (int ev:unpaired) vise[ev]=1;
        return fai;
    }
    else {
        for (int i=0;i<unpaired.size()-1;i+=2) cout<<unpaired[i]<<" "<<unpaired[i+1]<<"\n";
        for (int ev:unpaired) vise[ev]=1;
        vise[fai]=1;
        cout<<unpaired.back()<<" "<<fai<<"\n";
        return 0;
    }
}
signed main() {
    Cios;
    freopen ("match.in","r",stdin);
    freopen ("match.out","w",stdout);
    int T;
    cin>>T;
    while (T--) {
        cin>>n>>m;
        memset(hd,-1,sizeof hd);
        memset(vis,0,sizeof vis);
        ecnt=0;
        for (int i=1;i<=m;i++) {
            int u,v;
            cin>>u>>v;
            addedge(u,v,i);
            vise[i]=0;
        }
        dfs(1,0);
        
    }
    return 0;
}

/*
g++ -g match.cpp -o match.exe -O2 -std=c++14 -static ; echo "finish" ; .\match.exe

2
5 4
1 2
1 3
3 4
3 5
6 6
1 2
2 3
3 1
3 4
4 5
4 6

*/