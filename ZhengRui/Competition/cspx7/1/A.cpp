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
int n;
string s;
struct Point  {
    int x,y;
    Point operator + (Point _p) const {return {x+_p.x,y+_p.y};}
    bool operator < (Point _p) const {
        if (x!=_p.x) return x<_p.x;
        return y<_p.y;
    }
};
struct Vec {
    Point p;
    int d;
    Vec () =default;
    Vec (Point _p,int _d):p(_p),d(_d) {}
    Vec (int _x,int _y,int _d):p({_x,_y}),d(_d) {}
}a[N],p[N],q[N];
inline Point Rot (Point a,int d) {
    d%=4;
    if (d==0) return a;
    if (d==1) return {a.y,-a.x};
    if (d==2) return {-a.x,-a.y};
    return {-a.y,a.x};
}
inline Vec Merge (Vec a,Vec b) {
    return {a.p+Rot(b.p,a.d),(a.d+b.d)%4};
}
set <Point> st;
signed main() {
    Cios;
    cin>>n;
    cin>>s;
    s="~"+s;
    for (int i=1;i<=n;i++) {
        if (s[i]=='F') a[i]={0,1,0};
        if (s[i]=='L') a[i]={0,0,3};
        if (s[i]=='R') a[i]={0,0,1};
    }
    for (int i=1;i<=n;i++) p[i]=Merge(p[i-1],a[i]);
    for (int i=n;i>=1;i--) q[i]=Merge(a[i],q[i+1]);
    for (int i=1;i<=n;i++) st.insert(Merge(q[i],p[i-1]).p);
    cout<<st.size()<<"\n";
    return 0;
}