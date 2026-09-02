/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int n;
inline int Query (int a,int b) {
    cout<<"? "<<a<<" "<<b<<endl;
    int res;
    cin>>res;
    return res;
}
inline void Answer (int x,int y) {
    cout<<"! "<<x<<" "<<y<<endl;
    int res;
    cin>>res;
}
signed main() {
    Cios;
    int T;
    cin>>T;
    while (T--) {
        cin>>n;
        if (n==2) {
            Answer(1,2);
            continue;
        }
        int a=1,b=2,c=3,nw=3;
        while (nw<=n) {
            int ans1=Query(a,b),ans2=Query(a,c);
            if (ans1==ans2) a=++nw;
            else if (ans1<ans2)  b=++nw;
            else c=++nw;
        }
        if (a==n+1) Answer(b,c);
        else if (b==n+1) Answer(a,c);
        else if (c==n+1) Answer(a,b );
    }
    return 0;
}