/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e6+10;
int n,b[N];
bool pd[N];
vector <pair <int,int>> p;
void push_back (int a,int b) {
    p.push_back({min(a,b),max(a,b)});
}
signed main() {
    Cios;
    freopen("pair.in","r",stdin);
    freopen("pair.out","w",stdout);
    cin>>n;
    int nwi=1;
    for (int i=1;i<n;i++) {
        cin>>b[i];
        while (pd[nwi]) nwi++;
        push_back(b[i],nwi);
        pd[b[i]]=pd[nwi]=1;
    }
    int a,b;
    while (pd[nwi]) nwi++;
    a=nwi;nwi++;
    while (pd[nwi]) nwi++;
    b=nwi;
    push_back(a,b);
    sort(p.begin(),p.end());
    for (int i=0;i<n;i++) cout<<p[i].first<<" "<<p[i].second<<"\n";
    return 0;
}

/*
g++ -g pair.cpp -o pair.exe -std=c++14 -O2 -static; echo "finish"; .\pair.exe
*/