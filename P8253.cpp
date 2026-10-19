/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e5+10;
class Fenwick {
    int tr[N*2];
    inline int lb (int x) {return x&(-x);}
public:
    void update (int x) {
        while (x<2*N) {
            tr[x]++;
            x+=lb(x);
        }
    }
    int query (int x) {
        int res=0;
        while (x) {
            res+=tr[x];
            x-=lb(x);
        }   
        return res;
    }
    void clear () {memset(tr,0,sizeof tr);}
}bit;
int n,m,a[5][N];
struct hanser {
    int a,b,op,val;
    bool operator < (const hanser &p) const  {
        if (a!=p.a) return a<p.a;
        return op<p.op;
    }
};
vector <hanser> hr;
signed main() {
    Cios;
    cin>>m>>n;
    int res=0;
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) cin>>a[i][j];
    }
    for (int i=m+1;i<=4;i++) {
        for (int j=1;j<=n;j++) a[i][j]=a[i-m][j];
    }
    for (int i=1;i<=4;i++) {
        for (int j=1;j<=n;j++) res+=a[i][j]*2*n;
    }
    for (int x=1;x<=4;x++) {
        for (int y=1;y<=4;y++) {
            if (y==x) continue;
            for (int z=1;z<=4;z++) {
                if (z==x||z==y) continue;
                // cout<<x<<" "<<y<<" "<<z<<"\n";
                bit.clear();
                hr.clear();
                for (int i=1;i<=n;i++) {
                    hr.push_back({a[x][i]-a[y][i]+(x>y),a[y][i]-a[z][i]+(y>z),0,0});
                    hr.push_back({a[y][i]-a[x][i],a[z][i]-a[y][i],1,a[y][i]});
                }
                sort(hr.begin(),hr.end());
                for (auto [u,v,op,val]:hr) {
                    if (op==0) bit.update(v+N);
                    else res-=bit.query(v+N)*val;
                }
            }
        }
    }
    cout<<res<<"\n";
    return 0;
}