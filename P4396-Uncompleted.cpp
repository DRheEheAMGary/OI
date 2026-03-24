/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e5+10;
int n,m;
struct ques {
    int l,r,a,b,idx,res;
    ques () =default;
    ques (int l_,int r_,int a_,int b_,int idx_,int res_=0) :l(l_),r(r_),a(a_),b(b_),idx(idx_) {}
}q[N];
struct Fenwick {
    int tr[N];
    inline int lb (int p) {return p&(-p);}
    inline void Update (int p,int w) {
        while (p<N) {
            tr[p]+=w;
            p+=lb(p);
        }
    }
    inline int Query (int p) {
        int res=0;
        while (p) {
            res+=tr[p];
            p-=lb(p);
        }
        return res;
    }
    inline int QueryInterval (int l,int r) {
        return Query(r)-Query(l-1);
    }
}bit;
struct FenwickCount {
    int tr[N];
    int cnt[N];
    inline int lb (int p) {return p&(-p);}
    inline void _update (int p,int w) {
        while (p<N) {
            tr[p]+=w;
            p+=lb(p);
        }
    }
    inline int _query (int p) {
        int res=0;
        while (p) {
            res+=tr[p];
            p-=lb(p);
        }
        return res;
    }
    inline void UpdateAdd (int p) {
        cnt[p]++;
        if (cnt[p]==1) _update(p,1);
    }
    inline void UpdateDel (int p) {
        if (cnt[p]==1) _update(p,-1);
        cnt[p]--;
    }
    inline int Query (int l,int r) {
        return _query(r)-_query(l-1);
    }
}bitc;
struct answ {
    void add (int p) {
        
    }
}res;
signed main() {
    Cios;
    return 0;
}