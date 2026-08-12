/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define szof sizeof
intc N=1e6+10;
string s;
int n,m=127,sa[N],rk[N<<1],prk[N<<1],id[N],cnt[N];
signed main() {
    Cios;
    cin>>s;
    n=s.size();
    s="&"+s;
    for (int i=1;i<=n;i++) cnt[rk[i]=s[i]]++;
    for (int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
    for (int i=n;i>=1;i--) sa[cnt[rk[i]]--]=i;
    memcpy(prk+1,rk+1,n*szof(int));
    for (int p=0,i=1;i<=n;i++) {
        if (prk[sa[i]]==prk[sa[i-1]]) rk[sa[i]]=p;
        else rk[sa[i]]=++p;
    }
    for (int w=1;w<n;w<<=1,m=n) {
        memset(cnt,0,szof cnt);
        memcpy(id+1,sa+1,n*szof(int));
        for (int i=1;i<=n;i++) cnt[rk[id[i]+w]]++;
        for (int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
        for (int i=n;i>=1;i--) sa[cnt[rk[id[i]+w]]--]=id[i];
        memset(cnt,0,szof cnt);
        memcpy(id+1,sa+1,n*szof(int));
        for (int i=1;i<=n;i++) cnt[rk[id[i]]]++;
        for (int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
        for (int i=n;i>=1;i--) sa[cnt[rk[id[i]]]--]=id[i];
        memcpy(prk+1,rk+1,n*szof(int));
        for (int p=0,i=1;i<=n;i++) {
            if (prk[sa[i]]==prk[sa[i-1]]&&prk[sa[i]+w]==prk[sa[i-1]+w]) rk[sa[i]]=p;
            else rk[sa[i]]=++p;
        }
    }
    for (int i=1;i<=n;i++) cout<<sa[i]<<" \n"[i==n];
    return 0;
}