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
int n,k;
struct Star {
    int x,y;
    bool operator == (const Star& p) {return x==p.x&&y==p.y;}
    bool operator < (const Star& p) const {
        if (x!=p.x) return x<p.x;
        return y<p.y;
    }
};
map<Star,intl> star;
signed main() {
    Cios;
    int T;
    cin>>T;
    while (T--) {
        star.clear();
        cin>>n>>k;
        intl res=0;
        for (int i=1;i<=n;i++) {
            int x,y,d;
            cin>>x>>y>>d;
            star[{x,y}]=d;
            res=max(res,max(d+star[{x,y-1}],d+star[{x,y+1}])*k);
        }
        cout<<res<<"\n";
    }
    
    return 0;
}