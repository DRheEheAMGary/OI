/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int n,res=-1;
string s,t;
int mp[15][15];
int mpto[15];
bool used[15];
void dfs (int nw) {
    if (nw==10) {
        int tmp=0;
        for (int i=0;i<=9;i++) tmp+=mp[i][mpto[i]];
        res=max(res,tmp);
        return;
    }
    for (int i=0;i<=9;i++) {
        if (used[i]) continue;
        used[i]=1;
        mpto[nw]=i;
        dfs(nw+1);
        used[i]=0;
    }
}
signed main() {
    Cios;
    int T;
    cin>>T;
    while (T--) {
        cin>>n;
        cin>>s;
        cin>>t;
        for (int i=0;i<n;i++) mp[s[i]-'0'][t[i]-'0']++;
        dfs(0);
        memset(mp,0,sizeof mp);
        cout<<res<<"\n";
        res=-1;
    }
    return 0;
}