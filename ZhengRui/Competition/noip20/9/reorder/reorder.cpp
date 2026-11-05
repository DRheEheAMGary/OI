/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e5+10;
int n,q,a[N];
map <int,int> cnt;
multiset <int> cts;
signed main() {
    Cios;
    // freopen("reorder.in","r",stdin);
    // freopen("reorder.out","w",stdout);
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>a[i],cnt[a[i]]++;
    for (auto [a,ct]:cnt) cts.insert(ct);
    cout<<n-*cts.rbegin()<<"\n";
    while (q--) {
        int p,x;
        cin>>p>>x;
        cts.erase(cts.find(cnt[a[p]]));
        cts.insert(--cnt[a[p]]);
        auto it=cts.find(cnt[x]);
        if (it!=cts.end()) cts.erase(it);
        cts.insert(++cnt[x]);
        a[p]=x;
        cout<<n-*cts.rbegin()<<"\n";
    }
    return 0;
}

/*
g++ -g reorder.cpp -o reorder.exe -std=c++14 -O2 -static; echo "finish"; .\reorder.exe; rm reorder.exe
cd $work && g++ reorder.cpp -o reorder -std=c++14 -O2 && echo "finish" && ./reorder && rm reorder
*/