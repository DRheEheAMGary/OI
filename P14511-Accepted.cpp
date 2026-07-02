/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2005;
int n;
struct point {
    int x,col,id;
    bool operator < (const point p) const {
        return x<p.x;
    }
};
vector <point> p;
int tmp[N];
pair <int,int> res[N];
signed main() {
    Cios;
    int T;
    cin>>T;
    while (T--) {
        cin>>n;
        p.clear();
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n+1;j++) {
                int x,y;
                cin>>x>>y;
                p.push_back({x,i,j});
            }
        }
        sort(p.begin(),p.end());
        for (auto [x,col,id]:p) {
            if (!tmp[col]) tmp[col]=id;
            else if (res[col].first==0&&res[col].second==0){
                res[col]={tmp[col],id};
                for (int i=1;i<=n;i++) tmp[i]=0;
            }
        }
        for (int i=1;i<=n;i++) cout<<res[i].first<<" "<<res[i].second<<"\n";
        for (int i=1;i<=n;i++) tmp[i]=0,res[i]={0,0};
    }
    return 0;
}