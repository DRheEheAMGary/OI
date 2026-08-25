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
int n,m;
string s,t;
int fa[N],sz[N];
vector <int> bel[N];
int cnt1[30],cnt2[30];
int find (int x) {
    if (x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}
void merge (int u,int v) {
    u=find(u),v=find(v);
    if (sz[u]>sz[v]) swap(u,v);
    fa[u]=v;
    sz[v]+=sz[u];
}
signed main() {
    Cios;
    cin>>n>>m;
    cin>>s>>t;
    for (int i=1;i<=n;i++) fa[i]=i;
    for (int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        merge(u,v);
    }
    for (int i=1;i<=n;i++) bel[find(i)].push_back(i);
    for (int i=1;i<=n;i++) {
        if (bel[i].empty()) continue;
        memset(cnt1,0,sizeof cnt1);
        memset(cnt2,0,sizeof cnt2);
        for (int u:bel[i]) cnt1[s[u-1]-'a']++,cnt2[t[u-1]-'a']++;
        for (int j=0;j<26;j++) {
            if (cnt1[j]!=cnt2[j]) {
                cout<<"No\n";
                return 0;
            }
        }
    }
    cout<<"Yes\n";
    return 0;
}