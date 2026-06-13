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
struct event {
    int type,t,idx;
};
vector <event> e;
int n,d;
signed main() {
    Cios;
    cin>>n>>d;
    for (int i=1;i<=n;i++) {
        int s,t;
        cin>>s>>t;
        if (t-s>=d) {
            e.push_back({1,s,i});
            e.push_back({-1,t-d+1,i}); 
        }
    }
    sort (e.begin(),e.end(),[&] (event a,event b) {
        if (a.t==b.t) return a.type>b.type;
        return a.t<b.t;
    });
    intl res=0,nowt=1,nowp=0;
    int nwi=0;
    while (nwi<e.size()) {
        while (nwi<e.size()&&nowt==e[nwi].t) {
            event nwe=e[nwi];
            nowp+=nwe.type;
            nwi++;
        }
        res+=nowp*(nowp-1)/2;
        nowt++;
    }
    cout<<res<<"\n";
    return 0;
}