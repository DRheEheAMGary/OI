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
map<int,bool> mp;
int n,a[N];
signed main() { 
    Cios;
    // freopen("slime.in","r",stdin);
    // freopen("slime.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    if (n==1) {
        cout<<"1\n";
        return 0;
    }
    int res=0;
    for (int i=1;i<=n;i++) {
        if (mp[a[i]]) continue;
        if (i-2>=1) if (a[i-2]==a[i]) {res++,mp[a[i]]=1;continue;}
        if (i-1>=1) if (a[i-1]==a[i]) {res++,mp[a[i]]=1;continue;}
        if (i+1<=n) if (a[i+1]==a[i]) {res++,mp[a[i]]=1;continue;}
        if (i+2<=n) if (a[i+2]==a[i]) {res++,mp[a[i]]=1;continue;}
    }
    cout<<res<<"\n";
    return 0;
}

/*
g++ -g slime.cpp -o slime.exe -std=c++14 -O2 -static; echo "finish"; .\slime.exe
cd $work/ZhengRui/Competition/noip20/5/slime/ && g++ slime.cpp -o slime -std=c++14 -O2 && echo "finish" && ./slime
*/