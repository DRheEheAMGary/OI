/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int n;
string s;
signed main() {
    Cios;
    freopen("repeat.in","r",stdin);
    freopen("repeat.out","w",stdout);
    cin>>n;
    cin>>s;
    s="&"+s;
    int diff=0;
    for (int i=1;i<=n;i++) diff+=(s[i]!=s[i+n]);
    int res=0;
    for (int i=1;i<=n;i++) {
        res+=(s[i]!=s[i+n]);
        if (s[i]==s[i+n]) break;
    }
    if (res==diff) return cout<<res,0;
    for (int i=n;i>=1;i--) {
        res+=(s[i]!=s[i+n]);
        if (s[i]==s[i+n]) break;
    }
    if (res==diff) cout<<res;
    else cout<<-1<<"\n";
    return 0;
}

/*
g++ -g repeat.cpp -o repeat.exe -std=c++14 -O2 -static; echo "finish"; .\repeat.exe
*/