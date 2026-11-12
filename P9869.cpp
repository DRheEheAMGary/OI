/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e5+10;
intc T=1e5+1,F=-1e5-1,U=0;
int n,m;
int fa[N];
bool vis[N*3];
int find (int x) {
    if (x==T||x==F) return x;
    else if (x==U||vis[n-x]) return U;
    else if (vis[n+x]) return T;
    else if (x<0) {
        if (x==-fa[-x]) return x;
        else {
            vis[x+n]=1;
            int _tmp=find(-fa[-x]);
            vis[x+n]=0;
            return _tmp;
        }
    }
    else {
        if (x==fa[x]) return x;
        else {
            vis[x+n]=1;
            int _tmp=fa[x]=find(fa[x]);
            vis[x+n]=0;
            return _tmp;
        }
    }
}
signed main() {
    Cios;
    int C,_T;
    cin>>C>>_T;
    while (_T--) {
        cin>>n>>m;
        for (int i=1;i<=n;i++) fa[i]=i;
        for (int i=1;i<=m;i++) {
            char op;
            int u,v;
            cin>>op>>u;
            if (op=='T') fa[u]=T;
            else if (op=='F') fa[u]=F;
            else if (op=='U') fa[u]=U;
            else {
                cin>>v;
                if (op=='+') fa[u]=fa[v];
                else fa[u]=-fa[v];
            }
        }
        int res=0;
        for (int i=1;i<=n;i++) res+=(find(i)==U);
        cout<<res<<"\n";
    }
    return 0;
}

/*
g++ -g P9869.cpp -o P9869.exe -std=c++14 -O2 -static; echo "finish"; .\P9869.exe; rm P9869.exe
cd $work && g++  P9869.cpp -o P9869 -std=c++14 -O2 && echo "finish" && ./P9869 && rm P9869
*/