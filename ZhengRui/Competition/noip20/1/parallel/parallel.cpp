/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
// #define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef unsigned long long uintl;
typedef long long intl;
intc N=5e5+10;
mt19937_64 rnd (time(0));
int n,q,k;
uintl getid (int id,int u) {return (uintl)id*n+u;}
uintl a[N],c[N],hsv[N];
unordered_map <uintl,int> cnt;
intl res=0;
class DisjointSetUnion {
    struct node {;
        int fa,nxt,sz;
    };
    unordered_map <uintl,node> nw;
    public:
    inline node& getp (int id,int u) {
        uintl iid=getid(id,u);
        auto it=nw.find(iid);
        if (it==nw.end()) return nw[iid]=node{u,u,1};
        return it->second;
    }
    inline int find (int id,int u) {
        node& cur=getp(id,u);
        if (cur.fa==u) return u;
        return cur.fa=find(id,cur.fa);
    }
}dsu;
inline uintl getw (int id,int u) {return c[id]*a[u];}
void InitValue () {
    for (int i=1;i<=n;i++) a[i]=rnd();
    for (int i=1;i<=k;i++) c[i]=rnd()|1ull;
    uintl base=0;
    for (int i=1;i<=k;i++) base+=c[i];
    for (int i=1;i<=n;i++) hsv[i]=base*a[i],cnt[hsv[i]]++;
}
signed main() {
    Cios;
    // freopen("parallel.in","r",stdin);
    // freopen("parallel.out","w",stdout);
    cin>>n>>k>>q;
    InitValue();
    while (q--) {
        int id,u,v;
        cin>>id>>u>>v;
        int fu=dsu.find(id,u),fv=dsu.find(id,v);
        if (fu==fv) {
            cout<<res<<"\n";
            continue;
        }
        if (dsu.getp(id,fu).sz<dsu.getp(id,fv).sz) swap(fu,fv);
        auto &pu=dsu.getp(id,fu),&pv=dsu.getp(id,fv);
        uintl dta=getw(id,fu)-getw(id,fv);
        int cur=fv;
        while (1) {
            res-=cnt[hsv[cur]]-1;
            if (--cnt[hsv[cur]]==0) cnt.erase(hsv[cur]);
            hsv[cur]+=dta;
            res+=cnt[hsv[cur]]++;
            cur=dsu.getp(id,cur).nxt;
            if (cur==fv) break;
        }
        int nu=pu.nxt,nv=pv.nxt;
        pu.nxt=nv,pv.nxt=nu;
        pu.sz+=pv.sz;
        pv.fa=fu;
        cout<<res<<"\n";
    }
    return 0;
}

/*
g++ -g parallel.cpp -o parallel -std=c++14 -O2; echo "finish"; ./parallel
*/