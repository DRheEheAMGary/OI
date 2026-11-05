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
intl n,z;
struct item {
    intl d,a,idx;
};
vector <item> uph,dnh;
signed main() {
    Cios;
    cin>>n>>z;
    for (int i=1;i<=n;i++) {
        int d,a;
        cin>>d>>a;
        if (d>a) dnh.push_back({d,a,i});
        else uph.push_back({d,a,i});
    }
    sort(uph.begin(),uph.end(),[] (const item &a,const item &b) {return a.d<b.d;});
    sort(dnh.begin(),dnh.end(),[] (const item &a,const item &b) {return a.a>b.a;});
    vector <int> res;
    for (auto [d,a,id]:uph) {
        if (z-d<=0) return cout<<"NIE\n",0;
        z=z-d+a;
        res.push_back(id);
    }
    for (auto [d,a,id]:dnh) {
        if (z-d<=0) return cout<<"NIE\n",0;
        z=z-d+a;
        res.push_back(id);
    } 
    cout<<"TAK\n";
    for (auto r:res) cout<<r<<" "; 
    return 0;
}

/*
g++ -g mainc.cpp -o mainc.exe -std=c++14 -O2 -static; echo "finish"; .\mainc.exe; rm mainc.exe
cd $work && g++  mainc.cpp -o mainc -std=c++14 -O2 && echo "finish" && ./mainc && rm mainc
*/