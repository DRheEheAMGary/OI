/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
#include <clocale>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e5+10;
#ifdef CLANGD_
#define N 100
#endif
int n,m,p[N];
set <pair<int,int>> pt;
vector <int> ib[N];
signed main() {
    Cios;
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
        int a,b;
        cin>>a>>b;
        p[a]++;
        ib[a].push_back(b);
    }
    for (int i=1;i<=n;i++) pt.insert({p[i],-i});
    for (int i=1;i<=n;i++) {
        pt.erase({p[i],-i});
        for (int b:ib[i]) {
            pt.erase({p[b],-b});
            p[b]++;
            pt.insert({p[b],-b});
        }
        cout<<-(pt.rbegin()->second)<<"\n";
        for (int b:ib[i]) {
            pt.erase({p[b],-b});
            p[b]--;
            pt.insert({p[b],-b});
        }
        pt.insert({p[i],-i});
    }
    return 0;
}

/*
g++ -g mainc.cpp -o mainc.exe -std=c++14 -O2 -static; echo "finish"; .\mainc.exe; rm mainc.exe
cd $work && g++  mainc.cpp -o mainc -std=c++14 -O2 && echo "finish" && ./mainc && rm mainc
*/