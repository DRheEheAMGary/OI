/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1005;
map <int,int> mp;
int n,m,p[N];
signed main() {
    Cios;
    cin>>n>>m;
    int cnt=0,cnt2=0;
    for (int i=1;i<=n;i++) {
        int a;
        cin>>a;
        mp[a]=i;
    }
    memset(p,-1,sizeof p);
    for (int i=1;i<=m;i++) {
        int c,s;
        cin>>c>>s;
        if (!(~p[mp[c]])) cnt++;
        if (p[mp[c]]!=-1&&p[mp[c]]<60) cnt2--;
        p[mp[c]]=s;
        if (s<60) cnt2++;
    }
    cout<<n-cnt<<" "<<cnt2;
    return 0;
}